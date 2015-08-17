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

#ifndef SSLOGGER_LOGGER_HPP
#define SSLOGGER_LOGGER_HPP

#include <string>
#include <map>

namespace logger
{
// INFO:        default logging level
// DEBUG:     some extra log
// FINE:        function calls
//WARNING: problems
// ALL:         everything

class Logger
{
  public:
    enum LogLevel {INFO, DEBUG, FINE, WARNING, ALL};
    Logger();
    ~Logger();
    void log(LogLevel level = Logger::INFO, std::string message="");
    void begin(LogLevel level);
    void prop(std::string name, std::string value);
    void prop(std::string name, int value);
    void prop(std::string name, char charValue);
    void end(std::string message);
  private:
    std::map<std::string, std::string> m_props;
}; // class logger

} // namespace logger
#endif
