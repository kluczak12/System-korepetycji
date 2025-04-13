#ifndef CARRENTAL_UCZENREPOZYTORIUM_H
#define CARRENTAL_UCZENREPOZYTORIUM_H
#include "typedefs.h"
#include <vector>

class UczenRepozytorium {
private:
    std::vector<UczenPtr> uczniowie;
public:
    virtual ~UczenRepozytorium();

    void dodajUcznia(UczenPtr klient);

    void usunUcznia(UczenPtr klient);

    int liczbaUczniow();

    std::vector<UczenPtr> znajdz(UczenPredicate predicate);

    UczenPtr znajdzPrzezIdUcznia(const unsigned int idUcznia);

    UczenRepozytorium();
};
#endif //CARRENTAL_UCZENREPOZYTORIUM_H
