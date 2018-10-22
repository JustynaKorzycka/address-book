#include <iostream>
#include <vector>
#include "Uzytkownik.h"
#include "Uzytkownicy.h"
#include "PlikUzytkownicy.h"
#include <fstream>
#include <cstdlib>
#include <windows.h>

using namespace std;

Uzytkownicy::Uzytkownicy() {
    this-> idZalogowanegoUzytkownika = 0;
    plikUzytkownicy.wczytajUzytkownikowZPliku(uzytkownicy);
}
Uzytkownicy::~Uzytkownicy() {
    uzytkownicy.clear();
}

int Uzytkownicy :: pobierzIdZalogowanegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}

void Uzytkownicy :: ustawIdZalogowengoUzytkownika(int idZalogowanegoUzytkownika) {
    this->idZalogowanegoUzytkownika = idZalogowanegoUzytkownika;
}

void Uzytkownicy :: zaloguj () {
    string podanyLogin = "";
    string podaneHaslo = "";
    bool czyIstnieje = false;
    int iloscProb = 3;
    cout << "Podaj login: ";
    cin >> podanyLogin;
    for (vector <Uzytkownik> :: iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); ++itr) {
        if (itr -> Uzytkownik::pobierzLogin() == podanyLogin) {
            czyIstnieje = true;
            while (iloscProb > 0)  {
                cout << "Podaj haslo. Pozostalo prob " << iloscProb << " : ";
                cin >> podaneHaslo;
                if (itr -> Uzytkownik::pobierzHaslo() == podaneHaslo) {
                    this->idZalogowanegoUzytkownika = itr ->Uzytkownik::pobierzId();

                    cout << "Witaj w swojej ksiazce adresowej!";
                    Sleep (1000);
                    break;
                }
                iloscProb --;
            }
            if (iloscProb == 0) {
                cout << "Niepoprawne logowanie";
                Sleep(1000);
                break;
            }
        }
    }
    if (czyIstnieje == false) cout << "Nie ma takiego uzytkownika";
    Sleep(1000);
}
void Uzytkownicy :: rejestruj () {
    string podanyLogin, podaneHaslo;
    int iloscUzytkownikow = uzytkownicy.size();
    getchar();
    Uzytkownik uzytkownik;
    cout << "Wprowadz nazwe uzytkownika: ";
    cin >> podanyLogin;

    for (vector <Uzytkownik> :: iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); ++itr) {
        if (itr -> pobierzLogin() == podanyLogin) {
            cout << "Wprowadzona nazwa jest juz zajeta. Podaj inna nazwe uzytkownika: ";
            cin >> podanyLogin;
        }
    }
    uzytkownik.ustawLogin(podanyLogin);
    cout << "Podaj haslo: ";
    cin >> podaneHaslo;
    uzytkownik.ustawHaslo(podaneHaslo);
    getchar();
    if (iloscUzytkownikow == 0) uzytkownik.ustawId(1);
    else if (iloscUzytkownikow != 0) uzytkownik.ustawId(uzytkownicy.back().pobierzId() + 1);
    plikUzytkownicy.dopiszUzytkownikaDoPliku (uzytkownik);
    uzytkownicy.push_back(uzytkownik);
    cout << "Konto zostalo pomysle zalozone." << endl;
    Sleep (1000);
}

void Uzytkownicy :: zmienHaslo() {
    string login, noweHaslo, stareHaslo;
    int czyIsnieje = 0;
    cout << "Podaj login: ";
    cin >> login;
    for (vector <Uzytkownik> :: iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); ++itr) {
        if (itr -> pobierzLogin() == login) {
            czyIsnieje ++;
            cout << "Podaj haslo: ";
            cin >> stareHaslo;
            if (itr -> pobierzHaslo() == stareHaslo) {
                cout << "Podaj nowe haslo: ";
                cin >> noweHaslo;
                itr -> ustawHaslo(noweHaslo);
                plikUzytkownicy.aktualizujDaneUzytkownikow (uzytkownicy);
                cout<<"Haslo zostalo zmienione";
                Sleep(1000);
                break;
            } else cout << "Niepoprawne haslo" <<endl;
            Sleep(1000);
        }
    }
    if (czyIsnieje == 0) cout << "Taki uzytkownik nie istnieje.";
    Sleep(1000);
}

void Uzytkownicy :: wyloguj() {
    ustawIdZalogowengoUzytkownika(0);
}

