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

#include <utils/StringUtils.hh>

#include <sstream>

int
utils::StringUtils::stringToInt(std::string str)
{
  int result;
  std::stringstream ss;

  ss << str;
  ss >> result;
  return result;
}


std::string
utils::StringUtils::intToString(int a)
{
  std::stringstream ss;
  ss << a;

  return ss.str();
}


// this function can only convert a number to int!
int
utils::StringUtils::charToInt(char ch)
{
  return stringToInt( std::string(1 ,ch) );
}


bool
utils::StringUtils::isDigit(char c)
{
   return ( '0' <= c && c <= '9' );
}
