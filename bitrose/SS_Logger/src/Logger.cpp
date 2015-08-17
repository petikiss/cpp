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

#include <logger/Logger.hpp>

#include <iostream>
#include <assert.h>

namespace logger
{

Logger::Logger()
{
}


Logger::~Logger()
{
}


void Logger::log(LogLevel level, std::string message)
{
  std::cout << "Level: " << level << " message: " << message << "\n";
}


void Logger::begin(LogLevel level)
{
  m_props.clear();
}


void Logger::prop(std::string name, std::string value)
{
  m_props[name] = value;
}


void Logger::prop(std::string name, char charValue)
{
  std::string value(1,charValue);
  m_props[name] = value;
}

void Logger::prop(std::string name, int value)
{
  assert(0);
//   m_props[name] = value;
}


void Logger::end(std::string message)
{
  std::map<std::string, std::string>::iterator it = m_props.begin();

  std::cout << message << ":";
  for(std::map<std::string, std::string>::iterator it = m_props.begin();
      it != m_props.end(); it++)
  {
    std::cout << it->first << ":" << it->second << ",";
  }
  std::cout << "\n";
}


} // namespace logger