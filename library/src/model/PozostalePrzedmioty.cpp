#include "model/PozostalePrzedmioty.h"

bool PozostalePrzedmioty::isKorepetycjeGrupowe() const {
    return korepetycjeGrupowe;
}

//cene za materialy dydaktyczne rozkladamy na częściowe koszty za godzine
double PozostalePrzedmioty::kosztGodzinyKorepetycji() {
    double pomKoszt=getCenaZaMaterialyDydaktyczne()*0.01+getCenaZaGodzine();
    if(isKorepetycjeGrupowe())
    {
        return pomKoszt*0.8;
    }
    return pomKoszt;
}

std::string PozostalePrzedmioty::getInfo() {
    return Przedmiot::getInfo()+", czy zajecia w grupie: "+std::to_string(isKorepetycjeGrupowe());
}

PozostalePrzedmioty::PozostalePrzedmioty(int cenaZaMaterialyDydaktyczne, const std::string &nazwaPrzedmiotu,
                                         int liczbaNauczycieli, double cenaZaGodzine, bool korepetycjeGrupowe)
        : Przedmiot(cenaZaMaterialyDydaktyczne, nazwaPrzedmiotu, liczbaNauczycieli, cenaZaGodzine),
          korepetycjeGrupowe(korepetycjeGrupowe) {}

PozostalePrzedmioty::~PozostalePrzedmioty() {

}
