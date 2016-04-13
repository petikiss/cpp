#include "CSVParser.hh"

// TODO: needs to be deleted!
#include <iostream>

CSVParser::CSVParser(std::istream& stream) : mStream(stream),
                                             mFieldSeparator(','),
                                             mRecordEndLine('\n')
{
    // mRecordEndLine
}


bool
CSVParser::readRecord(std::vector<std::string>& record)
{
    std::cout << "readRecord()" <<std::endl;
    char c;
    mStream.get(c);
    std::cout << c << std::endl;
    std::string field = "";
    while(c != mRecordEndLine && !mStream.eof())
    {
        if (c != mFieldSeparator)
        {
            field += c;
        }
        else
        {
            record.push_back(field);
            field = "";
        }
        mStream.get(c);
    }

    if (field != "")
    {
        record.push_back(field);
        // TODO: maybe \n is necessary to push
    }
}
