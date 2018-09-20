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

#ifndef SSBENCODER_BENCODER_HPP
#define SSBENCODER_BENCODER_HPP

#include <string>
#include <list>
#include <map>

// #include <bencoder/Types.hpp>
#include <logger/Logger.hpp>


// The Augmented BNF syntax[5] for bencoding format is:
//
//    dictionary = "d" 1*(string anytype) "e" ; non-empty dictionary
//    list       = "l" 1*anytype "e"          ; non-empty list
//    integer    = "i" signumber "e"
//    string     = number ":" <number long sequence of any CHAR>
//    anytype    = dictionary / list / integer / string
//    signumber  = "-" number / number
//    number     = 1*DIGIT
//    CHAR       = %x00-FF                    ; any 8-bit character
//    DIGIT      = "0" / "1" / "2" / "3" / "4" /
//                 "5" / "6" / "7" / "8" / "9"


namespace Bencoder
{

class Bencoder
{
  public:
    Bencoder(logger::Logger* logger);
    ~Bencoder();
  private:
    logger::Logger* m_logger;
  private:
    bool isDigit(char ch);
    void decode(const std::string& str);


    //std::string parseString(const std::string& str, unsigned int& pos);
    //int parseInteger(const std::string& str, unsigned int& pos);
    //std::list<std::string> parseList(const std::string& str, unsigned int& pos);


    // void parseNextType(const std::string& str, unsigned int& pos, ListPtr list);
  private:
    // std::list< std::list< AnyType > > m_lists;
    // std::list< std::map<std::string, AnyType> > m_maps;

/*
  public:
    Bencoder(logger::Logger* logger);
    ~Bencoder();
    void decode(std::string);
  private:
    bool isDigit(char ch);
    void parseInteger(std::string& str, std::list<std::string>& list);
    void parseString(std::string& str, std::list<std::string>& list);

    void parseList(std::string& str, std::list<std::list<std::string> > list);
    void parseList(std::string& str, std::list<std::string>& list);
    logger::Logger* m_logger;

    std::list<std::string> m_integers;
    std::list<std::string> m_strings;
    std::list< std::list<std::string> > m_lists; // depends on indendention
*/
}; // class Bencoder

} // namespace Bencoder

#endif


