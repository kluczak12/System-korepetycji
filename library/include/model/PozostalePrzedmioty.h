#ifndef CARRENTAL_POZOSTALEPRZEDMIOTY_H
#define CARRENTAL_POZOSTALEPRZEDMIOTY_H

#include "Przedmiot.h"

class PozostalePrzedmioty: public Przedmiot {
private:
    bool korepetycjeGrupowe;
public:
    bool isKorepetycjeGrupowe() const;

    double kosztGodzinyKorepetycji() override;

    std::string getInfo() override;

    PozostalePrzedmioty(int cenaZaMaterialyDydaktyczne, const std::string &nazwaPrzedmiotu, int liczbaNauczycieli,
                        double cenaZaGodzine, bool korepetycjeGrupowe);

    ~PozostalePrzedmioty() override;
};


#endif //CARRENTAL_POZOSTALEPRZEDMIOTY_H
