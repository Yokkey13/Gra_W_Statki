#include <iostream>
#include "statek.h"
#include "info.h"

using namespace std;


Statek::Statek(int nazwa, char pozycja, int dlugosc, int x, int y) : nazwa(nazwa), pozycja(pozycja), dlugosc(dlugosc), x(x), y(y) {}


int Statek::getNazwa() const {
    return nazwa;
}

void Statek::setNazwa(int nazwa) {
    Statek::nazwa = nazwa;
}

char Statek::getPozycja() const {
    return pozycja;
}

void Statek::setPozycja(char pozycja) {
    Statek::pozycja = pozycja;
}

int Statek::getDlugosc() const {
    return dlugosc;
}

void Statek::setDlugosc(int dlugosc) {
    Statek::dlugosc = dlugosc;
}

int Statek::getX() const {
    return x;
}

void Statek::setX(int x) {
    Statek::x = x;
}

int Statek::getY() const {
    return y;
}

void Statek::setY(int y) {
    Statek::y = y;
}

Statek::Statek() {}

bool Statek::operator==(Statek &obj)
{
    return (nazwa==obj.nazwa) and (pozycja==obj.pozycja) and (dlugosc==obj.dlugosc) and (x==obj.x) and (y=obj.y);
}
