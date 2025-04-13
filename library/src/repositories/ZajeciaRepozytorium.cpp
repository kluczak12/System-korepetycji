#include "repositories/ZajeciaRepozytorium.h"
#include "model/Zajecia.h"
#include <algorithm>
#include <stdexcept>

void ZajeciaRepozytorium::dodajZajecia(ZajeciaPtr korepetycje) {
    if(korepetycje != nullptr)
    {
        zajecia.push_back(korepetycje);
    }
}

void ZajeciaRepozytorium::usunZajecia(ZajeciaPtr korepetycje) {
    zajecia.erase(std::remove(zajecia.begin(), zajecia.end(), korepetycje), zajecia.end());
}

int ZajeciaRepozytorium::liczbaZajec() const {
    return zajecia.size();
}

ZajeciaRepozytorium::~ZajeciaRepozytorium() {

}

std::vector<ZajeciaPtr> ZajeciaRepozytorium::znajdz(ZajeciaPredicate predicate) {
    std::vector<ZajeciaPtr > znalezione;
    for(unsigned int i=0; i<zajecia.size(); i++)
    {
        ZajeciaPtr obiekt = zajecia[i];
        if(obiekt != nullptr && predicate(obiekt))
        {
            znalezione.push_back(obiekt);
        }
    }
    return znalezione;
}

ZajeciaPtr ZajeciaRepozytorium::znajdzPoIdZajec(const unsigned int Id) {
    std::vector<ZajeciaPtr > znalezione = znajdz([Id](ZajeciaPtr korepetycje) {
        return korepetycje->getId() == Id;
    });
    if (!znalezione.empty()) {
        return znalezione.front();
    }
    throw std::runtime_error("Zajęcia o podanym Id nie istnieją.");
}

ZajeciaRepozytorium::ZajeciaRepozytorium() {}


