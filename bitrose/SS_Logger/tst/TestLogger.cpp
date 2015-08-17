#include <boost/test/unit_test.hpp>

#define private public
#define protected public

#include <logger/Logger.hpp>
#include <iostream>

struct fixture
{
    fixture() : i( 0 ) { BOOST_TEST_MESSAGE( "setup fixture" );  }
    ~fixture()       { BOOST_TEST_MESSAGE( "teardown fixture" ); }

    int i;
};


BOOST_FIXTURE_TEST_CASE(TestFirst, fixture)
{
    logger::Logger logger;
    logger.log(logger::Logger::INFO,"Hello");
}
