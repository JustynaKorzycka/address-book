#include <iostream>
#include <vector>
#include "Uzytkownik.h"
#include "PlikUzytkownicy.h"
#include "Adresat.h"
#include <fstream>
#include <cstdlib>
#include <windows.h>

using namespace std;

void PlikUzytkownicy:: wczytajUzytkownikowZPliku (vector <Uzytkownik> &uzytkownicy) {
    Uzytkownik uzytkownik;
    fstream plikZUzytkownikami;
    string wczytywanaLinia = "";
    int numerLinii;
    plikZUzytkownikami.open("Uzytkownicy.txt", ios :: in);
    if (plikZUzytkownikami.good() == true) {
        while (getline(plikZUzytkownikami, wczytywanaLinia)) {
            for (int i = 0; i < 3; i++) {
                size_t pozycja = wczytywanaLinia.find('|');
                {
                    string bufor = wczytywanaLinia.substr(0, pozycja);
                    wczytywanaLinia.erase(0, pozycja + 1);
                    if (i == 0) uzytkownik.ustawId( atoi(bufor.c_str()));
                    else if(i == 1) uzytkownik.ustawLogin(bufor);
                    else if (i == 2) uzytkownik.ustawHaslo(bufor);
                }
            }
            uzytkownicy.push_back(uzytkownik);
            ++numerLinii;
        }
        plikZUzytkownikami.close();
    } else cout << "Problemy z otwarciem pliku ";
}

void PlikUzytkownicy :: aktualizujDaneUzytkownikow (vector <Uzytkownik> &uzytkownicy) {
    string bufor;
    fstream plikZAdresami;
    plikZAdresami.open("Uzytkownicy.txt", ios::out | ios :: trunc);
    ofstream plik( "Uzytkownicy.txt" );
    if (plikZAdresami.good()) {
        for (vector <Uzytkownik> :: iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); ++itr) {
            plikZAdresami << itr -> pobierzId() << "|";
            plikZAdresami << itr -> pobierzLogin() << "|";
            plikZAdresami << itr -> pobierzHaslo() << endl;
        }
        plikZAdresami.close();
    } else cout << "Wystapil problem z otwarciem pliku. " <<endl;
}

void PlikUzytkownicy :: dopiszUzytkownikaDoPliku (Uzytkownik uzytkownik) {
    fstream plikZUzytkownikami;
    plikZUzytkownikami.open("Uzytkownicy.txt", ios::out|ios::app);
    if (plikZUzytkownikami.good()) {
        plikZUzytkownikami << uzytkownik.pobierzId() << "|";
        plikZUzytkownikami << uzytkownik.pobierzLogin() << "|";
        plikZUzytkownikami << uzytkownik.pobierzHaslo() << endl;
        plikZUzytkownikami.close();
    } else cout << "Problemy z otwarciem pliku ";
}
