#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "CSVParser.hh"
#include <iostream>
#include <string>

TEST_CASE( "Trivial TC", "[csvparser]" )
{
    // std::istringstream ss("asdf,asdf\n");
    // CSVParser parser(ss);

    // std::vector<std::string> record;
    // parser.readRecord(record);

    // REQUIRE( record.size() == 2 );
}

TEST_CASE("Empty read","[csvparser]")
{
    // std::istringstream ss;
    // CSVParser parser(ss);

    // std::vector<std::string> record;
    // parser.readRecord(record);

    // REQUIRE( record.size() == 0 );
}

TEST_CASE("Only one endl","[csvparser]")
{
    // std::istringstream ss("\n");
    // CSVParser parser(ss);

    // std::vector<std::string> record;
    // parser.readRecord(record);

    // REQUIRE( record.size() == 0 );
}

TEST_CASE("Differend endl","[csvparser]")
{
    std::istringstream ss("asdf,asdf,asdf\rasd,asd");
    CSVParser parser(ss);

    std::vector<std::string> record;
    parser.readRecord(record);

    REQUIRE( record.size() == 3 );

    record.clear();
    parser.readRecord(record);
    REQUIRE( record.size() == 2 );

}
