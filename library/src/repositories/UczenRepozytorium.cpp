#include "repositories/UczenRepozytorium.h"
#include <algorithm>
#include <stdexcept>
#include "model/Uczen.h"

UczenRepozytorium::~UczenRepozytorium() {

}

void UczenRepozytorium::dodajUcznia(UczenPtr klient) {
    if(klient != nullptr)
    {
        uczniowie.push_back(klient);
    }
}

void UczenRepozytorium::usunUcznia(UczenPtr klient) {
    uczniowie.erase(std::remove(uczniowie.begin(), uczniowie.end(), klient), uczniowie.end());
}

std::vector<UczenPtr> UczenRepozytorium::znajdz(UczenPredicate predicate) {
    std::vector<UczenPtr> znalezione;
    for(int i=0; i<liczbaUczniow(); i++)
    {
        UczenPtr obiekt = uczniowie[i];
        if(obiekt != nullptr && predicate(obiekt))
        {
            znalezione.push_back(obiekt);
        }
    }
    return znalezione;
}

UczenPtr UczenRepozytorium::znajdzPrzezIdUcznia(const unsigned int idUcznia) {
    std::vector<UczenPtr> znalezione = znajdz([idUcznia](UczenPtr uczen) {
        return uczen->getIdUcznia() == idUcznia;
    });
    if (!znalezione.empty()) {
        return znalezione.front();
    }
    throw std::runtime_error("Uczen o podanym Id nie istnieje.");
}

int UczenRepozytorium::liczbaUczniow() {
    return uczniowie.size();
}

UczenRepozytorium::UczenRepozytorium() {}
