#ifndef CARRENTAL_ZARZADCAUCZNIOW_H
#define CARRENTAL_ZARZADCAUCZNIOW_H
#include "typedefs.h"

#include "repositories/UczenRepozytorium.h"

class ZarzadcaUczniow {
private:
    UczenRepozytoriumPtr aktualnySpisUczniow;
    UczenRepozytoriumPtr archiwumUczniow;
public:
    ZarzadcaUczniow(const UczenRepozytoriumPtr &aktualnySpisUczniow, const UczenRepozytoriumPtr &archiwumUczniow);

    virtual ~ZarzadcaUczniow();

    std::vector<UczenPtr> znajdzAktualnychUczniow();

    std::vector<UczenPtr> znajdzUczniowZArchiwum();

    UczenPtr zarejestrujUcznia(const std::string &imieUcznia, const std::string &nazwiskoUcznia,
                               const std::string &poziomEdukacji, const std::string &adresEmail, unsigned int idUcznia);

    bool usunKontoUcznia(const UczenPtr &uczen);

};


#endif //CARRENTAL_ZARZADCAUCZNIOW_H
