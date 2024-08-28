#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>

//#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikMenedzer
{

    vector<Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;
    MetodyPomocnicze metodyPomocnicze;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    int idZalogowanegoUzytkownika;


public:
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami): plikZUzytkownikami(nazwaPlikuZUzytkownikami)
    {
        idZalogowanegoUzytkownika = 0;
        uzytkownicy = plikZUzytkownikami.wczytajPlikZUzytkownikami();
    };

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanieUzytkownika();
    bool czyUzytkownikJestZalogowany();
    int pobierzIdZalogowanegoUzytkownika();
    void ustawIdZalogowanegoUzytkownika(int noweId);


};
#endif // UZYTKOWNIKMENEDZER_H
