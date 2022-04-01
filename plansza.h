#pragma once
#include <iostream>

using namespace std;

class Plansza
{
    int rozmiar;
    char **plan;
public:
    Plansza(int rozmiar, char **plan);

    void budujPlansze(char **plan, const int rozmiar);

    void wyswietlPlansze();

    char pozyskajPole(int x, int y);

    void ustawPole(int x, int y, char pole);

    int getRozmiar() const;

    Plansza& operator=(const Plansza &zakrytaGracza);
};