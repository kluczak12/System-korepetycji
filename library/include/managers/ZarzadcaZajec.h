#ifndef CARRENTAL_ZARZADCAZAJEC_H
#define CARRENTAL_ZARZADCAZAJEC_H

#include "repositories/ZajeciaRepozytorium.h"
#include "model/Zajecia.h"

class ZarzadcaZajec {
private:
    ZajeciaRepozytoriumPtr aktualneZajecia;
    ZajeciaRepozytoriumPtr archiwumZajec;
public:
    ZarzadcaZajec(const ZajeciaRepozytoriumPtr &aktualneZajecia, const ZajeciaRepozytoriumPtr &archiwumZajec);

    virtual ~ZarzadcaZajec();

    std::vector<ZajeciaPtr> znajdzAktualneZajecia();

    std::vector<ZajeciaPtr> znajdzZajeciaZArchiwum();

    bool dezaktywujZajecia(const ZajeciaPtr &zajecia);

    ZajeciaPtr stworzZajecia(const pt::ptime &czasRozpoczecia, unsigned int id, const UczenPtr &uczen, const PrzedmiotPtr &przedmiot);

};


#endif //CARRENTAL_ZARZADCAZAJEC_H
