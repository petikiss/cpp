/*
* BitRose simple torrent client
*
* Copyright (c) 2012 Marton Siska
*
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 3 of the License, or (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

#include <bencoder/Bencoder.hpp>
#include <utils/StringUtils.hpp>


#include <assert.h>
#include <iostream>

namespace Bencoder
{


Bencoder::Bencoder(logger::Logger* logger)
{
  m_logger = logger;
}


Bencoder::~Bencoder()
{
}


bool Bencoder::isDigit(char ch)
{
  m_logger->log(logger::Logger::FINE, "Bencoder::isDigit()");

  switch (ch)
  {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return true;
    break;
    default:
      return false;
  }
}


void Bencoder::decode(const std::string& str)
{
  m_logger->log(logger::Logger::FINE, "Bencoder::decode()");

  m_logger->begin(logger::Logger::DEBUG);
  m_logger->prop("str", str);
  m_logger->end("Bencoder::decode()");

  for(unsigned int i = 0; i < str.size(); i++)
  {
      const char ch = str[i];

      switch (ch)
      {
          case 'd':
              break;
          case 'l':
              //parseList(str, i);
              break;
          case 'i':
              //parseInteger();
              break;
      }
  }
}



StringPtr Bencoder::parseString(const std::string& str, unsigned int& pos)
{
    m_logger->log(logger::Logger::FINE, "Bencoder::parseString()");

    m_logger->begin(logger::Logger::DEBUG);
//    m_logger->prop("pos", pos);
    m_logger->prop("str[pos]", str[pos]);
    m_logger->end("Bencoder::parseString()");

    assert( isDigit(str[pos]) );

    int colonLength = 1; // :
    std::string lengthInString = "";
    int lengthEnd = pos;

    while (isDigit(str[lengthEnd]))
    {
        lengthInString += str[lengthEnd];
        ++lengthEnd;
    }
    int stringLength = utils::StringUtils::stringToInt(lengthInString);

    pos = lengthEnd + colonLength + stringLength;

    std::string parsedString = str.substr(lengthEnd+colonLength, stringLength);

    m_logger->begin(logger::Logger::DEBUG);
//    m_logger->prop("stringLength", stringLength);
    m_logger->prop("parsedString", parsedString);
    m_logger->end("Bencoder::parseString()");

    StringPtr stringPtr( new String(parsedString) );
    return stringPtr; // 123:asd
}


IntegerPtr Bencoder::parseInteger(const std::string& str, unsigned int& pos)
{
    m_logger->log(logger::Logger::FINE, "Bencoder::parseInteger()");

    assert( str[pos] == 'i' );

    unsigned int firstLetterLength = 1; // i
    unsigned int endLetterLength = 1;   // e
    std::string integerInString = "";

    unsigned int integerLength = pos + firstLetterLength;

    while (str[integerLength] != 'e')
    {
        integerInString += str[integerLength];
        ++integerLength;
    }

    pos = integerLength + endLetterLength; // pos + firstLetter + length + endLetter
    IntegerPtr intPtr (new Integer(utils::StringUtils::stringToInt(integerInString)) );
    return intPtr;
}


void Bencoder::parseNextType(const std::string& str, unsigned int& pos, ListPtr list)
{
    m_logger->log(logger::Logger::FINE, "Bencoder::parseNextType()");

    switch (str[pos])
    {
        case 'd':
            break;
        case 'l':
        {
            ListPtr l = parseList(str, pos);
            //m_lists.push_back( reinterpret_cast<AnyType>(l) );
            break;
        }
        case 'i':
        {
            list->push_back( parseInteger(str, pos) );
            break;
        }
        default:
            list->push_back( parseString(str, pos) );
            break;
    }
}


ListPtr Bencoder::parseList(const std::string& str, unsigned int& pos)
{
    m_logger->log(logger::Logger::FINE, "Bencoder::ParseList()");

    m_logger->begin(logger::Logger::DEBUG);
    m_logger->prop("str", const_cast<std::string&>(str));
    m_logger->end("Bencoder::ParseList()");

    assert(str[pos] == 'l');

    ListPtr parsedList(new List);

    int firstLetterLength = 1; // l letter
    unsigned int posInString = pos + firstLetterLength;

    while (str[posInString] != 'e')
    {
        parseNextType(str, posInString, parsedList);
    }

    return parsedList;
}





/*
void Bencoder::decode(std::string str)
{
  m_logger->log(logger::Logger::FINE, "Bencoder::decode()");

  m_logger->begin(logger::Logger::DEBUG);
  m_logger->prop("str", str);
  m_logger->end("Bencoder::decode()");

  while(str.size() != 0)
  {
    std::cout << " str.size(): " <<  str.size() << "\n";
    char ch = str[0];
    switch (ch)
    {
      case 'i':
        parseInteger(str, m_integers);
        break;
      case 'd':
        std::cout << "d\n ";
        break;
      case 'l':
        parseList(str, m_lists);
        std::cout << "l\n ";
        break;
      default: // string or error
        if (isDigit(ch))
        {
          parseString(str, m_strings);
        }
        else
        {
          m_logger->log(logger::Logger::WARNING, "Bencoder::decode(): File corrupted!\n");
        }
        std::cout << "default\n ";
        break;
    } // switch
  } // while
  std::cout << "END str.size(): " <<  str.size() << "\n";
}


bool Bencoder::isDigit(char ch)
{
  m_logger->log(logger::Logger::FINE, "Bencoder::isDigit()");

  switch (ch)
  {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return true;
    break;
    default:
      return false;
  }
}

// bool Bencoder::isDictionary(char ch)
// {
//   if (ch == 'd')
//   {
//     return true;
//   }
//   else
//   {
//     return false;
//   }
// }
//
//
// bool Bencoder::isList(char ch)
// {
//   if (ch == 'l')
//   {
//     return true;
//   }
//   else
//   {
//     return false;
//   }
// }
//
//
// bool Bencoder::isInteger(char ch)
// {
//   if (ch == 'i')
//   {
//     return true;
//   }
//   else
//   {
//     return false;
//   }
// }
//
//
// bool Bencoder::isString(char ch)
// {
//   return isDigit();
// }
//
//
// bool Bencoder::endType(char ch)
// {
//   if (ch == 'e')
//   {
//     return true;
//   }
//   else
//   {
//     return false;
//   }
// }
//
//
// void Bencoder::parseDictionary(std::string str)
// {
//
// }
//
//
void Bencoder::parseList(std::string& str, std::list<std::list<std::string> > list)
{
  m_logger->log(logger::Logger::FINE, "Bencoder::parseList(1)");
  char ch = str[0];
  assert(ch == 'l');

  while (ch != 'e')
  {
    m_logger->begin(logger::Logger::DEBUG);
    m_logger->prop("ch", ch);
    m_logger->prop("str", str);
    m_logger->end("Bencoder::parseList(1)");
    std::list<std::string> tmpList;
    parseList(str, tmpList);
    list.push_back(tmpList);
    ch = str[0];
  }
}


void Bencoder::parseList(std::string& str, std::list<std::string>& list)
{
  m_logger->log(logger::Logger::FINE, "Bencoder::parseList(2)");

   // the first characher must be number
  assert(str[0] == 'l');

  // remove 'l' character
  str = str.substr(1);
  char ch = str[0];

  while(ch != 'e')
  {
    switch (ch)
    {
      case 'i':
      {
        m_logger->log(logger::Logger::DEBUG, "Bencoder::parseList(2): integer");
        parseInteger(str, list);
        break;
      }
      case 'd':
      {
        m_logger->log(logger::Logger::DEBUG, "Bencoder::parseList(2): dictionary");
        std::cout << "d\n ";
        break;
      }
      case 'l':
      {
        m_logger->log(logger::Logger::DEBUG, "Bencoder::parseList(2): list");
        std::list<std::list<std::string> > tempList;
        parseList(str, tempList);
        std::cout << "l\n ";
        break;
      }
      default: // string or error
      {
        if (isDigit(ch))
        {
          m_logger->log(logger::Logger::DEBUG, "Bencoder::parseList(2): string");
          parseString(str, list);
        }
        else
        {
          m_logger->log(logger::Logger::WARNING, "Bencoder::parseList(): File corrupted!\n");
        }
        std::cout << "default\n ";
        break;
      } //default
    } // switch
    ch = str[0];
  } // while


}


void Bencoder::parseInteger(std::string& str, std::list<std::string>& list)
{
  m_logger->log(logger::Logger::FINE, "Bencoder::parseInteger()");


  // the first characher must be 'i'
  // TODO: assert
  //assert(str[0] == 'i');

  int length = 1;
  while (str[length] != 'e')
  {
    ++length;
  }

  // leave the 'i' and the 'e' characters
  std::string number = str.substr(1, length-1);
  list.push_back(number);

  //returning with the unparsed peace of str
  str = str.substr(length+1);

  m_logger->begin(logger::Logger::DEBUG);
  m_logger->prop("number", number);
  m_logger->prop("str", str);
  m_logger->end("Bencoder::parseInteger()");
}


void Bencoder::parseString(std::string& str, std::list<std::string>& list)
{
  m_logger->log(logger::Logger::FINE, "Bencoder::parseString()");

  m_logger->begin(logger::Logger::DEBUG);
  m_logger->prop("str", str);
  m_logger->end("Bencoder::parseString()");
  // the first characher must be number
  assert(isDigit(str[0]));

  std::string lengthStr;
  int i = 0;
  while (str[i] != ':')
  {
    lengthStr += str[i];
    i++;
  }

  i++; // jump the ':' character

  int length = utils::StringUtils::stringToInt(lengthStr);

  // store the string
  std::string result = str.substr(i, length);
  list.push_back(result);

  // return value: rest of the string
  str = str.substr(i+length);

  m_logger->begin(logger::Logger::DEBUG);
  m_logger->prop("str", str);
  m_logger->prop("lengthStr", lengthStr); // TODO: integer!
  m_logger->prop("parsed string", result);
  m_logger->end("Bencoder::parseString()");
}
*/



} // namespace Bencoder
