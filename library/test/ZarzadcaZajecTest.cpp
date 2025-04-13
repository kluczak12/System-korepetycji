#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "model/Zajecia.h"
#include "managers/ZarzadcaZajec.h"
#include "model/Uczen.h"
#include "model/PozostalePrzedmioty.h"


struct ZarzadcaZajecFixture {
    ZarzadcaZajec testowyManagerZajec;
    ZajeciaPtr testoweZajeciaManZ;
    UczenPtr testowyUczenManZ;
    PrzedmiotPtr testowyPrzedmiotManZ;

    ZarzadcaZajecFixture() :
            testowyManagerZajec(std::make_shared<ZajeciaRepozytorium>(), std::make_shared<ZajeciaRepozytorium>()),
            testowyUczenManZ(std::make_shared<Uczen>("Ktoś", "Nowy", "liceum", "ktosiek@op.pl", 11)),
            testowyPrzedmiotManZ(std::make_shared<PozostalePrzedmioty>(50, "Fizyka", 4, 80, false))    {}
};

BOOST_FIXTURE_TEST_SUITE(ZarzadcaZajecSuite, ZarzadcaZajecFixture)

    BOOST_AUTO_TEST_CASE(StworzZajeciaTest) {
        testoweZajeciaManZ=testowyManagerZajec.stworzZajecia(pt::time_from_string("2024-06-13 12:00:00"), 90,testowyUczenManZ, testowyPrzedmiotManZ);
        BOOST_TEST(testowyManagerZajec.znajdzAktualneZajecia().size() == 1);
        BOOST_TEST(testowyManagerZajec.znajdzAktualneZajecia()[0] == testoweZajeciaManZ);
    }

    BOOST_AUTO_TEST_CASE(UsunZajeciaTest) {
        testoweZajeciaManZ=testowyManagerZajec.stworzZajecia(pt::time_from_string("2024-06-13 12:00:00"), 90,testowyUczenManZ, testowyPrzedmiotManZ);
        testowyManagerZajec.dezaktywujZajecia(testoweZajeciaManZ);
        BOOST_TEST(testowyManagerZajec.znajdzAktualneZajecia().size() == 0);
    }


BOOST_AUTO_TEST_SUITE_END()