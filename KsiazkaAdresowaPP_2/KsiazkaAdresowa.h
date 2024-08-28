#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer *adresatMenedzer;
    MetodyPomocnicze metodyPomocnicze;
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    const string NAZWA_PLIKU_TYMCZASOWEGO_Z_ADRESATAMI;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami, string nazwaPlikuTymczasowegoZAdresatami)
        : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami), NAZWA_PLIKU_TYMCZASOWEGO_Z_ADRESATAMI(nazwaPlikuTymczasowegoZAdresatami)
    {
        adresatMenedzer = NULL;
    };

    ~KsiazkaAdresowa()
    {
        delete adresatMenedzer;
        adresatMenedzer = NULL;
    };

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanieUzytkownika();
    bool czyUzytkownikJestZalogowany();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
    void usunAdresata();
    void edytujAdresata();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();

};

#endif //KSIAZKAADRESOWA_H
