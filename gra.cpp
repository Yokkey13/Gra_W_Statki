#include <iostream>
#include <vector>
#include <ctime>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "plansza.h"
#include "statek.h"
#include "gra.h"
#include "info.h"

#define ROZMIAR 32 //musza byc dwa dodatkowe pola, czyli jak ma byc plansza 30x30 to ustawiamy 32 jeszcze w plansza.cpp trzeba zmienic

using namespace std;

//bool czyZatopiony(int x, int y, Plansza gracz, Plansza zakrytaGracza)
//{
//    gracz = zakrytaGracza;
//    gracz.wyswietlPlansze();
//    if(((int)gracz.pozyskajPole(x+1,y) >= 2 && (int)gracz.pozyskajPole(x+1,y) <= 5) || ((int)gracz.pozyskajPole(x-1,y) >= 2 && (int)gracz.pozyskajPole(x-1,y) <= 5) || ((int)gracz.pozyskajPole(x,y+1) >= 2 && (int)gracz.pozyskajPole(x,y+1) <= 5))
//        return false;
//    return true;
//}

void strzelanie(Plansza gracz1, Plansza gracz2, Info *dane1, Info *dane2, char ktoGra)
{
    srand(time(NULL));
    int trafionyCzyNie = 2;
    int x, y, xs, ys, numerGracza=1, tx, ty;
    Statek s, test;
    char **zakryta1, **zakryta2;
    zakryta1 = new char *[ROZMIAR];
    zakryta2 = new char *[ROZMIAR];
    for (int i = 0; i < ROZMIAR; i++)
    {
        zakryta1[i] = new char[ROZMIAR];
        zakryta2[i] = new char[ROZMIAR];
    }
    Plansza zakrytaGracza1(ROZMIAR, zakryta1), zakrytaGracza2(ROZMIAR, zakryta2);
    while(dane1->sprawdzDlTab() != 0 && dane2->sprawdzDlTab() != 0)
    {
        cout<<"-----------------------------------------------"<<endl;
        int dlugosc1=dane1->sprawdzDlTab(), dlugosc2=dane2->sprawdzDlTab();
        int idTabWek=0;
        switch(ktoGra)
        {
            case 'G':
                if(numerGracza==1)
                {
                    cout<<"PLANSZA GRACZA NR 2"<<endl;
                    zakrytaGracza2.wyswietlPlansze();
                    cout<<"PLANSZA GRACZA NR 1"<<endl;
                    gracz1.wyswietlPlansze();
                    if(trafionyCzyNie==1)
                        cout << "TRAFIONY! Strzelaj dalej\n";
                    else if(trafionyCzyNie==0)
                        cout << "PUDLO! Pora na ruch oponenta\n";
                    cout << "GRACZU NR " << numerGracza << "\nPodaj wspolrzedne do strzalu: ";
                    label52:
                    cin >> x >> y;
                    if(zakrytaGracza2.pozyskajPole(x,y) == 'o' || zakrytaGracza2.pozyskajPole(x,y) == 'x') {
                        cout << "Juz tu strzelales..." << endl;
                        goto label52;
                    }
                }
                else if(numerGracza==2)
                {
                    cout<<"PLANSZA GRACZA NR 1"<<endl;
                    zakrytaGracza1.wyswietlPlansze();
                    cout<<"PLANSZA GRACZA NR 2"<<endl;
                    gracz2.wyswietlPlansze();
                    if(trafionyCzyNie==1)
                        cout << "TRAFIONY! Strzelaj dalej\n";
                    else if(trafionyCzyNie==0)
                        cout << "PUDLO! Pora na ruch oponenta\n";
                    cout << "GRACZU NR " << numerGracza << "\nPodaj wspolrzedne do strzalu: ";
                    label68:
                    cin >> x >> y;
                    if(zakrytaGracza2.pozyskajPole(x,y) == 'o' || zakrytaGracza2.pozyskajPole(x,y) == 'x') {
                        cout << "Juz tu strzelales..." << endl;
                        goto label68;
                    }
                }
                break;
            case 'P':
                if(numerGracza==1)
                {
                    cout<<"PLANSZA KOMPUTERA"<<endl;
                    zakrytaGracza2.wyswietlPlansze();
                    cout<<"PLANSZA GRACZA"<<endl;
                    gracz1.wyswietlPlansze();
                    if(trafionyCzyNie==1)
                        cout << "TRAFIONY! Strzelaj dalej\n";
                    else if(trafionyCzyNie==0)
                        cout << "PUDLO! Pora na ruch oponenta\n";
                    cout << "GRACZU NR " << numerGracza << "\nPodaj wspolrzedne do strzalu: ";
                    label90:
                    cin >> x >> y;
                    if(zakrytaGracza2.pozyskajPole(x,y) == 'o' || zakrytaGracza2.pozyskajPole(x,y) == 'x') {
                        cout << "Juz tu strzelales..." << endl;
                        goto label90;
                    }
                }
                else if(numerGracza==2)
                {
                    cout<<"PLANSZA GRACZA"<<endl;
                    zakrytaGracza1.wyswietlPlansze();
                    cout<<"PLANSZA KOMPUTERA"<<endl;
                    gracz2.wyswietlPlansze();
                    cout<<"Komputer oddaje strzal..."<<endl;
                    sleep(1);
                    label106:
                    x = rand()% (ROZMIAR-2)+1;
                    y = rand()% (ROZMIAR-2)+1;
                    tx = x;
                    ty = y;
                    if(trafionyCzyNie == 1)
                    {
                        x = rand()% 3 + (x-1);
                        y = rand()% 3 + (y-1);
                    }
                    if(zakrytaGracza2.pozyskajPole(x,y) == 'o' || zakrytaGracza2.pozyskajPole(x,y) == 'x')
                        goto label106;
                }
                break;
            case 'W':
                if(numerGracza==1)
                {
                    cout<<"PLANSZA KOMPUTERA NR 2"<<endl;
                    zakrytaGracza2.wyswietlPlansze();
                    cout<<"PLANSZA KOMPUTREA NR 1"<<endl;
                    gracz1.wyswietlPlansze();
                    cout<<"Komputer 1 oddaje strzal..."<<endl;
                    sleep(1);
                    label121:
                    x = rand()% (ROZMIAR-2)+1;
                    y = rand()% (ROZMIAR-2)+1;
                    if(zakrytaGracza2.pozyskajPole(x,y) == 'o' || zakrytaGracza2.pozyskajPole(x,y) == 'x')
                        goto label121;
                }
                else if(numerGracza==2)
                {
                    cout << "PLANSZA KOMPUTERA NR 1" << endl;
                    zakrytaGracza1.wyswietlPlansze();
                    cout << "PLANSZA KOMPUTERA NR 2" << endl;
                    gracz2.wyswietlPlansze();
                    cout << "Komputer 2 oddaje strzal..." << endl;
                    sleep(1);
                    label135:
                    x = rand() % (ROZMIAR - 2) + 1;
                    y = rand() % (ROZMIAR - 2) + 1;
                    if(zakrytaGracza2.pozyskajPole(x,y) == 'o' || zakrytaGracza2.pozyskajPole(x,y) == 'x')
                        goto label135;
                }
                break;
        }
        if(dane2->getFlota(0).empty())
        {
            idTabWek = 1;
            if(dane2->getFlota(1).empty())
            {
                idTabWek=2;
                if(dane2->getFlota(2).empty())
                {
                    idTabWek=3;
                }
            }
        }
        if(numerGracza==1) {
            for(int i=0; i < (dane2->dajRozmiarIndeksu(idTabWek));i++) {
                s = dane2->getFlota(idTabWek).operator[](i);
                xs = s.getX();
                ys = s.getY();
                if ((x == xs) && (y == ys)) {
                    zakrytaGracza2.ustawPole(x,y,'x');
                    dane2->usunFragmentStatku(idTabWek, i);
                    trafionyCzyNie = 1;
                    //bool testa = czyZatopiony(x,y,gracz2,zakrytaGracza2);
                    break;
                }
                test = dane2->getFlota(idTabWek).back();
                if (s == dane2->getFlota(idTabWek).back()) {
                    idTabWek++;
                    i = -1;
                    if (idTabWek == 4)
                        break;
                }
            }
            if(idTabWek==4 || (idTabWek==1 && dane2->getFlota(1).empty()))  {
                zakrytaGracza2.ustawPole(x, y, 'o');
                trafionyCzyNie = 0;
                numerGracza = 2;
            }
        }
        else if(numerGracza==2) {
            for(int i=0; i < (dane1->dajRozmiarIndeksu(idTabWek));i++) {
                s = dane1->getFlota(idTabWek).operator[](i);
                xs = s.getX();
                ys = s.getY();
                if ((x == xs) && (y == ys)) {
                    zakrytaGracza1.ustawPole(x,y,'x');
                    dane1->usunFragmentStatku(idTabWek, i);
                    trafionyCzyNie = 1;
                    break;
                }
                if (s == dane1->getFlota(idTabWek).back()) {
                    idTabWek++;
                    i = -1;
                    if (idTabWek == 4)
                        break;
                }
            }
            if(idTabWek==4 || (idTabWek==1 && dane2->getFlota(1).empty())) {
                zakrytaGracza1.ustawPole(x, y, 'o');
                trafionyCzyNie = 0;
                numerGracza = 1;
            }
        }
    }
}

