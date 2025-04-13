#include "managers/ZarzadcaZajec.h"

ZarzadcaZajec::ZarzadcaZajec(const ZajeciaRepozytoriumPtr &aktualneZajecia, const ZajeciaRepozytoriumPtr &archiwumZajec)
        : aktualneZajecia(aktualneZajecia), archiwumZajec(archiwumZajec) {}

ZarzadcaZajec::~ZarzadcaZajec() {

}

std::vector<ZajeciaPtr> ZarzadcaZajec::znajdzAktualneZajecia() {
    return aktualneZajecia->znajdz([](ZajeciaPtr ) {return true;});}


std::vector<ZajeciaPtr> ZarzadcaZajec::znajdzZajeciaZArchiwum() {
    return archiwumZajec->znajdz([](ZajeciaPtr ) {return true;});}

bool ZarzadcaZajec::dezaktywujZajecia(const ZajeciaPtr &zajecia) {
    aktualneZajecia->usunZajecia(zajecia);
    std::string plikDoZapisu = "../../zapis/aktualneZajecia.txt";
    std::string plikDodatkowy = "../../zapis/pomocniczyZajecia.txt";
    std::ifstream plik1;
    std::ofstream pomocniczy;
    plik1.open(plikDoZapisu, std::ios::app);
    pomocniczy.open(plikDodatkowy, std::ios::app);
    if(plik1.good() && pomocniczy.good())
    {
        std::string linijka;
        while (std::getline(plik1, linijka))
        {
            if (linijka.find(zajecia->getInfo()) == std::string::npos)
            {
                pomocniczy << linijka << std::endl;
            }
        }
    }
    else
    {
        throw std::ios_base::failure("Blad podczas otwierania pliku do zapisu.");
        return false;
    }
    plik1.close();
    pomocniczy.close();

    std::remove(plikDoZapisu.c_str());
    std::rename("pomocniczyZajecia.txt", plikDoZapisu.c_str());
    return true;
}

ZajeciaPtr ZarzadcaZajec::stworzZajecia(const pt::ptime &czasRozpoczecia, unsigned int id, const UczenPtr &uczen,
                                        const PrzedmiotPtr &przedmiot) {
    ZajeciaPtr noweZajecia = std::make_shared<Zajecia>(czasRozpoczecia, id, uczen, przedmiot);
    aktualneZajecia->dodajZajecia(noweZajecia);
    archiwumZajec->dodajZajecia(noweZajecia);

    std::ofstream plik1;
    plik1.open("../../zapis/aktualneZajecia.txt", std::ios::app);
    if(plik1.good())
    {
        plik1<<noweZajecia->getInfo()<<std::endl;
    }
    else {
        throw std::ios_base::failure("Blad podczas otwierania pliku do zapisu.");
    }
    plik1.close();

    std::ofstream plik2;
    plik2.open("../../zapis/archiwumZajec.txt", std::ios::app);
    if(plik2.good())
    {
        plik2<<noweZajecia->getInfo()<<std::endl;
    }
    else {
        throw std::ios_base::failure("Blad podczas otwierania pliku do zapisu.");
    }
    plik2.close();

    return noweZajecia;}
