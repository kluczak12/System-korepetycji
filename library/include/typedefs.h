#ifndef CARRENTAL_TYPEDEFS_H
#define CARRENTAL_TYPEDEFS_H
#include <memory>
#include <functional>

class Uczen;
class Zajecia;
class Przedmiot;
class UczenRepozytorium;
class PrzedmiotRepozytorium;
class ZajeciaRepozytorium;
class ZarzadcaUczniow;

typedef std::shared_ptr<Uczen> UczenPtr;
typedef std::shared_ptr<Zajecia> ZajeciaPtr;
typedef std::shared_ptr<Przedmiot> PrzedmiotPtr;

typedef std::function<bool(UczenPtr)> UczenPredicate;
typedef std::function<bool(ZajeciaPtr)> ZajeciaPredicate;
typedef std::function<bool(PrzedmiotPtr)> PrzedmiotPredicate;


typedef std::shared_ptr<UczenRepozytorium> UczenRepozytoriumPtr;
typedef std::shared_ptr<ZajeciaRepozytorium> ZajeciaRepozytoriumPtr;
typedef std::shared_ptr<PrzedmiotRepozytorium> PrzedmiotRepozytoriumPtr;

typedef std::shared_ptr<ZarzadcaUczniow> ZarzadcaUczniowPtr;

//typedef std::function<bool(UczenRepozytoriumPtr)> UczenRepozytoriumPredicate;
//typedef std::function<bool(ZajeciaRepozytoriumPtr)> ZajeciaRepozytoriumPredicate;
//typedef std::function<bool(PrzedmiotRepozytoriumPtr)> PrzedmiotRepozytoriumPredicate;

#endif //CARRENTAL_TYPEDEFS_H
