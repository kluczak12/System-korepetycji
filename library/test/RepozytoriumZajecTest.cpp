#include "repositories/ZajeciaRepozytorium.h"
#include "model/Zajecia.h"
#include "model/Uczen.h"
#include "model/PozostalePrzedmioty.h"
#include <boost/test/unit_test.hpp>


struct ZajeciaRepozytoriumFixture {
    ZajeciaRepozytorium testoweZajeciaRepo;
    PrzedmiotPtr testPrzedmiotRepZaj;
    UczenPtr testUczenRepZaj;
    ZajeciaPtr testoweZajeciaRepZaj;

    ZajeciaRepozytoriumFixture() :
            testoweZajeciaRepo(),
            testPrzedmiotRepZaj(std::make_shared<PozostalePrzedmioty>(80, "Technika", 2, 110, false)),
            testUczenRepZaj(std::make_shared<Uczen>("jan", "mal", "podstawowka", "aaa@a.pl", 3)),
            testoweZajeciaRepZaj(std::make_shared<Zajecia>(pt::time_from_string("2021-01-10 13:00:00"), 34, testUczenRepZaj, testPrzedmiotRepZaj)){}

    ~ZajeciaRepozytoriumFixture() {};
};


BOOST_FIXTURE_TEST_SUITE(ZajeciaRepozytoriumSuite, ZajeciaRepozytoriumFixture)

    BOOST_AUTO_TEST_CASE(DodajZajeciaTest) {
        testoweZajeciaRepo.dodajZajecia(testoweZajeciaRepZaj);
            BOOST_TEST(testoweZajeciaRepo.liczbaZajec()==1);
    }

    BOOST_AUTO_TEST_CASE(UsunZajeciaTest) {
        testoweZajeciaRepo.dodajZajecia(testoweZajeciaRepZaj);
        BOOST_TEST(testoweZajeciaRepo.liczbaZajec()==1);
        testoweZajeciaRepo.usunZajecia(nullptr);
        BOOST_TEST(testoweZajeciaRepo.liczbaZajec()==1);
        testoweZajeciaRepo.usunZajecia(testoweZajeciaRepZaj);
        BOOST_TEST(testoweZajeciaRepo.liczbaZajec()==0);
    }


    BOOST_AUTO_TEST_CASE(ZnajdzPoIdZajecTest) {
        testoweZajeciaRepo.dodajZajecia(testoweZajeciaRepZaj);
        BOOST_CHECK_EQUAL(testoweZajeciaRepo.znajdzPoIdZajec(34), testoweZajeciaRepZaj);
        BOOST_CHECK_THROW(testoweZajeciaRepo.znajdzPoIdZajec(43), std::runtime_error);
    }

BOOST_AUTO_TEST_SUITE_END()