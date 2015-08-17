#include <boost/test/unit_test.hpp>

#define private public
#define protected public

#include <utils/StringUtils.hpp>

#include <iostream>

struct fixture
{
    fixture() : i( 0 ) { BOOST_TEST_MESSAGE( "setup fixture" );  }
    ~fixture()       { BOOST_TEST_MESSAGE( "teardown fixture" ); }

    int i;
};

void dumpHeader(std::string text)
{
  std::string padding(80 - text.length(), '-');
  std::cout << "\n\n\n--------| TestStringUtils test " << text << " |" << padding << "\n\n";
}

// -------------------------TESTCASES---------------------------------------------------------------------------------------

BOOST_FIXTURE_TEST_CASE(TestStringToInt, fixture)
{
    dumpHeader("TestStringToInt()");

    BOOST_CHECK_EQUAL(utils::StringUtils::stringToInt("-300"),-300);
    BOOST_CHECK_EQUAL(utils::StringUtils::stringToInt("0"),0);
    BOOST_CHECK_EQUAL(utils::StringUtils::stringToInt("101"),101);
} // TestStringToInt


BOOST_FIXTURE_TEST_CASE(TestIntToString, fixture)
{
    dumpHeader("TestIntToString()");

    BOOST_CHECK_EQUAL(utils::StringUtils::intToString(-300),"-300");
    BOOST_CHECK_EQUAL(utils::StringUtils::intToString(0),"0");
    BOOST_CHECK_EQUAL(utils::StringUtils::intToString(101),"101");
} // TestIntToString


BOOST_FIXTURE_TEST_CASE(TestCharToInt, fixture)
{
  dumpHeader("TestCharToInt()");

  BOOST_CHECK_EQUAL(utils::StringUtils::charToInt('0'),0);
  BOOST_CHECK_EQUAL(utils::StringUtils::charToInt('1'),1);
} // TestCharToInt
