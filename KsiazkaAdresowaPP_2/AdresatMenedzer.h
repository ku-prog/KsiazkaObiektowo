#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "PlikZAdresatami.h"


using namespace std;

class AdresatMenedzer
{

    vector<Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    MetodyPomocnicze metodyPomocnicze;

    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);
    int podajIdWybranegoAdresata();
    char wybierzOpcjeZMenuEdycja();
    void zaktualizujDaneWybranegoAdresata(Adresat adresat, int idEdytowanegoAdresata);

    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami, string nazwaPlikuTymczasowegoZAdresatami, int idZalogowanegoUzytkownika)
        : plikZAdresatami(nazwaPlikuZAdresatami, nazwaPlikuTymczasowegoZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };

    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void usunAdresata();
    void zaktualizujIdOstatniegoAdresataPoUsunieciuAdresata();
    void edytujAdresata();
    void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
};

#endif // ADRESATMENEDZER_H
