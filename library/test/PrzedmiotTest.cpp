#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "model/PozostalePrzedmioty.h"
#include "model/Jezyki.h"

namespace btt = boost::test_tools;

struct TestSuitePrzedmiotFixture {
    int testCenaZaMaterialy = 10;
    const std::string testNazwa = "Matematyka";
    int testLiczbaNauczycieli = 1;
    double testCenaZaGodzine = 100.0;
    bool testCzyGrupowe = true;

    int testCenaZaMaterialy2 = 50;
    const std::string testNazwa2 = "Hiszpanski";
    int testLiczbaNauczycieli2 = 2;
    double testCenaZaGodzine2 = 120.0;
    double testCenaZaNative=3;
    PoziomJezyka testPoziom = PoziomJezyka::A1;

    PozostalePrzedmioty testPrzedmiot11;
    Jezyki testPrzedmiot22;


    TestSuitePrzedmiotFixture()
            : testPrzedmiot11(testCenaZaMaterialy, testNazwa, testLiczbaNauczycieli, testCenaZaGodzine, true),
              testPrzedmiot22(testCenaZaMaterialy2, testNazwa2, testLiczbaNauczycieli2, testCenaZaGodzine2, testPoziom, testCenaZaNative){
    }

    ~TestSuitePrzedmiotFixture() {
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuitePrzedmiot, TestSuitePrzedmiotFixture)

    BOOST_AUTO_TEST_CASE(ConstructorTests) {
        BOOST_TEST(testCenaZaMaterialy == testPrzedmiot11.getCenaZaMaterialyDydaktyczne());
        BOOST_TEST(testNazwa == testPrzedmiot11.getNazwaPrzedmiotu());
        BOOST_TEST(testLiczbaNauczycieli == testPrzedmiot11.getLiczbaNauczycieli());
        BOOST_TEST(testCenaZaGodzine == testPrzedmiot11.getCenaZaGodzine());
        BOOST_TEST(testCzyGrupowe == testPrzedmiot11.isKorepetycjeGrupowe());

        BOOST_TEST(testCenaZaMaterialy2 == testPrzedmiot22.getCenaZaMaterialyDydaktyczne());
        BOOST_TEST(testNazwa2 == testPrzedmiot22.getNazwaPrzedmiotu());
        BOOST_TEST(testLiczbaNauczycieli2 == testPrzedmiot22.getLiczbaNauczycieli());
        BOOST_TEST(testCenaZaGodzine2 == testPrzedmiot22.getCenaZaGodzine());
        BOOST_TEST(static_cast<int>(testPoziom) == static_cast<int>(testPrzedmiot22.getPoziom()));
        BOOST_TEST(testCenaZaNative == testPrzedmiot22.getCenaZaNative());

    }

    BOOST_AUTO_TEST_CASE(KosztKorepetycjiTest) {
        BOOST_CHECK_CLOSE_FRACTION(testPrzedmiot11.kosztGodzinyKorepetycji(), 80.08, 0.001);
        BOOST_TEST(testPrzedmiot22.kosztGodzinyKorepetycji()==137.5);

    }

    BOOST_AUTO_TEST_CASE(SetLiczbaNauczycieliTest) {
        testPrzedmiot22.setLiczbaNauczycieli(99);
        BOOST_TEST(testPrzedmiot22.getLiczbaNauczycieli()==99);

    }

    BOOST_AUTO_TEST_CASE(SetPoziomJezykiTest) {
        testPrzedmiot22.setPoziom(PoziomJezyka::C1);
        BOOST_TEST(static_cast<int>(testPrzedmiot22.getPoziom())==static_cast<int>(PoziomJezyka::C1));

    }


BOOST_AUTO_TEST_SUITE_END()