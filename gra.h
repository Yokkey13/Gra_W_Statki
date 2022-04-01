#pragma once
#include <iostream>
#include "plansza.h"
#include "info.h"

using namespace std;

class Gra
{
public:

};

void takGramy(int wyborOpcjiGry);
void graczVSgracz(Info dane1, Info dane2);
void liczbaFloty(int numerGracza, Info dane);
void rozstawianie(int numerGracza, Plansza gracz, Info dane);
void dodajStatekNaPlansze(Plansza gracz, int iloscDanegoStatku, int rodzajStatku, string nazwaStatku, Info dane);
void tworzenieStatku(int rodzajStatku, char pozycja, int x, int y, Info dane);
void jakGramy();

//void rozstawianie(int numerGracza, Plansza gracz);
//void liczbaFloty(int numerGracza);
//void graczVSgracz();
//void takGramy(int wyborOpcjiGry);
//void jakGramy();