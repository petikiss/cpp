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

#include <bencoder/Bencoder.hpp>


namespace Bencoder
{

Tokens::Bencode*
Bencoder::readBencode(std::ifstream& inp)
{
    std::cout << "readBencode" << std::endl;

    Tokens::Bencode* bencode;

    // check the next character without removing from the stream
    char ch = inp.peek();
    if (ch == 'd')
    {
        bencode = readDict(inp);
    }
    else if(ch == 'l')
    {
        assert("Not implemented LIST" == "0");
    }
    else if (ch == 'i')
    {
        assert("Not implemented INTEGER" == "0");
    }
    else if ( isDigit(ch))
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
Bencoder::readStr(std::ifstream& inp)
{
    std::cout << "Read Str" << std::endl;

    // read string length at first
    std::string length = "";
    char ch = inp.get();
    std::cout << "CH: " << ch << std::endl;
    while (isDigit(ch))
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


    std::cout << "str len: " << length << std::endl;
    std::cout << "str: " << str << std::endl;

    return new Tokens::Str(str);
}


Tokens::Dict*
Bencoder::readDict(std::ifstream& inp)
{
    std::cout << "Read Dict\n";

    // remove 'd' character
    assert(inp.get() == 'd');

    Tokens::Dict* dict = new Tokens::Dict();

    Tokens::Str* str = readStr(inp);
    Tokens::Bencode* bencode = readBencode(inp);

    dict->mDict[str] = bencode;

    return dict;
}


void
Bencoder::createList(Tokens::Bencode* bencode)
{
    // remove 'd' character
//    assert(inp.get() == 'l');

}


}
