#include "repositories/UczenRepozytorium.h"
#include <boost/test/unit_test.hpp>
#include "model/Uczen.h"

struct UczenRepozytoriumFixture {
    UczenRepozytorium testowyUczenRepo;
    UczenPtr testowyUczen;

    UczenRepozytoriumFixture() :
            testowyUczenRepo(),
            testowyUczen(std::make_shared<Uczen>("janina", "malwa", "podstawowka", "aaa@a.pl", 66)) {}

    ~UczenRepozytoriumFixture(){};
};

BOOST_FIXTURE_TEST_SUITE(RepozytoriumUczniaSuite, UczenRepozytoriumFixture)

    BOOST_AUTO_TEST_CASE(DodajUczniaTest) {
        testowyUczenRepo.dodajUcznia(testowyUczen);
        BOOST_TEST(testowyUczenRepo.liczbaUczniow() == 1);
        testowyUczenRepo.dodajUcznia(nullptr);
        BOOST_TEST(testowyUczenRepo.liczbaUczniow() == 1);
}

    BOOST_AUTO_TEST_CASE(UsunUczniaTest) {
        testowyUczenRepo.dodajUcznia(testowyUczen);
        BOOST_TEST(testowyUczenRepo.liczbaUczniow() == 1);

        testowyUczenRepo.usunUcznia(nullptr);
        BOOST_TEST(testowyUczenRepo.liczbaUczniow() == 1);
        testowyUczenRepo.usunUcznia(testowyUczen);
        BOOST_TEST(testowyUczenRepo.liczbaUczniow() == 0);
    }


    BOOST_AUTO_TEST_CASE(ZnajdzPoIdUczniaTest) {
        testowyUczenRepo.dodajUcznia(testowyUczen);
        BOOST_CHECK_EQUAL(testowyUczenRepo.znajdzPrzezIdUcznia(66), testowyUczen);
        BOOST_CHECK_THROW(testowyUczenRepo.znajdzPrzezIdUcznia(56), std::runtime_error);
    }

BOOST_AUTO_TEST_SUITE_END()