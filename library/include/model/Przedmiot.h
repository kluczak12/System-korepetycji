#ifndef CARRENTAL_PRZEDMIOT_H
#define CARRENTAL_PRZEDMIOT_H

#include <string>
#include "Zajecia.h"

class Przedmiot{
private:
    int cenaZaMaterialyDydaktyczne;
    std::string nazwaPrzedmiotu;
    int liczbaNauczycieli;
    double cenaZaGodzine;
public:
    Przedmiot(int cenaZaMaterialyDydaktyczne, const std::string &nazwaPrzedmiotu, int liczbaNauczycieli,
              double cenaZaGodzine);

    virtual ~Przedmiot();

    int getCenaZaMaterialyDydaktyczne() const;

    const std::string &getNazwaPrzedmiotu() const;

    int getLiczbaNauczycieli() const;

    double getCenaZaGodzine() const;

    virtual double kosztGodzinyKorepetycji() = 0;

    virtual std::string getInfo();

    void setLiczbaNauczycieli(int nowaLiczbaNauczycieli);
};


#endif //CARRENTAL_PRZEDMIOT_H
