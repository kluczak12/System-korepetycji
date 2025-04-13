#ifndef CARRENTAL_JEZYKI_H
#define CARRENTAL_JEZYKI_H


#include "Przedmiot.h"

enum class PoziomJezyka {
    A1=10,
    A2=20,
    B1=30,
    B2=40,
    C1=50,
    C2=60
};

class Jezyki: public Przedmiot{
private:
    PoziomJezyka poziom;
    float cenaZaNative;
public:
    double kosztGodzinyKorepetycji() override;

    std::string getInfo() override;

    float getCenaZaNative() const;

    Jezyki(int cenaZaMaterialyDydaktyczne, const std::string &nazwaPrzedmiotu, int liczbaNauczycieli,
           double cenaZaGodzine, PoziomJezyka poziom, float cenaZaNative);

    ~Jezyki() override;

    PoziomJezyka getPoziom() const;

    void setPoziom(PoziomJezyka poziom);

    std::string nazwaPoziomu(PoziomJezyka poziom) const;
};


#endif //CARRENTAL_JEZYKI_H
