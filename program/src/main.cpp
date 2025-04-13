#include <iostream>
#include "model/Uczen.h"
#include "model/Zajecia.h"
#include "typedefs.h"
#include "model/Jezyki.h"
#include "model/PozostalePrzedmioty.h"
#include "managers/ZarzadcaUczniow.h"
#include "managers/ZarzadcaZajec.h"

using namespace std;

int main()
{
    char wybor;
    string imieKlienta, nazwiskoKlienta, poziomEdukacjiKlienta, emailKlienta, NazwaPrzedmiotuKlienta;

    cout<<"Witaj na platformie z korepetycjami! Rozpocznij rejestracje.\nPodaj swoje imię: ";
    cin>>imieKlienta;
    cout<<"\nPodaj swoje nazwisko: ";
    cin>>nazwiskoKlienta;
    cout<<"\nPodaj poziom edukacji: ";
    cin>>poziomEdukacjiKlienta;
    cout<<"\nPodaj swoj adres email: ";
    cin>>emailKlienta;
    cout<<"\nPodaj nazwe przedmiotu: ";
    cin>>NazwaPrzedmiotuKlienta;

    ZarzadcaUczniow zarzadcaUczniowMainowy(std::make_shared<UczenRepozytorium>(), std::make_shared<UczenRepozytorium>());
    UczenPtr uczenMainowy1;
    ZarzadcaZajec zarzadcaZajecMainowy(std::make_shared<ZajeciaRepozytorium>(), std::make_shared<ZajeciaRepozytorium>());
    ZajeciaPtr zajeciaMainowe1;
    ZajeciaPtr zajeciaMainowe2;
    uczenMainowy1=zarzadcaUczniowMainowy.zarejestrujUcznia(imieKlienta, nazwiskoKlienta, poziomEdukacjiKlienta, emailKlienta, 111);


    cout<<"\nStworzmy korepetycje. Czy uczysz sie jezyka? t-tak: ";
    cin>>wybor;
    if(wybor=='t')
    {
        PrzedmiotPtr przedmiotMainowy1(std::make_shared<Jezyki>(50, NazwaPrzedmiotuKlienta, 10, 80, PoziomJezyka::A1, 50.0));
        zajeciaMainowe1=zarzadcaZajecMainowy.stworzZajecia(pt::time_from_string("2024-06-13 12:00:00"), 8, uczenMainowy1, przedmiotMainowy1);
        cout<<uczenMainowy1->getInfo()<<endl<<zajeciaMainowe1->getInfo();;
        zajeciaMainowe1->zakonczZajecia(pt::time_from_string("2024-06-13 14:00:00"));
        zarzadcaZajecMainowy.dezaktywujZajecia(zajeciaMainowe1);
        cout<<"\nKoszt zajęć wynosi: "<<zajeciaMainowe1->getKosztZajec();
    }
    else
    {
        bool czyKorepetycjeGrupoweKlienta=false;
        wybor=0;
        cout<<"\nCzy chcesz uczestniczyć w korepetycjach grupowych? t-tak: ";
        cin>>wybor;
        if(wybor=='t')
        {
            czyKorepetycjeGrupoweKlienta=true;
        }
        PrzedmiotPtr przedmiotMainowy2(std::make_shared<PozostalePrzedmioty>(20, NazwaPrzedmiotuKlienta, 2, 130, czyKorepetycjeGrupoweKlienta));
        zajeciaMainowe2=zarzadcaZajecMainowy.stworzZajecia(pt::time_from_string("2024-06-13 12:00:00"), 10, uczenMainowy1, przedmiotMainowy2);
        cout<<uczenMainowy1->getInfo()<<endl<<zajeciaMainowe2->getInfo();
        zajeciaMainowe1->zakonczZajecia(pt::time_from_string("2024-06-13 14:00:00"));
        zarzadcaZajecMainowy.dezaktywujZajecia(zajeciaMainowe2);
        cout<<"\nKoszt zajęć wynosi: "<<zajeciaMainowe2->getKosztZajec();
    }

    return 0;
}