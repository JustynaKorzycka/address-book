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
#include "KsiazkaAdresowa.h"


using namespace std;

KsiazkaAdresowa:: KsiazkaAdresowa()
{
    ;
}
KsiazkaAdresowa:: ~KsiazkaAdresowa()
{
    ;
}

void KsiazkaAdresowa::wczytanieKontaktowDoWektora(Uzytkownicy uzytkownik)
{
    plikAdresaci.wczytywanieAdresatowZPliku(adresaci, uzytkownik);
}
string KsiazkaAdresowa:: zamienPierwszaLitereNaDuzaAPozostaleNaMale(string &tekst)
{
    if (!tekst.empty()) {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}
void  KsiazkaAdresowa::nadanieIdKontkatu (int &idNowegoKontaktu)
{
    fstream plikZAdresami;
    string wczytywanaLinia;
    string bufor1;

    plikZAdresami.open("Adresaci.txt", ios::in  );
    int dlugoscPliku = plikZAdresami.tellg()+1;
    if (dlugoscPliku == 0) idNowegoKontaktu = 1;
    else {
        while (getline(plikZAdresami, wczytywanaLinia)) {
            bufor1 = wczytywanaLinia;
        }
        size_t pozycja = bufor1.find('|');
        string bufor = bufor1.substr(0, pozycja);
        idNowegoKontaktu = atoi(bufor.c_str())+1;
    }
}
void KsiazkaAdresowa::wprowadzNowyKontakt (int idZalogowanegoUzytkownika)
{
    Adresat adresatPomocniczy;
    string imie, nazwisko, email, adres, numerTelefonu;
    int idNowegoKontaktu = 0;
    nadanieIdKontkatu(idNowegoKontaktu);
    adresatPomocniczy.ustawIdAdresata(idNowegoKontaktu);
    cout << "Podaj imie: ";
    cin >> imie;
    zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
    adresatPomocniczy.ustawImie(imie);
    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
    adresatPomocniczy.ustawNazwisko(nazwisko);
    cin.sync();
    cout << "Podaj adres: ";
    getline(cin,adres);
    adresatPomocniczy.ustawAdres(adres);
    cin.sync();
    cout << "Podaj numer telefonu: ";
    getline(cin, numerTelefonu);
    adresatPomocniczy.ustawNumerTelefonu(numerTelefonu);
    cout << "Podaj adres email: ";
    cin >> email;
    adresatPomocniczy.ustawEmail(email);
    adresatPomocniczy.ustawIdUzytkownika(idZalogowanegoUzytkownika);
    adresaci.push_back(adresatPomocniczy);
    plikAdresaci.dopiszAdresataDoPliku (adresatPomocniczy);
    cout << "Kontakt zostal zapisany.";
    Sleep(1000);
}
void KsiazkaAdresowa::wyszukajKontaktPoImieniu ()
{
    string imiePoszukiwanegoKontaktu;
    int iloscWyszukanychKontaktow = 0;
    if (! adresaci.empty()) {
        cout << "Podaj imie: ";
        cin >> imiePoszukiwanegoKontaktu;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); ++itr) {
            if (imiePoszukiwanegoKontaktu == itr ->Adresat::pobierzImie()) {
                cout << "---------------------- " << endl;
                cout << "Id:                " << itr -> Adresat::pobierzIdAdresata() << endl;
                cout << "Nazwisko:          " << itr -> Adresat::pobierzNazwisko() << endl;
                cout << "Adres:             " << itr -> Adresat::pobierzAdres() << endl;
                cout << "Numer telefonu:    " << itr -> Adresat::pobierzNumerTelefonu() << endl;
                cout << "Email:             " << itr -> Adresat::pobierzEmail() << endl;
                cout << endl;
                iloscWyszukanychKontaktow++;
            }
        }
        if (iloscWyszukanychKontaktow == 0) {
            cout << "Nie znaleziono kontaktu o takim imieniu." << endl;
        }
    } else cout << "Ksiazka adresowa jest pusta. " << endl;
    getch();
}
void KsiazkaAdresowa:: wyszukajKontaktPoNazwisku ()
{
    string nazwiskoPoszukiwanegoKontaktu;
    int iloscWyszukanychKontaktow = 0;
    if (! adresaci.empty()) {
        cout << "Podaj nazwisko: ";
        cin >> nazwiskoPoszukiwanegoKontaktu;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); ++itr) {
            if (nazwiskoPoszukiwanegoKontaktu == itr ->Adresat::pobierzNazwisko()) {
                cout << "---------------------- " << endl;
                cout << "Id:                " << itr -> Adresat::pobierzIdAdresata() << endl;
                cout << "Imie:              " << itr -> Adresat::pobierzImie() << endl;
                cout << "Adres:             " << itr -> Adresat::pobierzAdres() << endl;
                cout << "Numer telefonu:    " << itr -> Adresat::pobierzNumerTelefonu() << endl;
                cout << "Email:             " << itr -> Adresat::pobierzEmail() << endl;
                cout << endl;
                iloscWyszukanychKontaktow ++;
            }
        }
        if (iloscWyszukanychKontaktow == 0) {
            cout << "Nie znaleziono kontaktu o takim nazwisku." << endl;
        }
    } else cout << "Ksiazka adresowa jest pusta. " << endl;
    getch();
}

void KsiazkaAdresowa::wyswietlWszystkieKontakty()
{
    if (!adresaci.empty()) {
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {

                cout << "Id:                " << itr -> Adresat::pobierzIdAdresata() << endl;
                cout << "Imie:              " << itr -> Adresat::pobierzImie() << endl;
                cout << "Nazwisko:          " << itr -> Adresat::pobierzNazwisko() << endl;
                cout << "Adres:             " << itr -> Adresat::pobierzAdres() << endl;
                cout << "Numer telefonu:    " << itr -> Adresat::pobierzNumerTelefonu() << endl;
                cout << "Email:             " << itr -> Adresat::pobierzEmail() << endl;
                cout << endl;
        }
    } else cout << "Ksiazka adresowa jest pusta.";
    getch();
}

