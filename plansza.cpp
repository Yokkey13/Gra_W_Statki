#pragma once
#include <iostream>
#include "plansza.h"
#define ROZMIAR 32

using namespace std;

Plansza::Plansza(int rozmiar, char **plan) : rozmiar(rozmiar), plan(plan)
{
    budujPlansze(plan, rozmiar);
}

void Plansza::budujPlansze(char **plan, const int rozmiar)
{
    int i, j;
    char koniec = 'e', liczba=0;
    for(i=0; i<rozmiar; i++)
    {
        plan[0][i] = liczba;
        if(i>0)
            for(j=1; j<rozmiar; j++)
            {
                plan[i][j]='*';
            }
        plan[i][0] = liczba;
        plan[i][rozmiar-1] = koniec;
        liczba++;
    }
    for(j=0; j<rozmiar; j++)
        plan[rozmiar-1][j] = koniec;
}

void Plansza::wyswietlPlansze()
{
    int i, j;
    for(i=0; i<rozmiar-1; i++)
    {
        if(i<10)
            cout<<" ";
        for(j=0; j<rozmiar-1; j++)
        {
            if((j>=10 && i>0) || j<10)
                cout<<" ";
            if(i==0 && j>1)
                cout<<" ";
            if(plan[i][j] == 'x' || plan[i][j]== 'o')
            {
                cout<<plan[i][j]<<" ";
            }
            else if((plan[i][j] >= '2' && plan[i][j] <= '5') || plan[i][j] == 'e')
            {
                cout<<plan[i][j]<<" ";
            }
            else if(plan[i][j] != '*')
            {
                cout<<(int)plan[i][j];
                if(i>0 && j>0)
                    cout<<" ";
            }
            else
            {
                cout<<plan[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

char Plansza::pozyskajPole(int x, int y)
{
    if(y==(ROZMIAR))
        y=(ROZMIAR-2); //nie wiem czemu ale czasami y jest rowny 32
    return plan[y][x];
}

void Plansza::ustawPole(int x, int y, char pole)
{
    plan[y][x] = pole;
}

int Plansza::getRozmiar() const
{
    return rozmiar;
}

Plansza& Plansza::operator=(const Plansza &zakrytaGracza)
{
    int i, j;
    for(i=1; i<rozmiar-1; i++)
    {
        for(j=1; j<rozmiar-1; j++)
        {
            if(plan[i][j] == '*' || plan[i][j] == 'o' || plan[i][j] == 'x')
                plan[i][j] = zakrytaGracza.plan[i][j];
            else
                plan[i][j] = plan[i][j];
        }
    }
}
