#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "model/Uczen.h"
#include "managers/ZarzadcaUczniow.h"


struct ZarzadcaUczniowFixture {
    ZarzadcaUczniow testowyManagerUcznia;
    UczenPtr testowyUczenManU;

    ZarzadcaUczniowFixture() :
            testowyManagerUcznia(std::make_shared<UczenRepozytorium>(), std::make_shared<UczenRepozytorium>()) {}
};

BOOST_FIXTURE_TEST_SUITE(ZarzadcaUczniowSuite, ZarzadcaUczniowFixture)

    BOOST_AUTO_TEST_CASE(ZarejestrujUczniaTest) {
    testowyUczenManU=testowyManagerUcznia.zarejestrujUcznia("Harry", "Potter", "podstawówka", "hp@gmail.com", 934);
    BOOST_TEST(testowyManagerUcznia.znajdzAktualnychUczniow().size() == 1);
    BOOST_TEST(testowyManagerUcznia.znajdzAktualnychUczniow()[0] == testowyUczenManU);
    }

    BOOST_AUTO_TEST_CASE(UsunKontoUczniaTest) {
        testowyUczenManU=testowyManagerUcznia.zarejestrujUcznia("Harry", "Potter", "podstawówka", "hp@gmail.com", 934);
        testowyManagerUcznia.usunKontoUcznia(testowyUczenManU);
        BOOST_TEST(testowyManagerUcznia.znajdzAktualnychUczniow().size() == 0);
    }


BOOST_AUTO_TEST_SUITE_END()