void KsiazkaAdresowa:: zmianaDaychKontakowych()
{
    int idWyszukiwanegoKontaktu;
    int czyIstniejeKontakt = false;
    Adresat adresatPomocniczy;
    cout << "Podaj id kontaktu: ";
    cin >> idWyszukiwanegoKontaktu;
    for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); ++itr) {
        if (idWyszukiwanegoKontaktu == itr ->Adresat::pobierzIdAdresata()) {
            czyIstniejeKontakt = true;
            cout << "Obecne dane kontaktowe: " << endl;
            cout << "------------------------------" << endl;
            cout << "Imie:              " << itr -> Adresat::pobierzImie() << endl;
            cout << "Nazwisko:          " << itr -> Adresat::pobierzNazwisko() << endl;
            cout << "Adres:             " << itr -> Adresat::pobierzAdres() << endl;
            cout << "Numer telefonu:    " << itr -> Adresat::pobierzNumerTelefonu() << endl;
            cout << "Email:             " << itr -> Adresat::pobierzEmail() << endl;
            cout << endl;
            string doZmiany;
            char wybor;
            cout << "Prosze wybrac jedna z ponizszych opcji (wpisujac cyfre od 1 do 6) : " << endl;
            cout << "1. Zmiana imienia" << endl;
            cout << "2. Zmiana nazwiska" << endl;
            cout << "3. Zmiana adresu" << endl;
            cout << "4. Zmiana numeru telefonu" << endl;
            cout << "5. Zmiana adresu email" << endl;
            cout << "6. Powrot do menu" << endl;
            cin >> wybor;
            if (wybor != '6') {
                adresatPomocniczy.ustawIdAdresata(idWyszukiwanegoKontaktu);
                adresatPomocniczy.ustawIdUzytkownika(itr -> Adresat::pobierzIdUzytkownika());
                adresatPomocniczy.ustawImie(itr -> Adresat::pobierzImie());
                adresatPomocniczy.ustawNazwisko(itr -> Adresat::pobierzNazwisko());
                adresatPomocniczy.ustawAdres(itr -> Adresat::pobierzAdres());
                adresatPomocniczy.ustawEmail(itr -> Adresat::pobierzEmail());
                adresatPomocniczy.ustawNumerTelefonu(itr -> Adresat::pobierzNumerTelefonu());
                cin.sync();
                cout << "Wprowadz dane do zapisu: ";
                getline(cin, doZmiany);
                switch (wybor) {
                case '1':
                    adresatPomocniczy.ustawImie(zamienPierwszaLitereNaDuzaAPozostaleNaMale(doZmiany));
                    itr->Adresat::ustawImie(doZmiany);
                    getch();
                    plikAdresaci.wprowadzanieZminaAdresataWPliku (adresatPomocniczy);
                    break;
                case '2':
                    adresatPomocniczy.ustawNazwisko(zamienPierwszaLitereNaDuzaAPozostaleNaMale(doZmiany));
                    itr->Adresat::ustawNazwisko(doZmiany);
                    plikAdresaci.wprowadzanieZminaAdresataWPliku (adresatPomocniczy);
                    break;
                case '3':
                    adresatPomocniczy.ustawAdres(doZmiany);
                    itr->Adresat::ustawAdres(doZmiany);
                    plikAdresaci.wprowadzanieZminaAdresataWPliku (adresatPomocniczy);
                    break;
                case '4':
                    adresatPomocniczy.ustawNumerTelefonu(doZmiany);
                    itr->Adresat::ustawNumerTelefonu(doZmiany);
                    plikAdresaci.wprowadzanieZminaAdresataWPliku (adresatPomocniczy);
                    break;
                case '5':
                    adresatPomocniczy.ustawEmail(doZmiany);
                    itr->Adresat::ustawEmail(doZmiany);
                    plikAdresaci.wprowadzanieZminaAdresataWPliku (adresatPomocniczy);
                    break;
                }
                cout << "Zmiany zostaly zapisane";
                Sleep(1000);
            } else if (wybor == 6) break;
        }
    }
    if (czyIstniejeKontakt == false) {
        cout << "Nie ma takiego kontaktu." << endl;
        Sleep(1000);
    }
}

void KsiazkaAdresowa::usuwanieKontaktu()
{
    int rozmiar = adresaci.size();
    int czyIstniejeKontakt = false;
    int idSzukanegoKontaktu = 0;
    int wybor;
    cout << "Podaj id kontaktu ";
    cin >> idSzukanegoKontaktu;
    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
        if (idSzukanegoKontaktu == itr ->Adresat::pobierzIdAdresata()) {
            czyIstniejeKontakt = true;
            cout << "Czy na pewno chcesz usunac kontakt " << itr ->Adresat::pobierzImie() << " " << itr -> Adresat::pobierzNazwisko() << "?" << endl;
            cout << "Jesli tak wcisnij 1, jesli nie wcisnij 2. " << endl;
            cin >> wybor;
            if (wybor == 1) {
                itr = adresaci.erase(itr);
                plikAdresaci.usuwanieAdresataZPliku(idSzukanegoKontaktu);
                cout << "Kontakt zostal usuniety.";
                Sleep(1000);
                break;
            } else  if (wybor !=1) break;
        }
    if (czyIstniejeKontakt == false) cout << "Taki kontakt nie istnieje. " << endl;

    }
}



