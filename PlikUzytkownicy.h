#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#ifndef PLIKUZYTKOWNICY_H
#define PLIKUZYTKOWNICY_H
#include "Uzytkownik.h"

using namespace std;

class PlikUzytkownicy {

public:
    void wczytajUzytkownikowZPliku (vector <Uzytkownik> &uzytkownicy);
    void aktualizujDaneUzytkownikow (vector <Uzytkownik> &uzytkownicy);
    void dopiszUzytkownikaDoPliku (Uzytkownik uzytkownik);

};

#endif
