#include "UzytkownikMenedzer.h"


void UzytkownikMenedzer::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}


bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{
    for (size_t i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            cout << "Istnieje uzytkwonik z podanym loginem" << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow()
{
    for (size_t i = 0; i < uzytkownicy.size(); i++)
    {
        cout << "ID uzytkownika: " << uzytkownicy[i].pobierzId() << endl;
        cout << "Login uzytkownika: " << uzytkownicy[i].pobierzLogin() << endl;
        cout << "Haslo uzytkownika: " << uzytkownicy[i].pobierzHaslo() << endl;
    }
}


Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    //uzytkownik.id = pobierzIdNowegoUzytkownika(uzytkownicy);
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login;

    do
    {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    //uzytkownik.haslo = wczytajLinie();
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}



int UzytkownikMenedzer::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    cin >> login;
    uzytkownik.ustawLogin(login);

    for (size_t i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                cin >> haslo;
                uzytkownik.ustawHaslo(haslo);
                //haslo = metodyPomocnicze.wczytajLinie();

                if (uzytkownicy[i].pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();
                    return idZalogowanegoUzytkownika;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }

    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}


void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika()
{
    Uzytkownik uzytkownik;
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    cin >> noweHaslo;
    //uzytkownik.ustawHaslo(noweHaslo);
    //noweHaslo = metodyPomocnicze.wczytajLinie();

//    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
//    {
//        if (itr -> id == idZalogowanegoUzytkownika)
//        {
//            itr -> haslo = noweHaslo;
//            cout << "Haslo zostalo zmienione." << endl << endl;
//            system("pause");
//        }
//    }
    for (size_t i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzId() == idZalogowanegoUzytkownika)
        {
            uzytkownicy[i].ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

void UzytkownikMenedzer::ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika)
{
    idZalogowanegoUzytkownika = noweIdZalogowanegoUzytkownika;
}

void UzytkownikMenedzer::wylogowanieUzytkownika()
{
    idZalogowanegoUzytkownika = 0;
}

bool UzytkownikMenedzer::czyUzytkownikJestZalogowany()
{
    if (idZalogowanegoUzytkownika > 0)
        return true;
    else
        return false;
}
