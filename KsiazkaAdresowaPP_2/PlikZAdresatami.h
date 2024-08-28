#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <vector>
#include <fstream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

class PlikZAdresatami
{
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    const string NAZWA_PLIKU_TYMCZASOWEGO_Z_ADRESATAMI;
    int idOstatniegoAdresata;
    int idUsuwanegoAdresata;
    MetodyPomocnicze metodyPomocnicze;
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    bool czyPlikJestPusty(fstream &plikTekstowy);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);
    int pobierzZPlikuIdOstatniegoAdresata();


    public:
    PlikZAdresatami(string nazwaPlikuZAdresatami, string nazwaPlikuTymczasowegoZAdresatami)
    : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami), NAZWA_PLIKU_TYMCZASOWEGO_Z_ADRESATAMI(nazwaPlikuTymczasowegoZAdresatami)
    {
        idOstatniegoAdresata = 0;
    };



    int idZalogowanegoUzytkownika;

    vector<Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void dopiszAdresataDoPliku(Adresat adresat);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    void usunWybranaLinieWPliku(int numerUsuwanejLinii);
    void podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata();
    void edytujWybranaLinieWPliku(int numerEdytowanejLinii, string liniaZDanymiAdresataOddzielonePionowymiKreskami);
    void ustawIdOstatniegoAdresata(int noweIdOstatniegoAdresata);
    void ustawIdUsuwanegoAdresata(int noweIdUsuwanegoAdresata);
    int pobierzIdUsuwanegoAdresata();
    int pobierzIdOstatniegoAdresata();
};

#endif // PLIKZADRESATAMI_H
