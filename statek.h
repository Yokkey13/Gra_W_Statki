#pragma once
#include <iostream>

using namespace std;

class Statek
{
    int nazwa;
    char pozycja;
    int dlugosc;
    int x, y;

public:
    Statek();

    Statek(int nazwa, char pozycja, int dlugosc, int x, int y);

    int getNazwa() const;

    void setNazwa(int nazwa);

    char getPozycja() const;

    void setPozycja(char pozycja);

    int getDlugosc() const;

    void setDlugosc(int dlugosc);

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    bool operator==(Statek &obj);
};