void pomocDoCzyMozna(Plansza gracz)
{
    for(int i=2; i<6; i++)
    {
        gracz.ustawPole(0, i, i);
        gracz.ustawPole(i, 0, i);
    }
}

bool czyMozna(int x, int y, char pozycja, int rodzajStatku, Plansza gracz, char autMan)
{
    for(int i=2; i<6; i++)
    {
        gracz.ustawPole(0, i, 1);
        gracz.ustawPole(i, 0, 1);
    }
    switch(pozycja)
    {
        case 'W':
            for (int i = 0; i < rodzajStatku; i++)
            {
                if(((int)gracz.pozyskajPole(x,y+i-1) >= 2 && (int)gracz.pozyskajPole(x,y+i-1) <= 5) || ((int)gracz.pozyskajPole(x-1,y+i) >= 2 && (int)gracz.pozyskajPole(x-1,y+i) <= 5) || ((int)gracz.pozyskajPole(x+1,y+i) >= 2 && (int)gracz.pozyskajPole(x+1,y+i) <= 5))
                {
                    if(autMan=='M')
                        cout << "\n-----------PODANO NIEPRAWIDLOWE WSPOLRZEDNE DO USTAWIENIA STATKU -> PODAJ POPRAWNE-----------\n";
                    pomocDoCzyMozna(gracz);
                    return false;
                }
                if(i == (rodzajStatku-1))
                {
                    if (((int)gracz.pozyskajPole(x, y+i) >= 2 && (int)gracz.pozyskajPole(x, y + i) <= 5) || ((int)gracz.pozyskajPole(x, y+i+1) >= 2 && (int)gracz.pozyskajPole(x, y+i+1) <= 5))
                    {
                        if(autMan=='M')
                            cout << "\n-----------PODANO NIEPRAWIDLOWE WSPOLRZEDNE DO USTAWIENIA STATKU -> PODAJ POPRAWNE-----------\n";
                        pomocDoCzyMozna(gracz);
                        return false;
                    }
                }
                if(gracz.pozyskajPole(x,y + i) == 'e')
                {
                    if(autMan=='M')
                        cout << "\n-----------PODANO NIEPRAWIDLOWE WSPOLRZEDNE DO USTAWIENIA STATKU -> PODAJ POPRAWNE-----------\n";
                    pomocDoCzyMozna(gracz);
                    return false;
                }
            }
            break;
        case 'H':
            for (int i = 0; i < rodzajStatku; i++)
            {//lewo, gora, dol
                if(((int)gracz.pozyskajPole(x+i-1,y) >= 2 && (int)gracz.pozyskajPole(x+i-1,y) <= 5) || ((int)gracz.pozyskajPole(x+i,y-1) >= 2 && (int)gracz.pozyskajPole(x+i,y-1) <= 5) || ((int)gracz.pozyskajPole(x+i,y+1) >= 2 && (int)gracz.pozyskajPole(x+i,y+1) <= 5))
                {
                    if(autMan=='M')
                        cout << "\n-----------PODANO NIEPRAWIDLOWE WSPOLRZEDNE DO USTAWIENIA STATKU -> PODAJ POPRAWNE-----------\n";
                    pomocDoCzyMozna(gracz);
                    return false;
                }
                if(i == (rodzajStatku-1))
                {
                    if (((int)gracz.pozyskajPole(x+i, y) >= 2 && (int)gracz.pozyskajPole(x+i, y) <= 5) || ((int)gracz.pozyskajPole(x+i+1, y) >= 2 && (int)gracz.pozyskajPole(x+i+1, y) <= 5))
                    {
                        if(autMan=='M')
                            cout << "\n-----------PODANO NIEPRAWIDLOWE WSPOLRZEDNE DO USTAWIENIA STATKU -> PODAJ POPRAWNE-----------\n";
                        pomocDoCzyMozna(gracz);
                        return false;
                    }
                }
                if(gracz.pozyskajPole(x + i,y) == 'e')
                {
                    if(autMan=='M')
                        cout << "\n-----------PODANO NIEPRAWIDLOWE WSPOLRZEDNE DO USTAWIENIA STATKU -> PODAJ POPRAWNE-----------\n";
                    pomocDoCzyMozna(gracz);
                    return false;
                }
            }
            break;
    }
    pomocDoCzyMozna(gracz);
    return true;
}

