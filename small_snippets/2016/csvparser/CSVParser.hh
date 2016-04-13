#ifndef CSVPARSER_HH
#define CSVPARSER_HH

#include <vector>
#include <string>
#include <istream>

class CSVParser
{
  public:
    CSVParser(std::istream& stream);
    bool readRecord(std::vector<std::string>& record);
  private:
    std::istream& mStream;
    const char mFieldSeparator;
    const char mRecordEndLine;
    // const char mQuotesMark;
    // const std::vector<char> mRecordEndLine;
};

#endif
