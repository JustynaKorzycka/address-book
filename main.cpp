#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Uzytkownik.h"
#include "Adresat.h"
#include "Uzytkownicy.h"
#include "plikUzytkownicy.h"
#include "PlikAdresaci.h"
#include "KsiazkaAdresowa.h"

using namespace std;


int main() {
    char wyborPierwszy;
    int idPomocnicze;

    Uzytkownicy uzytkownik;
    while (1) {
        system ("cls");
        if (uzytkownik.pobierzIdZalogowanegoUzytkownika() == 0) {
            cout << "Menu logowania " << endl;
            cout << "---------------------" << endl;
            cout << "1. Logowanie " <<endl;
            cout << "2. Rejestracja " <<endl;
            cout << "3. Zmiana hasla " <<endl;
            cout << "4. Wyjscie z programu " << endl;
            cin >> wyborPierwszy;
            switch (wyborPierwszy) {
            case '1': {
                uzytkownik.zaloguj();
                break;
            }
            case '2': {
                uzytkownik.rejestruj ();
                break;
            }
            case '3': {
                uzytkownik.zmienHaslo();
                break;
            }
            case '4':
                exit(0);
                break;
            }
        }else if (uzytkownik.pobierzIdZalogowanegoUzytkownika() != 0) {
            KsiazkaAdresowa adresat;
            adresat.wczytanieKontaktowDoWektora(uzytkownik);
            char wyborFunkcji;

            while (uzytkownik.pobierzIdZalogowanegoUzytkownika() != 0) {
                system("cls");
                cout << "Menu" << endl;
                cout << "--------------------" << endl;
                cout << "1. Wprowadz nowe dane kontaktowe" << endl;
                cout << "2. Wyszukaj kontakt po imieniu" << endl;
                cout << "3. Wyszukaj kontakt po nazwisku" << endl;
                cout << "4. Wyswietl wszystkie kontakty" << endl;
                cout << "5. Zmiana danych kontaktu"<<endl;
                cout << "6. Usuwanie kontaktu" << endl;
                cout << "7. Wyloguj" << endl;
                cout << "8. Wyjdz z programu" << endl;
                cin >> wyborFunkcji;

                if (wyborFunkcji == '1') {
                    int idZalogowanego = uzytkownik.pobierzIdZalogowanegoUzytkownika();
                    adresat.wprowadzNowyKontakt (idZalogowanego);
                } else if (wyborFunkcji == '2') {
                    adresat.wyszukajKontaktPoImieniu();
                } else if (wyborFunkcji == '3') {
                    adresat.wyszukajKontaktPoNazwisku();
                } else if (wyborFunkcji == '4') {
                    adresat.wyswietlWszystkieKontakty ();
                } else if (wyborFunkcji == '5') {
                    adresat.zmianaDaychKontakowych ();
                } else if (wyborFunkcji == '6') {
                    adresat.usuwanieKontaktu();
                } else if (wyborFunkcji == '7') {
                    uzytkownik.ustawIdZalogowengoUzytkownika(0);
                    break;
                } else if (wyborFunkcji == '8') exit(0);

    }
        }
    }

    return 0;
}
