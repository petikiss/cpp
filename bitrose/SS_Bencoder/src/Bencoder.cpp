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

}


void Bencoder::decode(const std::string& str)
{
  m_logger->log(logger::Logger::FINE, "Bencoder::decode()");

  m_logger->begin(logger::Logger::DEBUG);
  m_logger->prop("str", str);
  m_logger->end("Bencoder::decode()");


}


/*
std::string Bencoder::parseString(const std::string& str, unsigned int& pos)
{
    m_logger->log(logger::Logger::FINE, "Bencoder::parseString()");

    m_logger->begin(logger::Logger::DEBUG);
//    m_logger->prop("pos", pos);
    m_logger->prop("str[pos]", str[pos]);
    m_logger->end("Bencoder::parseString()");

}


int Bencoder::parseInteger(const std::string& str, unsigned int& pos)
{
    m_logger->log(logger::Logger::FINE, "Bencoder::parseInteger()");

    assert( str[pos] == 'i' );

}


void Bencoder::parseNextType(const std::string& str, unsigned int& pos, ListPtr list)
{
    m_logger->log(logger::Logger::FINE, "Bencoder::parseNextType()");

}


std::list<std::string> Bencoder::parseList(const std::string& str, unsigned int& pos)
{
    m_logger->log(logger::Logger::FINE, "Bencoder::ParseList()");

    m_logger->begin(logger::Logger::DEBUG);
    m_logger->prop("str", const_cast<std::string&>(str));
    m_logger->end("Bencoder::ParseList()");

    assert(str[pos] == 'l');


}

*/


} // namespace Bencoder
