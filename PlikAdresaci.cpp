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
#include "Adresat.h"
#include "PlikAdresaci.h"

using namespace std;

void PlikAdresaci::wczytywanieAdresatowZPliku (vector <Adresat> &adresaci, Uzytkownicy uzytkownik)
{
    string wczytywanaLinia ;
    Adresat adresat;
    int numerLinii = 1;
    int idKontaktu;
    fstream plikZAdresami;
    plikZAdresami.open("Adresaci.txt", ios::in);
    if (plikZAdresami.good()) {
        while (getline(plikZAdresami, wczytywanaLinia)) {
            for (int i = 0; i < 2; i++) {
                size_t pozycja = wczytywanaLinia.find('|');
                {
                    string bufor = wczytywanaLinia.substr(0, pozycja);
                    wczytywanaLinia.erase(0, pozycja + 1);
                    if (i == 0) idKontaktu = atoi(bufor.c_str());
                    else if (i == 1 && uzytkownik.pobierzIdZalogowanegoUzytkownika() == atoi(bufor.c_str())) {
                        adresat.ustawIdAdresata(idKontaktu);
                        adresat.ustawIdUzytkownika(atoi(bufor.c_str()));
                        for (int j = 0; j <5; j++) {
                            size_t pozycja = wczytywanaLinia.find('|');
                            bufor = wczytywanaLinia.substr(0, pozycja);
                            wczytywanaLinia.erase(0, pozycja + 1);
                            if(j == 0) adresat.ustawImie(bufor);
                            else if (j == 1) adresat.ustawNazwisko(bufor);
                            else if (j == 2)  adresat.ustawNumerTelefonu(bufor);
                            else if (j == 3)  adresat.ustawEmail(bufor);
                            else if (j == 4)  adresat.ustawAdres(bufor);
                        }
                        adresaci.push_back(adresat);
                    }
                }
            }
            ++numerLinii;
        }
        plikZAdresami.close();
    } else cout << "Problemy z otwarciem pliku ";
}


void PlikAdresaci::dopiszAdresataDoPliku (Adresat adresat)
{
    fstream plikZAdresami;
    plikZAdresami.open("Adresaci.txt", ios::out|ios::app);
    if (plikZAdresami.good()) {
        plikZAdresami << adresat.pobierzIdAdresata() << "|";
        plikZAdresami << adresat.pobierzIdUzytkownika() << "|";
        plikZAdresami << adresat.pobierzImie() << "|";
        plikZAdresami << adresat.pobierzNazwisko() << "|";
        plikZAdresami << adresat.pobierzNumerTelefonu() << "|";
        plikZAdresami << adresat.pobierzEmail() << "|";
        plikZAdresami << adresat.pobierzAdres() << endl;
        plikZAdresami.close();
    } else cout << "Problemy z otwarciem pliku ";
}

void PlikAdresaci::usuwanieAdresataZPliku (int idDoUsuniecia)
{
    string wczytywanaLinia = "";
    int nrLinii = 1;
    fstream plikZAdresami;
    fstream plikTymczasowy;
    plikZAdresami.open("Adresaci.txt", ios::in);
    if (plikZAdresami.good()) {
        while (getline(plikZAdresami, wczytywanaLinia)) {
            size_t pozycja = wczytywanaLinia.find('|');
            string bufor = wczytywanaLinia.substr(0, pozycja);
            if (idDoUsuniecia != atoi(bufor.c_str())) {
                plikTymczasowy.open("Adresaci.tymczasowy.txt", ios :: out | ios :: app);
                plikTymczasowy << wczytywanaLinia <<endl;
                plikTymczasowy.close();
            }
            nrLinii++;
        }
        plikZAdresami.close();
        remove("Adresaci.txt");
        rename("Adresaci.tymczasowy.txt", "Adresaci.txt");
    } else cout << "Wystapil problem z otwarciem pliku. " <<endl;
}

void PlikAdresaci::wprowadzanieZminaAdresataWPliku (Adresat adresat)
{
    string wczytywanaLinia = "";
    int nrLinii = 1;
    fstream plikZAdresami;
    fstream plikTymczasowy;
    plikZAdresami.open("Adresaci.txt", ios::in);
    if (plikZAdresami.good()) {
        while (getline(plikZAdresami, wczytywanaLinia)) {
            size_t pozycja = wczytywanaLinia.find('|');
            string bufor = wczytywanaLinia.substr(0, pozycja);
            if (adresat.pobierzIdAdresata() != atoi(bufor.c_str())) {
                plikTymczasowy.open("Adresaci.tymczasowy.txt", ios :: out | ios :: app);
                plikTymczasowy << wczytywanaLinia <<endl;
                plikTymczasowy.close();
            } else if (adresat.pobierzIdAdresata()  == atoi(bufor.c_str())) {
                plikTymczasowy.open("Adresaci.tymczasowy.txt", ios :: out | ios :: app);
                plikTymczasowy << adresat.pobierzIdAdresata() << "|";
                plikTymczasowy << adresat.pobierzIdUzytkownika() << "|";
                plikTymczasowy << adresat.pobierzImie() << "|";
                plikTymczasowy << adresat.pobierzNazwisko() << "|";
                plikTymczasowy << adresat.pobierzNumerTelefonu() << "|";
                plikTymczasowy << adresat.pobierzEmail() << "|";
                plikTymczasowy << adresat.pobierzAdres() << endl;
                plikTymczasowy.close();
            }
            nrLinii++;
        }
        plikZAdresami.close();
        remove("Adresaci.txt");
        rename("Adresaci.tymczasowy.txt", "Adresaci.txt");
    } else cout << "Wystapil problem z otwarciem pliku. " <<endl;
}
