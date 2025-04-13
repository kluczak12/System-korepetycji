#include "model/Przedmiot.h"

Przedmiot::Przedmiot(int cenaZaMaterialyDydaktyczne, const std::string &nazwaPrzedmiotu, int liczbaNauczycieli,
                     double cenaZaGodzine) : cenaZaMaterialyDydaktyczne(cenaZaMaterialyDydaktyczne),
                                             nazwaPrzedmiotu(nazwaPrzedmiotu), liczbaNauczycieli(liczbaNauczycieli),
                                             cenaZaGodzine(cenaZaGodzine) {}

Przedmiot::~Przedmiot() {

}

int Przedmiot::getCenaZaMaterialyDydaktyczne() const {
    return cenaZaMaterialyDydaktyczne;
}

const std::string &Przedmiot::getNazwaPrzedmiotu() const {
    return nazwaPrzedmiotu;
}

int Przedmiot::getLiczbaNauczycieli() const {
    return liczbaNauczycieli;
}

double Przedmiot::getCenaZaGodzine() const {
    return cenaZaGodzine;
}

std::string Przedmiot::getInfo() {
    return "Przedmiot "+getNazwaPrzedmiotu()+", cena za godzinę: "+std::to_string(getCenaZaGodzine())+", cena za materiały: "+std::to_string(getCenaZaMaterialyDydaktyczne())+", liczba nauczycieli: "+std::to_string(getLiczbaNauczycieli());
}

void Przedmiot::setLiczbaNauczycieli(int nowaLiczbaNauczycieli) {
    Przedmiot::liczbaNauczycieli = nowaLiczbaNauczycieli;
}
