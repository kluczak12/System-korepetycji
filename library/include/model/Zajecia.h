#ifndef CARRENTAL_ZAJECIA_H
#define CARRENTAL_ZAJECIA_H
#include <boost/date_time.hpp>
#include "typedefs.h"

namespace pt = boost::posix_time;

class Zajecia {
private:
    pt::ptime czasRozpoczecia;
    pt::ptime czasZakonczenia;
    unsigned int id;
    UczenPtr uczen;
    PrzedmiotPtr przedmiot;
    double kosztZajec;
public:
    virtual ~Zajecia();

    Zajecia(const pt::ptime &czasRozpoczecia, unsigned int id, const UczenPtr &uczen, const PrzedmiotPtr &przedmiot);

    const pt::ptime &getCzasRozpoczecia() const;

    unsigned int getId() const;

    const UczenPtr &getUczen() const;

    const PrzedmiotPtr &getPrzedmiot() const;

    double getKosztZajec() const;

    const pt::ptime &getCzasZakonczenia() const;

    std::string getInfo();

    void zakonczZajecia(const pt::ptime& czasZakonczenia);

    unsigned int czasZajec();

    void setKosztZajec(double nowykosztZajec);

    void setCzasZakonczenia(const pt::ptime &czasZakonczenia);

};

#endif //CARRENTAL_ZAJECIA_H
