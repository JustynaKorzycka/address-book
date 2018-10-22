#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Uzytkownik.h"
#include "Uzytkownicy.h"
#include "plikUzytkownicy.h"
#ifndef ADRESAT_H
#define ADRESAT_H

using namespace std;

class Adresat {
    int idAdresata, idZalogowanegoUzytkownika;
    string imie, nazwisko, numerTelefonu, email, adres;



public:
    Adresat();
    virtual ~Adresat();

    int pobierzIdAdresata();
    int pobierzIdUzytkownika();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzNumerTelefonu();
    string pobierzEmail();
    string pobierzAdres();


    void ustawIdAdresata(int idAdresta);
    void ustawIdUzytkownika(int idZalogowanegoUzytkownika);
    void ustawImie(string imie);
    void ustawNazwisko (string nazwisko);
    void ustawNumerTelefonu(string numerTelefonu);
    void ustawEmail (string email);
    void ustawAdres(string adres);

};
#endif
