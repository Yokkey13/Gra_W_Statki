#pragma once
#include <iostream>
#include <vector>
#include "statek.h"

using namespace std;

class Info{
    vector<Statek> flota[4];
    int ilDw, ilTr, ilCz, ilPi, wiFlo, numerGracza;
public:
    Info(vector<Statek> *flota, int ilDw, int ilTr, int ilCz, int ilPi, int wiFlo, int numerGracza);

    vector<Statek> wstawFlota(int indeksTablicyWektorow, Statek statek);

    vector<Statek> getFlota(int indeksTablicyWektorow);

    int sprawdzDlTab();

    int dajRozmiarIndeksu(int indeksTablicyWektorow);

    int getIlDw() const;

    void setIlDw(int ilDw);

    int getIlTr() const;

    void setIlTr(int ilTr);

    int getIlCz() const;

    void setIlCz(int ilCz);

    int getIlPi() const;

    void setIlPi(int ilPi);

    int getWiFlo() const;

    void setWiFlo(int wiFlo);

    int getNumerGracza() const;

    void setNumerGracza(int numerGracza);

    void usunFragmentStatku(int indeksTablicyWektorow, int i);
};
