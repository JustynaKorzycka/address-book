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

using namespace std;

Adresat :: Adresat()
{
    idAdresata = 0;
    idZalogowanegoUzytkownika = 0;
    imie = "";
    nazwisko = "";
    numerTelefonu = "";
    email = "";
    adres = "";
}
Adresat :: ~Adresat()
{
   ;
}
int Adresat :: pobierzIdAdresata() {
    return idAdresata;
}
int Adresat :: pobierzIdUzytkownika() {
    return idZalogowanegoUzytkownika;
}
string Adresat :: pobierzImie() {
    return imie;
}
string Adresat :: pobierzNazwisko() {
    return nazwisko;
}
string Adresat :: pobierzNumerTelefonu() {
    return numerTelefonu;
}
string Adresat :: pobierzEmail() {
    return email;
}
string Adresat :: pobierzAdres() {
    return adres;
}

void Adresat :: ustawIdAdresata(int idAdresata) {
    this->idAdresata = idAdresata;
}
void Adresat :: ustawIdUzytkownika(int idZalogowanegoUzytkownika) {
    this->idZalogowanegoUzytkownika = idZalogowanegoUzytkownika;
}
void Adresat :: ustawImie(string imie) {
    this->imie = imie;
}
void Adresat :: ustawNazwisko(string nazwisko) {
    this->nazwisko = nazwisko;
}
void Adresat :: ustawNumerTelefonu(string numerTelefonu) {
    this->numerTelefonu = numerTelefonu;
}
void Adresat :: ustawEmail(string email) {
    this->email = email;
}
void Adresat :: ustawAdres(string adres) {
    this->adres = adres;
}










