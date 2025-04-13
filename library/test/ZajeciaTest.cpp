#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "model/PozostalePrzedmioty.h"
#include "model/Uczen.h"
#include <boost/date_time.hpp>

namespace btt = boost::test_tools;
namespace pt = boost::posix_time;

struct TestSuiteZajeciaFixture {

    pt::ptime pomCzasRozp;
    pt::ptime pomCzasZak;
    PrzedmiotPtr testPrzedmiot111;
    UczenPtr testUczen11;
    ZajeciaPtr testZajecia1;


    TestSuiteZajeciaFixture()
            : pomCzasRozp(pt::time_from_string("2022-05-15 12:00:00")),
              pomCzasZak(pt::time_from_string("2022-05-15 13:00:00")),
              testPrzedmiot111(std::make_shared<PozostalePrzedmioty>(70, "Fizyka", 2, 120, false)),
              testUczen11(std::make_shared<Uczen>("jan", "mal", "podstawowka", "aaa@a.pl", 3)),
              testZajecia1(std::make_shared<Zajecia>(pomCzasRozp, 3, testUczen11,  testPrzedmiot111))
             {
    }
    ~TestSuiteZajeciaFixture() {
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteZajecia, TestSuiteZajeciaFixture)

    BOOST_AUTO_TEST_CASE(KonstruktorZajecTests) {
        BOOST_TEST(testUczen11 == testZajecia1->getUczen());
        BOOST_TEST(testPrzedmiot111 == testZajecia1->getPrzedmiot());
        BOOST_TEST(pomCzasRozp == testZajecia1->getCzasRozpoczecia());
    }

    BOOST_AUTO_TEST_CASE(SetterKosztZajecTest)
    {
        testZajecia1->setKosztZajec(200);
        BOOST_TEST(testZajecia1->getKosztZajec() == 200);
    }

    BOOST_AUTO_TEST_CASE(SetterCzasZakonczeniaTest)
    {
        testZajecia1->setCzasZakonczenia(pt::time_from_string("2122-05-15 12:00:00"));
        BOOST_TEST(testZajecia1->getCzasZakonczenia() == pt::time_from_string("2122-05-15 12:00:00"));
    }

    BOOST_AUTO_TEST_CASE(ZakonczZajeciaTest)
    {
        testZajecia1->zakonczZajecia(pomCzasZak);
        BOOST_TEST(testZajecia1->getKosztZajec() == 120.7);
        BOOST_TEST(pomCzasZak == testZajecia1->getCzasZakonczenia());
    }


BOOST_AUTO_TEST_SUITE_END()