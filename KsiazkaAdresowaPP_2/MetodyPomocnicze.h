#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class MetodyPomocnicze
{
public:
    static string konwerjsaIntNaString(int liczba);
    string wczytajLinie();
    int konwersjaStringNaInt(string liczba);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    char wczytajZnak();
    int wczytajLiczbeCalkowita();
    int podajIdWybranegoAdresata();
};

#endif // METODYPOMOCNICZE_H
