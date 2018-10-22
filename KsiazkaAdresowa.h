#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Uzytkownik.h"
#include "Uzytkownicy.h"
#include "PlikUzytkownicy.h"
#include "Adresat.h"
#include "PlikAdresaci.h"
#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

using namespace std;

class KsiazkaAdresowa
{
    vector <Adresat> adresaci;
    PlikAdresaci plikAdresaci;

public:
    KsiazkaAdresowa();
    virtual ~KsiazkaAdresowa();
    void wczytanieKontaktowDoWektora(Uzytkownicy uzytkownik);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string &tekst);
    void nadanieIdKontkatu (int & idNowegoKontaktu);
    void wprowadzNowyKontakt (int idZalogowanegoUzytkownika);
    void wyszukajKontaktPoImieniu ();
    void wyszukajKontaktPoNazwisku ();
    void wyswietlWszystkieKontakty ();
    void zmianaDaychKontakowych ();
    void usuwanieKontaktu ();
};






#endif
