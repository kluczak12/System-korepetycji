#ifndef CARRENTAL_ZAJECIAREPOZYTORIUM_H
#define CARRENTAL_ZAJECIAREPOZYTORIUM_H
#include "typedefs.h"
#include <vector>

class ZajeciaRepozytorium {
private:
    std::vector<ZajeciaPtr> zajecia;
public:
    void dodajZajecia(ZajeciaPtr korepetycje);

    void usunZajecia(ZajeciaPtr korepetycje);

    int liczbaZajec() const;

    virtual ~ZajeciaRepozytorium();

    std::vector<ZajeciaPtr> znajdz(ZajeciaPredicate predicate);

    ZajeciaPtr znajdzPoIdZajec(const unsigned int Id);

    ZajeciaRepozytorium();
};


#endif //CARRENTAL_ZAJECIAREPOZYTORIUM_H