void tworzenieStatku(int rodzajStatku, char pozycja, int x, int y, Info *dane)
{
    Statek piatka(5,0,5,0,0);
    Statek czworka(4,0,4,0,0);
    Statek trojka(3,0,3,0,0);
    Statek dwojka(2,0,2,0,0);
    switch(rodzajStatku)
    {
        case 5:
            switch(pozycja)
            {
                case 'W':
                    for(int i=0; i<rodzajStatku; i++)
                    {
                        piatka.setX(x);
                        piatka.setY(y+i);
                        piatka.setPozycja(pozycja);
                        dane->wstawFlota(3,piatka);
                    }
                    break;
                case 'H':
                    for(int i=0; i<rodzajStatku; i++)
                    {
                        piatka.setX(x+i);
                        piatka.setY(y);
                        piatka.setPozycja(pozycja);
                        dane->wstawFlota(3, piatka);
                    }
                    break;
            }
            break;
        case 4:
            switch(pozycja)
            {
                case 'W':
                    for(int i=0; i<rodzajStatku; i++)
                    {
                        czworka.setX(x);
                        czworka.setY(y+i);
                        czworka.setPozycja(pozycja);
                        dane->wstawFlota(2, czworka);
                    }
                    break;
                case 'H':
                    for(int i=0; i<rodzajStatku; i++)
                    {
                        czworka.setX(x+i);
                        czworka.setY(y);
                        czworka.setPozycja(pozycja);
                        dane->wstawFlota(2, czworka);
                    }
                    break;
            }
            break;
        case 3:
            switch(pozycja)
            {
                case 'W':
                    for(int i=0; i<rodzajStatku; i++)
                    {
                        trojka.setX(x);
                        trojka.setY(y+i);
                        trojka.setPozycja(pozycja);
                        dane->wstawFlota(1, trojka);
                    }
                    break;
                case 'H':
                    for(int i=0; i<rodzajStatku; i++)
                    {
                        trojka.setX(x+i);
                        trojka.setY(y);
                        trojka.setPozycja(pozycja);
                        dane->wstawFlota(1, trojka);
                    }
                    break;
            }
            break;
        case 2:
            switch(pozycja)
            {
                case 'W':
                    for(int i=0; i<rodzajStatku; i++)
                    {
                        dwojka.setX(x);
                        dwojka.setY(y+i);
                        dwojka.setPozycja(pozycja);
                        dane->wstawFlota(0, dwojka);
                    }
                    break;
                case 'H':
                    for(int i=0; i<rodzajStatku; i++)
                    {
                        dwojka.setX(x+i);
                        dwojka.setY(y);
                        dwojka.setPozycja(pozycja);
                        dane->wstawFlota(0, dwojka);
                    }
                    break;
            }
            break;
    }
}

