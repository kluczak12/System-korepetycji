#include "model/Zajecia.h"
#include "model/Uczen.h"
#include "model/Przedmiot.h"
namespace pt = boost::posix_time;

Zajecia::~Zajecia() {

}

Zajecia::Zajecia(const pt::ptime &czasRozpoczecia, unsigned int id, const UczenPtr &uczen,
                 const PrzedmiotPtr &przedmiot) : czasRozpoczecia(czasRozpoczecia), id(id), uczen(uczen),
                                                  przedmiot(przedmiot) {}

const pt::ptime &Zajecia::getCzasRozpoczecia() const {
    return czasRozpoczecia;
}

unsigned int Zajecia::getId() const {
    return id;
}

const UczenPtr &Zajecia::getUczen() const {
    return uczen;
}

const PrzedmiotPtr &Zajecia::getPrzedmiot() const {
    return przedmiot;
}

double Zajecia::getKosztZajec() const {
    return kosztZajec;
}

const pt::ptime &Zajecia::getCzasZakonczenia() const {
    return czasZakonczenia;
}

std::string Zajecia::getInfo() {
    return "Informacje o zajęciach: "+getPrzedmiot()->getInfo()+ ", czas początku zajęć: "+boost::posix_time::to_simple_string(czasRozpoczecia)+std::to_string(getKosztZajec());
}

void Zajecia::zakonczZajecia(const pt::ptime &czasZakonczeniaCpp) {
    setCzasZakonczenia(czasZakonczeniaCpp);
    setKosztZajec((czasZajec()*getPrzedmiot()->kosztGodzinyKorepetycji()));
}


unsigned int Zajecia::czasZajec() {
    pt::time_duration czas = getCzasZakonczenia() - getCzasRozpoczecia();
    return czas.total_seconds()/3600;
}

void Zajecia::setKosztZajec(double nowyKosztZajec) {
    kosztZajec = nowyKosztZajec;
}

void Zajecia::setCzasZakonczenia(const pt::ptime &NowyCzasZakonczenia) {
    Zajecia::czasZakonczenia = NowyCzasZakonczenia;
}

