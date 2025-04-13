#include "managers/ZarzadcaUczniow.h"
#include <iostream>
#include <fstream>
#include "model/Uczen.h"

ZarzadcaUczniow::~ZarzadcaUczniow() {

}

ZarzadcaUczniow::ZarzadcaUczniow(const UczenRepozytoriumPtr &aktualnySpisUczniow,
                                 const UczenRepozytoriumPtr &archiwumUczniow) : aktualnySpisUczniow(
        aktualnySpisUczniow), archiwumUczniow(archiwumUczniow) {}

std::vector<UczenPtr> ZarzadcaUczniow::znajdzAktualnychUczniow() {
    return aktualnySpisUczniow->znajdz([](UczenPtr ) {return true;});}

std::vector<UczenPtr> ZarzadcaUczniow::znajdzUczniowZArchiwum() {
    return archiwumUczniow->znajdz([](UczenPtr ) {return true;});}

UczenPtr ZarzadcaUczniow::zarejestrujUcznia(const std::string &imieUcznia, const std::string &nazwiskoUcznia,
                                            const std::string &poziomEdukacji, const std::string &adresEmail,
                                            unsigned int idUcznia) {
    UczenPtr nowyUczen = std::make_shared<Uczen>(imieUcznia, nazwiskoUcznia, poziomEdukacji, adresEmail, idUcznia);
    aktualnySpisUczniow->dodajUcznia(nowyUczen);
    archiwumUczniow->dodajUcznia(nowyUczen);

    std::ofstream plik1;
    plik1.open("../../zapis/aktualniUczniowie.txt", std::ios::app);
    if(plik1.good())
    {
        plik1<<nowyUczen->getInfo()<<std::endl;
    }
    else {
        throw std::ios_base::failure("Blad podczas otwierania pliku do zapisu.");
    }
    plik1.close();

    std::ofstream plik2;
    plik2.open("../../zapis/archiwumUczniow.txt", std::ios::app);
    if(plik2.good())
    {
        plik2<<nowyUczen->getInfo()<<std::endl;
    }
    else {
        throw std::ios_base::failure("Blad podczas otwierania pliku do zapisu.");
    }
    plik2.close();

    return nowyUczen;
}

bool ZarzadcaUczniow::usunKontoUcznia(const UczenPtr &uczen) {
    aktualnySpisUczniow->usunUcznia(uczen);
    std::string plikDoZapisu = "../../zapis/aktualniUczniowie.txt";
    std::string plikDodatkowy = "../../zapis/pomocniczy.txt";
    std::ifstream plik1;
    std::ofstream pomocniczy;
    plik1.open(plikDoZapisu, std::ios::app);
    pomocniczy.open(plikDodatkowy, std::ios::app);
    if(plik1.good() && pomocniczy.good())
    {
        std::string linijka;
        while (std::getline(plik1, linijka))
        {
            if (linijka.find(uczen->getInfo()) == std::string::npos)
            {
                pomocniczy << linijka << std::endl;
            }
        }
    }
    else
    {
        throw std::ios_base::failure("Blad podczas otwierania pliku do zapisu.");
    }
    plik1.close();
    pomocniczy.close();

    std::remove(plikDoZapisu.c_str());
    std::rename("pomocniczy.txt", plikDoZapisu.c_str());
    return true;
}