void dodajStatekNaPlansze(Plansza gracz, int iloscDanegoStatku, int rodzajStatku, string nazwaStatku, Info *dane, char autMan)
{
    srand(time(NULL));
    int HczyW[2] = {87,72}, indeksHW;
    bool wynikMoznosci = false;
    int x, y, i=0;
    char pozycja;
    while(i < iloscDanegoStatku)
    {
        if(autMan=='M')
        {
            gracz.wyswietlPlansze();
            cout << nazwaStatku << "\nPodaj wspolrzedne rozstawienia: ";
            cin >> x >> y;
            if ((x < 1 || x > (ROZMIAR-2)) || (y < 1 || y > (ROZMIAR-2))) {
                cout << "\n---------------------PODANO NIEPRAWIDLOWE WSPOLRZEDNE --> PODAJ POPRAWNE---------------------\n";
                continue;
            }
            cout << "Podaj pozycje rozstawienia (H-horyzontalnie/W-wertykalnie): ";
            cin >> pozycja;
        }
        else
        {
            pozycja='A';
            x = rand()% (ROZMIAR-2)+1;
            y = rand()% (ROZMIAR-2)+1;
            //W-87 H-72
            while(pozycja != 'H' && pozycja != 'W')
            {
                indeksHW = rand() % 2;
                pozycja = (char) HczyW[indeksHW];
            }
        }
        wynikMoznosci = czyMozna(x, y, pozycja, rodzajStatku, gracz, autMan);
        if(!wynikMoznosci)
            continue;
        switch(pozycja)
        {
            case 'W':
                for (int j = 0; j < rodzajStatku; j++)
                {
                    gracz.ustawPole(x, y + j, rodzajStatku);
                }
                tworzenieStatku(rodzajStatku, pozycja, x, y, dane);
                break;
            case 'H':
                for (int j = 0; j < rodzajStatku; j++)
                {
                    gracz.ustawPole(x + j, y, rodzajStatku);
                }
                tworzenieStatku(rodzajStatku, pozycja, x, y, dane);
                break;
            default:
                cout << "Bledna opcja. Wybierz poprawna (H/W)\n";
                break;
        }
        i++;
    }
}

