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
#ifndef PlIKADRESACI_H
#define PlIKADRESACI_H

using namespace std;

class PlikAdresaci
{
public:

    void wczytywanieAdresatowZPliku (vector <Adresat> &adresat, Uzytkownicy uzytkownik);
    void dopiszAdresataDoPliku (Adresat adresat);
    void usuwanieAdresataZPliku (int idDoUsuniecia);
    void wprowadzanieZminaAdresataWPliku (Adresat adresat);



};







#endif
