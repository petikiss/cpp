/*
* BitRose simple torrent client
*
* Copyright (c) 2018 Marton S.
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

#include <bencoder/Bencoder.hh>
#include <utils/StringUtils.hh>

#include <istream>
#include <iostream>
#include <assert.h>

namespace Bencoder
{

Bencoder::Bencoder(logger::Logger* logger) : mLogger(logger)
{
}

Bencoder::~Bencoder()
{
}


Tokens::Bencode*
Bencoder::readBencode(std::istream& inp)
{
    std::cout << "readBencode" << std::endl;

    Tokens::Bencode* bencode = 0;

    // check the next character without removing from the stream
    char ch = inp.peek();
    if (ch == 'd')
    {
        bencode = readDict(inp);
    }
    else if(ch == 'l')
    {
       bencode = readList(inp);
    }
    else if (ch == 'i')
    {
       bencode = readInt(inp);
    }
    else if ( utils::StringUtils::isDigit(ch))
    {
        bencode = readStr(inp);
    }
    else
    {
        assert(ch == 'e');
    }

    return bencode;
}


Tokens::Str*
Bencoder::readStr(std::istream& inp)
{
    std::cout << "Read Str" << std::endl;

    // read string length at first
    std::string length = "";
    char ch = inp.get();

    assert(utils::StringUtils::isDigit(ch) == true);

    while (utils::StringUtils::isDigit(ch))
    {
        length += ch;
        ch = inp.get();
    }

    assert(ch == ':');

    std::string str = "";
    for (int i = 0; i < atoi(length.c_str()); ++i)
    {
        ch = inp.get();
        str += ch;
    }


    return new Tokens::Str(str);
}


Tokens::Dict*
Bencoder::readDict(std::istream& inp)
{
    std::cout << "Read Dict\n";

    assert(inp.get() == 'd'); // beginning of a dictionary

    Tokens::Dict* dict = new Tokens::Dict();
    while (inp.peek() != 'e')
    {
       readDictElement(dict, inp);
    }

    assert(inp.get() == 'e'); // end of a dictionary

    return dict;
}


void
Bencoder::readDictElement(Tokens::Dict* dict, std::istream& inp)
{
   std::cout << "Read dict element";

   Tokens::Str* str = readStr(inp);
   Tokens::Bencode* bencode = readBencode(inp);

   std::cout << "Adding an element to dict: {" << str->get() << "," << "}\n";

   dict->mDict[str] = bencode;
}


Tokens::Bencode*
Bencoder::find(std::string)
{
}



Tokens::Int*
Bencoder::readInt(std::istream& inp)
{
   std::cout << "Read int";

   assert(inp.get() == 'i');

   Tokens::Int* integer = new Tokens::Int();

   char ch = inp.get();
   std::string number = "";
   while (ch != 'e')
   {
      number += ch;
      ch = inp.get();
   }

   integer->mInt =  utils::StringUtils::stringToInt(number);

   return integer;
}


Tokens::List*
Bencoder::readList(std::istream& inp)
{
   std::cout << "Read list";

   assert(inp.get() == 'l'); // beginning of a list

   Tokens::List* list = new Tokens::List();

   while(inp.peek() != 'e')
   {
      readListElement(list, inp);
   }

   assert(inp.get() == 'e'); // end of a list

   return list;
}


void Bencoder::readListElement(Tokens::List* list, std::istream& inp)
{
   std::cout << "Read list element";

   Tokens::Bencode* bencode = readBencode(inp);

   list->mList.push_back(bencode);
}


}
