#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#ifndef UZYTKOWNICY_H
#define UZYTKOWNICY_H
#include "PlikUzytkownicy.h"
#include "Uzytkownik.h"


using namespace std;

class Uzytkownicy {
    vector<Uzytkownik> uzytkownicy;
    int idZalogowanegoUzytkownika;
    PlikUzytkownicy plikUzytkownicy;

public:

    Uzytkownicy();
    virtual ~Uzytkownicy();

    int pobierzIdZalogowanegoUzytkownika();
    void ustawIdZalogowengoUzytkownika(int idZalogowanegoUzytkownia);

    void zaloguj ();
    void rejestruj ();
    void zmienHaslo();
    void wyloguj();

};

#endif
