#include <boost/test/unit_test.hpp>

#define private public
#define protected public

#include <logger/Logger.hpp>
#include <bencoder/Bencoder.hh>

#include <list>
#include <iostream>


// I would use BOOST_CHECK or BOOST_CHECK_EQUAL before the BOOST_REQUIRE.
// BOOST_CHECK" just reports the error and continues, so the test fails, but you get to see all the wrong values.
// BOOST_REQUIRE: If you want to force the test to stop afterwards use BOOST_REQUIRE afterwards.

struct fixture
{
    fixture()  { BOOST_TEST_MESSAGE( "setup fixture" ); m_logger = new logger::Logger();  }
    ~fixture()       { BOOST_TEST_MESSAGE( "teardown fixture" ); delete m_logger;}

    logger::Logger* m_logger;
};


void dumpHeader(std::string text)
{
  std::string padding(80 - text.length(), '-');
  std::cout << "\n\n\n--------| TestParse test " << text << " |" << padding << "\n\n";
}

/*
// check weather a list contains the str
bool contains(std::list<std::string> list, std::string str)
{
  // iterate throw the list
  for(std::list<std::string>::iterator it = list.begin();
      it != list.end();
      it++)
      {
        if (*it == str)
        {
          return true;
        }
      }

return false;
}
*/

//bool contains(const Bencoder::ListPtr list, const Bencoder::AnyType& item)
//{
/*
    std::list<Bencoder::AnyTypePtr> l = list->getValue();

    for(std::list<Bencoder::AnyTypePtr>::const_iterator it = l.begin();
        it != l.end();
        ++it)
    {
        if (*(it->get()) == item)
        {
            return true;
        }
    }

     return false;

     */
//}


// // print a list
// void printList(std::list<std::string> list)
// {
//   std::list<std::string>::iterator it = list.begin();

//   std::cout << "Elements in the list:";
//   for(std::list<std::string>::iterator it = list.begin();
//       it != list.end();
//       it++)
//       {
//         std::cout << *it << ",";
//       }
//   std::cout << "\n";
// }

// -------------------------TESTCASES---------------------------------------------------------------------------------------


BOOST_FIXTURE_TEST_CASE(TestIsDigit, fixture)
{
    dumpHeader("TestIsDigit()");

    //Bencoder::Bencoder bc(m_logger);
//    bool digit;
//    digit = bc.isDigit('0');
//    BOOST_CHECK(digit);

    //digit = bc.isDigit('5');
    //BOOST_CHECK(digit);

//    digit = bc.isDigit('9');
    //BOOST_CHECK(digit);

    //digit = bc.isDigit('a');
    //BOOST_CHECK(!digit);
} // TestIsDigit


