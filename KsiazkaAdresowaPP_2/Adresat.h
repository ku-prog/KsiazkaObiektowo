#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>
using namespace std;

class Adresat
{
    int id = 0, idUzytkownika = 0;
    string imie = "", nazwisko = "", nrTelefonu = "", email = "", adres = "";

    public:
        void ustawId(int noweId);
        void ustawIdUzytkownika(int noweIdUzytkownika);
        void ustawImie(string noweImie);
        void ustawNazwisko(string noweNazwisko);
        void ustawNrTelefonu(string nowyNrTelefonu);
        void ustawEmail(string nowyEmail);
        void ustawAdres(string nowyAdres);

        int pobierzId();
        int pobierzIdUzytkownika();
        string pobierzImie();
        string pobierzNazwisko();
        string pobierzNrTelefonu();
        string pobierzEmail();
        string pobierzAdres();


};

#endif // ADRESAT_H
