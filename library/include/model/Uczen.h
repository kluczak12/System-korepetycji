#ifndef CARRENTAL_UCZEN_H
#define CARRENTAL_UCZEN_H
#include <string>
#include <vector>
#include "typedefs.h"

class Uczen {
private:
    std::string imieUcznia;
    std::string nazwiskoUcznia;
    std::string poziomEdukacji;
    std::string adresEmail;
    unsigned int idUcznia;
public:
    virtual ~Uczen();

    std::string getInfo();

    Uczen(const std::string &imieUcznia, const std::string &nazwiskoUcznia, const std::string &poziomEdukacji,
          const std::string &adresEmail, unsigned int idUcznia);

    const std::string &getImieUcznia() const;

    const std::string &getNazwiskoUcznia() const;

    const std::string &getPoziomEdukacji() const;

    const std::string &getAdresEmail() const;

    unsigned int getIdUcznia() const;

    void setPoziomEdukacji(const std::string &poziomEdukacji);

};


#endif //CARRENTAL_UCZEN_H