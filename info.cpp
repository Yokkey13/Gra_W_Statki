#include <iostream>
#include "info.h"
#include "statek.h"
#include <vector>

void Info::usunFragmentStatku(int indeksTablicyWektorow, int i)
{
    flota[indeksTablicyWektorow].erase(flota[indeksTablicyWektorow].begin() + i, flota[indeksTablicyWektorow].begin() + (i+1));
}

vector<Statek> Info::wstawFlota(int indeksTablicyWektorow, Statek statek) {
    flota[indeksTablicyWektorow].push_back(statek);
    return flota[indeksTablicyWektorow];
}

vector<Statek> Info::getFlota(int indeksTablicyWektorow) {
    return flota[indeksTablicyWektorow];
}

int Info::sprawdzDlTab()
{
    int rozmiar0, rozmiar1, rozmiar2, rozmiar3;
    rozmiar0 = flota[0].size();
    rozmiar1 = flota[1].size();
    rozmiar2 = flota[2].size();
    rozmiar3 = flota[3].size();
    return (rozmiar0 + rozmiar1 + rozmiar2 + rozmiar3);
}

int Info::dajRozmiarIndeksu(int indeksTablicyWektorow)
{
    return flota[indeksTablicyWektorow].size();
}

int Info::getIlDw() const {
    return ilDw;
}

void Info::setIlDw(int ilDw) {
    Info::ilDw = ilDw;
}

int Info::getIlTr() const {
    return ilTr;
}

void Info::setIlTr(int ilTr) {
    Info::ilTr = ilTr;
}

int Info::getIlCz() const {
    return ilCz;
}

void Info::setIlCz(int ilCz) {
    Info::ilCz = ilCz;
}

int Info::getIlPi() const {
    return ilPi;
}

void Info::setIlPi(int ilPi) {
    Info::ilPi = ilPi;
}

int Info::getWiFlo() const {
    return wiFlo;
}

void Info::setWiFlo(int wiFlo) {
    Info::wiFlo = wiFlo;
}

int Info::getNumerGracza() const {
    return numerGracza;
}

void Info::setNumerGracza(int numerGracza) {
    Info::numerGracza = numerGracza;
}

Info::Info(vector<Statek> *flota, int ilDw, int ilTr, int ilCz, int ilPi, int wiFlo, int numerGracza) :
        ilDw(ilDw),
        ilTr(ilTr),
        ilCz(ilCz),
        ilPi(ilPi),
        wiFlo(wiFlo),
        numerGracza(numerGracza) {
    this->flota[0] = flota[0];
    this->flota[1] = flota[1];
    this->flota[2] = flota[2];
    this->flota[3] = flota[3];
}
