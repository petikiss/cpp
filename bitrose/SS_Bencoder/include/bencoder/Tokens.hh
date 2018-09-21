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

#ifndef TOKENS_HH
#define TOKENS_HH

#include <string>
#include <map>
#include <list>

#include <iostream>
namespace Bencoder
{
namespace Tokens
{

class Bencode
{
public:
   virtual void print() = 0;
};

class Int : public Bencode
{
public:
    void print() {std::cout << mInt;}
//private:
    int mInt;
};

class Str : public Bencode
{
public:
    Str() {}
    Str(std::string str) : mStr(str) {}
    void print() {std::cout << mStr;}
//private:
    std::string mStr;
};

class Dict : public Bencode
{
public:
    void print()
    {
        for( auto i : mDict)
        {
            std::cout << "{";
            i.first->print();
            std::cout << ":";
            i.second->print();
            std::cout << "}";
        }
        std::cout << std::endl;
    }

//private:
    std::map<Str*, Bencode*> mDict;
};

class List : public Bencode
{
public:
    void print() {}
//private:
    std::list<Bencode*> mList;
};


}
}
#endif