void rozstawianie(int numerGracza, Plansza gracz, Info *dane, char autMan)
{
    char pozycja;
    if(autMan=='M')
        cout << " ------------------------------GRACZ NR " << numerGracza << " ROZSTAW SWOJE OKRETY------------------------------\n";
    dodajStatekNaPlansze(gracz, dane->getIlPi(), 5, "PIECIOMASZTOWIEC", dane, autMan);
    dodajStatekNaPlansze(gracz, dane->getIlCz(), 4, "CZTEROMASZTOWIEC", dane, autMan);
    dodajStatekNaPlansze(gracz, dane->getIlTr(), 3, "TROJMASZTOWIEC", dane, autMan);
    dodajStatekNaPlansze(gracz, dane->getIlDw(), 2, "DWUMASZTOWIEC", dane, autMan);
    if(autMan=='M')
        gracz.wyswietlPlansze();
}

void liczbaFloty(Info *dane)
{
    int iloscDwojek, iloscTrojek, iloscCzworek, iloscPiatek, wielkoscFloty;
    cout << " PODAJ ROZMIAR FLOTY DO GRY\n";
    cout << "Dwumasztowce: ";
    cin >> iloscDwojek;
    dane->setIlDw(iloscDwojek);
    cout << "Trzymasztowce: ";
    cin >> iloscTrojek;
    dane->setIlTr(iloscTrojek);
    cout << "Czteromasztowce: ";
    cin >> iloscCzworek;
    dane->setIlCz(iloscCzworek);
    cout << "Pieciomasztowce: ";
    cin >> iloscPiatek;
    dane->setIlPi(iloscPiatek);
    wielkoscFloty = iloscDwojek + iloscTrojek + iloscCzworek + iloscPiatek;
    dane->setWiFlo(wielkoscFloty);
}

void granie(Info dane1, Info dane2, char ktoGra)
{
    int i, numerGracza = 1;
    string start;
    char autMan;
    char **plansza1, **plansza2;
    plansza1 = new char *[ROZMIAR];
    plansza2 = new char *[ROZMIAR];
    for (i = 0; i < ROZMIAR; i++)
    {
        plansza1[i] = new char[ROZMIAR];
        plansza2[i] = new char[ROZMIAR];
    }
    Plansza gracz1(ROZMIAR, plansza1), gracz2(ROZMIAR, plansza2);
    liczbaFloty(&dane1);
    dane2 = dane1;
    cout<<"Jak chcesz rozmiescic flote? [A]utomatycznie czy [M]anualnie ?\n";
    cout<<"Wybierz: ";
    cin>>autMan;
    if(autMan=='A')
        cout<<"Rozstawianie..."<<endl;
    rozstawianie(1, gracz1, &dane1, autMan);
    sleep(2);
    rozstawianie(2, gracz2, &dane2, autMan);
    cout<<endl<<"PLANSZA 1"<<endl;
    gracz1.wyswietlPlansze();
    cout<<endl<<"PLANSZA 2"<<endl;
    gracz2.wyswietlPlansze();
    cout<<endl<<"Start? Wpisz cokolwiek.\n";
    cin>>start;
    strzelanie(gracz1, gracz2, &dane1, &dane2, ktoGra);
    cout<<endl<<"KONIEC GRY. GRATULACJE DLA OBU GRACZY ZA WYTRWALOSC";
}

void takGramy(int wyborOpcjiGry)
{
    vector<Statek> flota1[4];
    vector<Statek> flota2[4];
    Info dane1(flota1,0,0,0,0,0,1), dane2(flota2,0,0,0,0,0,2);
    switch (wyborOpcjiGry)
    {
        case 1:
            granie(dane1, dane2, 'G');
            break;
        case 2:
            granie(dane1,dane2,'P');
            break;
        case 3:
            granie(dane1,dane2,'W');
            break;
    }
}

void jakGramy()
{
    int wyborOpcjiGry;
    cout << "[1] - gracz vs gracz\n[2] - gracz vs komputer\n[3] - komputer vs komputer\nWybierz opcje gry: ";
    cin >> wyborOpcjiGry;
    takGramy(wyborOpcjiGry);
}