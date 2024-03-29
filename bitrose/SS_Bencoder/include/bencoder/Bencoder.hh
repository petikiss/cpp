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

#ifndef SSBENCODER_BENCODER_HPP
#define SSBENCODER_BENCODER_HPP

#include <logger/Logger.hpp>


#include <bencoder/Tokens.hh>


//class istream;


namespace Bencoder
{

class Bencoder
{
  public:
    Bencoder(logger::Logger* logger);
    ~Bencoder();

   Tokens::Bencode* readBencode(std::istream& inp);
   Tokens::Str*     readStr(std::istream& inp);
   Tokens::Dict*    readDict(std::istream& inp);
   Tokens::Int*     readInt(std::istream& inp);
   Tokens::List*    readList(std::istream& inp);


   void readDictElement(Tokens::Dict* dict, std::istream& inp);
   void readListElement(Tokens::List* list, std::istream& inp);

  private:
    logger::Logger* mLogger;


}; // class Bencoder

} // namespace Bencoder

#endif
