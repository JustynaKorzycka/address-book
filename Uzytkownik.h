#include <iostream>
#include <vector>
#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

using namespace std;

class Uzytkownik {
    int id;
    string login;
    string haslo;

public:
    Uzytkownik();
    virtual ~Uzytkownik();

    int pobierzId();
    string pobierzLogin();
    string pobierzHaslo();

    void ustawId(int id);
    void ustawLogin(string login);
    void ustawHaslo (string haslo);
};

#endif