/*
BOOST_FIXTURE_TEST_CASE(TestParseString, fixture)
{
    dumpHeader("TestParseString");

    Bencoder::Bencoder bc(m_logger);
    unsigned int pos1 = 0;
    BOOST_CHECK_EQUAL(bc.parseString("2:aa",pos1)->getValue(),"aa");
    BOOST_CHECK_EQUAL(pos1, 4);

    unsigned int pos2 = 0;
    BOOST_CHECK_EQUAL(bc.parseString("12:asdfasdfasdf",pos2)->getValue(),"asdfasdfasdf");
    BOOST_CHECK_EQUAL(pos2, 15);

    unsigned int pos3 = 5;
    BOOST_CHECK_EQUAL(bc.parseString("xxxxx100:aaaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeaaaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeee",pos3)->getValue(),"aaaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeaaaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeee");
    BOOST_CHECK_EQUAL(pos3, 109);


}



BOOST_FIXTURE_TEST_CASE(TestParseThreeString, fixture)
{
    dumpHeader("Parse string three times");


    Bencoder::Bencoder bc(m_logger);
    unsigned int pos = 0;
    std::string needParse = "2:aa12:asdfasdfasdf5:12345";
    BOOST_CHECK_EQUAL(bc.parseString(needParse,pos)->getValue(),"aa");
    BOOST_CHECK_EQUAL(bc.parseString(needParse,pos)->getValue(),"asdfasdfasdf");
    BOOST_CHECK_EQUAL(bc.parseString(needParse,pos)->getValue(),"12345");


}


BOOST_FIXTURE_TEST_CASE(TestParseInteger, fixture)
{
    dumpHeader("TestParseInteger");


    Bencoder::Bencoder bc(m_logger);
    unsigned int pos1 = 0;
    BOOST_CHECK_EQUAL(bc.parseInteger("i123e",pos1)->getValue(), 123);
    BOOST_CHECK_EQUAL(pos1, 5);

    unsigned int pos2 = 1;
    BOOST_CHECK_EQUAL(bc.parseInteger("xi-123e",pos2)->getValue(), -123);
    BOOST_CHECK_EQUAL(pos2, 7);

    unsigned int pos3 = 4;
    BOOST_CHECK_EQUAL(bc.parseInteger("xxxxi123456789e",pos3)->getValue(), 123456789);
    BOOST_CHECK_EQUAL(pos3, 15);

    unsigned int pos4 = 0;
    BOOST_CHECK_EQUAL(bc.parseInteger("i0e",pos4)->getValue(), 0);
    BOOST_CHECK_EQUAL(pos4, 3);


}


BOOST_FIXTURE_TEST_CASE(TestParseFourInteger, fixture)
{
    dumpHeader("Parse integer four times");


    Bencoder::Bencoder bc(m_logger);
    unsigned int pos = 0;
    std::string needParse = "i123ei54321ei000ei-500e";

    BOOST_CHECK_EQUAL(bc.parseInteger(needParse, pos)->getValue(), 123);
    BOOST_CHECK_EQUAL(bc.parseInteger(needParse, pos)->getValue(), 54321);
    BOOST_CHECK_EQUAL(bc.parseInteger(needParse, pos)->getValue(), 0);
    BOOST_CHECK_EQUAL(bc.parseInteger(needParse, pos)->getValue(), -500);


}


BOOST_FIXTURE_TEST_CASE(TestParseList1, fixture)
{
    dumpHeader("Parse string with only strings");


    Bencoder::Bencoder bc(m_logger);

    // only string in List
    unsigned int pos = 0;
    std::string needParse = "l3:foo4:aaaa7:bbbbbbbe";
    Bencoder::ListPtr list = bc.parseList(needParse, pos);
    BOOST_CHECK_EQUAL(list->getValue().size(), 3);

    BOOST_CHECK(contains(list, Bencoder::String("foo")));
    BOOST_CHECK(contains(list, Bencoder::String("aaaa")));
    BOOST_CHECK(contains(list, Bencoder::String("bbbbbbb")));

}


BOOST_FIXTURE_TEST_CASE(TestParseList2, fixture)
{
    dumpHeader("Parse with only integers");


    Bencoder::Bencoder bc(m_logger);

    // only string in List
    unsigned int pos = 0;
    std::string needParse = "li12345ei-500ei0ee";
    Bencoder::ListPtr list = bc.parseList(needParse, pos);
    BOOST_CHECK_EQUAL(list->getValue().size(), 3);

    BOOST_CHECK(contains(list, Bencoder::Integer(12345)));
    BOOST_CHECK(contains(list, Bencoder::Integer(-500)));
    BOOST_CHECK(contains(list, Bencoder::Integer(0)));

    }


BOOST_FIXTURE_TEST_CASE(TestParseList3, fixture)
{
    dumpHeader("Parse with string AND integers");


    Bencoder::Bencoder bc(m_logger);

    // only string in List
    unsigned int pos = 0;
    std::string needParse = "l4:asdfi5e10:asdfasdfasi-300ei10ee";
    Bencoder::ListPtr list = bc.parseList(needParse, pos);
    BOOST_CHECK_EQUAL(list->getValue().size(), 5);

    BOOST_CHECK(contains(list, Bencoder::Integer(5)));
    BOOST_CHECK(contains(list, Bencoder::Integer(-300)));
    BOOST_CHECK(contains(list, Bencoder::String("asdf")));
    BOOST_CHECK(contains(list, Bencoder::String("asdfasdfas")));

}


BOOST_FIXTURE_TEST_CASE(TestParseList4, fixture)
{
    dumpHeader("Parse list");

     Bencoder::Bencoder bc(m_logger);

     
}






BOOST_FIXTURE_TEST_CASE(TestParseInteger, fixture)
{
    dumpHeader("TestParseInteger()");

    Bencoder::Bencoder bc(m_logger);
    std::list<std::string> list;

    std::string str = "i13e";
    bc.parseInteger(str, list);
    BOOST_CHECK_EQUAL(list.size(),1);
    BOOST_CHECK_EQUAL(list.back(),"13");

    str = "i-67e";
    bc.parseInteger(str, list);
    BOOST_CHECK_EQUAL(list.size(),2);
    BOOST_CHECK_EQUAL(list.back(),"-67");

    str = "i-2000e";
    bc.parseInteger(str, list);
    BOOST_CHECK_EQUAL(list.size(),3);
    BOOST_CHECK_EQUAL(list.back(),"-2000");

    str = "i0e";
    bc.parseInteger(str, list);
    BOOST_CHECK_EQUAL(list.size(),4);
    BOOST_CHECK_EQUAL(list.back(),"0");

    printList(list);


} // TestParseInteger


BOOST_FIXTURE_TEST_CASE(TestParseString, fixture)
{
  dumpHeader("TestParseString()");


  Bencoder::Bencoder bc(m_logger);
  std::list<std::string> list;

  std::string str = "4:spam";
  bc.parseString(str, list);
  BOOST_CHECK_EQUAL(list.size(),1);
  BOOST_CHECK_EQUAL(list.back(),"spam");

  str = "0:";
  bc.parseString(str, list);
  BOOST_CHECK_EQUAL(list.size(),2);
  BOOST_CHECK_EQUAL(list.back(),"");

  str = "6:marton";
  bc.parseString(str, list);
  BOOST_CHECK_EQUAL(list.size(),3);
  BOOST_CHECK_EQUAL(list.back(),"marton");

  str = "17:publisher-webpage";
  bc.parseString(str, list);
  BOOST_CHECK_EQUAL(list.size(),4);
  BOOST_CHECK_EQUAL(list.back(),"publisher-webpage");

  str = "18:publisher.location";
  bc.parseString(str, list);
  BOOST_CHECK_EQUAL(list.size(),5);
  BOOST_CHECK_EQUAL(list.back(),"publisher.location");

  printList(list);

} // TestParseString


BOOST_FIXTURE_TEST_CASE(TestDecode, fixture)
{
  dumpHeader("TestDecode()");

  Bencoder::Bencoder bc(m_logger);

  // test integer
  bc.decode("i1ei2ei3ei4ei5ei6ei7ei8ei9ei10ei11ei12ei13ei14ei15ei100ei0ei1000e");
  BOOST_CHECK_EQUAL(bc.m_integers.size(), 18);
  BOOST_CHECK(contains(bc.m_integers,"1"));
  BOOST_CHECK(contains(bc.m_integers,"2"));
  BOOST_CHECK(contains(bc.m_integers,"3"));
  BOOST_CHECK(contains(bc.m_integers,"4"));
  BOOST_CHECK(contains(bc.m_integers,"5"));
  BOOST_CHECK(contains(bc.m_integers,"6"));
  BOOST_CHECK(contains(bc.m_integers,"7"));
  BOOST_CHECK(contains(bc.m_integers,"8"));
  BOOST_CHECK(contains(bc.m_integers,"9"));
  BOOST_CHECK(contains(bc.m_integers,"0"));
  BOOST_CHECK(contains(bc.m_integers,"1000"));
  printList(bc.m_integers);

  // test string
  bc.decode("8:announce4:spam6:marton4:eggs9:publisher3:bob17:publisher-webpage15:www.example.com18:publisher.location4:home");
  BOOST_CHECK_EQUAL(bc.m_strings.size(), 10);
  BOOST_CHECK(contains(bc.m_strings,"announce"));
  BOOST_CHECK(contains(bc.m_strings,"spam"));
  BOOST_CHECK(contains(bc.m_strings,"marton"));
  BOOST_CHECK(contains(bc.m_strings,"eggs"));
  BOOST_CHECK(contains(bc.m_strings,"publisher"));
  BOOST_CHECK(contains(bc.m_strings,"bob"));
  BOOST_CHECK(contains(bc.m_strings,"publisher-webpage"));
  BOOST_CHECK(contains(bc.m_strings,"www.example.com"));
  BOOST_CHECK(contains(bc.m_strings,"publisher.location"));
  BOOST_CHECK(contains(bc.m_strings,"home"));
  printList(bc.m_strings);

}// testDecode


BOOST_FIXTURE_TEST_CASE(TestParseList, fixture)
{
    dumpHeader("TestParseList()");

    Bencoder::Bencoder bc(m_logger);

    // [ "spam", "eggs" ]
//     bc.decode("l4:spam4:eggse");
//     std::list< std::list<std::string> >::iterator it = bc.m_lists.begin();
//     TS_ASSERT_EQUALS(*it, 2);
//     TS_ASSERT(contains(*it,"spam"));
//     TS_ASSERT(contains(*it,"eggs"));

} // TestParseList
*/


