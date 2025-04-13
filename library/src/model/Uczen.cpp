#include <string>
#include "model/Uczen.h"

Uczen::~Uczen() {

}

std::string Uczen::getInfo() {

    return "Uczen o imieniu i nazwisku: "+getImieUcznia()+" "+getNazwiskoUcznia()+", adres email: "+getAdresEmail()+", poziom edukacji: "+getPoziomEdukacji()+"\n";
}

Uczen::Uczen(const std::string &imieUcznia, const std::string &nazwiskoUcznia, const std::string &poziomEdukacji,
             const std::string &adresEmail, unsigned int idUcznia) : imieUcznia(imieUcznia),
                                                                     nazwiskoUcznia(nazwiskoUcznia),
                                                                     poziomEdukacji(poziomEdukacji),
                                                                     adresEmail(adresEmail), idUcznia(idUcznia) {}

const std::string &Uczen::getImieUcznia() const {
    return imieUcznia;
}

const std::string &Uczen::getNazwiskoUcznia() const {
    return nazwiskoUcznia;
}

const std::string &Uczen::getPoziomEdukacji() const {
    return poziomEdukacji;
}

const std::string &Uczen::getAdresEmail() const {
    return adresEmail;
}

unsigned int Uczen::getIdUcznia() const {
    return idUcznia;
}

void Uczen::setPoziomEdukacji(const std::string &poziomEdukacjiCpp) {
    Uczen::poziomEdukacji = poziomEdukacjiCpp;
}
