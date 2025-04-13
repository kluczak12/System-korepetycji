#include <boost/test/unit_test.hpp>
#include "model/Uczen.h"
#include "typedefs.h"
#include "model/Jezyki.h"

namespace btt = boost::test_tools;

struct TestSuiteUczenFixture {
    const std::string testImie = "Adam";
    const std::string testNazwisko = "Tetsowy";
    const std::string testPoziomEdukacji = "podstawowka";
    const std::string testMail = "Mail@p.pl";
    PrzedmiotPtr testPrzedmiot1;
    UczenPtr testUczen1;
    ZajeciaPtr testZajecia1;
    PrzedmiotPtr testPrzedmiot2;
    ZajeciaPtr testZajecia2;

    TestSuiteUczenFixture()
            : testPrzedmiot1(std::make_shared<Jezyki>(50, "Angielski", 2, 80, PoziomJezyka::A1, 50.0)),
              testUczen1(std::make_shared<Uczen>(testImie, testNazwisko, testPoziomEdukacji, testMail, 1)),
              testZajecia1(std::make_shared<Zajecia>(pt::time_from_string("2024-06-16 12:00:00"), 1, testUczen1, testPrzedmiot1)),
              testPrzedmiot2(std::make_shared<Jezyki>(50, "Angielski", 0, 80, PoziomJezyka::A1, 50.0)),
              testZajecia2(std::make_shared<Zajecia>(pt::time_from_string("2024-06-16 12:00:00"), 2, testUczen1, testPrzedmiot2)){
    }

    ~TestSuiteUczenFixture() {
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteUczen, TestSuiteUczenFixture)

BOOST_AUTO_TEST_CASE(ConstructorTests) {
        BOOST_TEST(testImie == testUczen1->getImieUcznia());
        BOOST_TEST(testNazwisko == testUczen1->getNazwiskoUcznia());
        BOOST_TEST(testPoziomEdukacji == testUczen1->getPoziomEdukacji());
        BOOST_TEST(testMail == testUczen1->getAdresEmail());
}

BOOST_AUTO_TEST_CASE(SetterPoziomuEdukacjiTest) {
        testUczen1->setPoziomEdukacji("liceum");
        BOOST_TEST(testUczen1->getPoziomEdukacji()=="liceum");
}

BOOST_AUTO_TEST_SUITE_END()