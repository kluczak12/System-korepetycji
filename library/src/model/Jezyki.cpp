#include "model/Jezyki.h"
#include <iostream>

float Jezyki::getCenaZaNative() const {
    return cenaZaNative;
}

Jezyki::~Jezyki() {

}

//cene za materialy dydaktyczne rozkladamy na częściowe koszty za godzine
double Jezyki::kosztGodzinyKorepetycji() {
    return (1+static_cast<double>(poziom)/100.0)*getCenaZaGodzine()+getCenaZaNative()+getCenaZaMaterialyDydaktyczne()*0.05;
}

std::string Jezyki::getInfo() {
    return Przedmiot::getInfo()+", cena zwiększona przez zajęcia z native o: "+std::to_string(getCenaZaNative()) + ", poziom języka: " +
            nazwaPoziomu(getPoziom())+", który zwiększa cenę za godzinę o "+std::to_string(static_cast<double>(poziom))+" procent";
}

Jezyki::Jezyki(int cenaZaMaterialyDydaktyczne, const std::string &nazwaPrzedmiotu, int liczbaNauczycieli,
               double cenaZaGodzine, PoziomJezyka poziom, float cenaZaNative) : Przedmiot(cenaZaMaterialyDydaktyczne,
                                                                                           nazwaPrzedmiotu,
                                                                                           liczbaNauczycieli,
                                                                                           cenaZaGodzine),
                                                                                 poziom(poziom),
                                                                                 cenaZaNative(cenaZaNative) {}

PoziomJezyka Jezyki::getPoziom() const {
    return poziom;
}

void Jezyki::setPoziom(PoziomJezyka poziomCpp) {
    Jezyki::poziom = poziomCpp;
}

std::string Jezyki::nazwaPoziomu(PoziomJezyka poziomCpp) const {
    switch(poziomCpp) {
        case PoziomJezyka::A1: return "A1";
        case PoziomJezyka::A2: return "A2";
        case PoziomJezyka::B1: return "B1";
        case PoziomJezyka::B2: return "B2";
        case PoziomJezyka::C1: return "C1";
        case PoziomJezyka::C2: return "C2";
        default: return "Nieznany poziom";
    }
}

