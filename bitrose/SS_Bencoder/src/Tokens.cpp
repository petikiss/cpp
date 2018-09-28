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

#include <bencoder/Tokens.hh>
#include <iostream>

namespace Bencoder
{
namespace Tokens
{

void Int::print()
{
   std::cout << mInt;
}

Str::Str()
{
}

Str::~Str()
{
}

Str::Str(std::string str) : mStr(str)
{
}

void Str::print()
{
   std::cout << mStr;
}

std::string
Str::get()
{
   return mStr;
}

void Dict::print()
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


Dict::Dict()
{
}

Dict::~Dict()
{
}

int
Int::get()
{
   return mInt;
}


void List::print()
{
   std::cout << "List print";

   for (auto i : mList)
   {
      std::cout << "[";
      std::cout << "]";
   }
   std::cout << std::endl;
}


}
}
