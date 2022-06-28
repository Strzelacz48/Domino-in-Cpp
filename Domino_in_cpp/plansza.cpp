#include "header.hpp"
// plansza
using namespace std;
plansza::plansza()
{
    klocek reka1[21];
    klocek reka2[21];
    std::pair<klocek, float> pula[28];
    int idx1, idx2, idxp;
    initPudelko(28);
    dobierz(1);
    dobierz(2);
}
bool plansza::pairSort(std::pair<klocek, float> &a, std::pair<klocek, float> &b)
{
    return a.second < b.second;
}
void plansza::stop(int player)
{
    switch (player)
    {
    case 1:
        cout << "Gracz 1 wygrywa";
    case 2:
        cout << "Gracz 2 wygrywa";
    case 3:
        cout << "Remis";
    }
    // ver 2
    /*
    cout<<"Gracz ";
    switch (player)
    {
    case 1:
        cout<<"1";
    case 2:
        cout<<"2"
    }
    cout<<" wygrywa";*/
}
/*void plansza::mieszaj(std::pair<klocek, float> *table)
{
    for (int i = 0; i < 28; i++)
    {
        table[i].second = rand() * 100000.f;
    }

    std::sort(table, table + 28, pairSort);
    idxp = 14;
    idx1 = 7;
    idx2 = 7;
}*/

void plansza::initPudelko(int x)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = i; j < x; j++){
            klocek pomi = klocek(i,j);
            pula[i + j].first = pomi;
        }
    }
    pula[2].second = 0.3;
}

void plansza::dobierz(int player)
{
    switch (player)
    {
    case 1:
        if (idx1 >= 7 && idx1 < 21)
        {
            reka1[idx1] = pula[idxp].first;
            idx1++;
            idxp++;
        }
        else
        {
            throw std::string("Zly indeks reki gracza 1");
        }
    case 2:
        if (idx2 >= 7 && idx2 < 21)
        {
            reka1[idx2] = pula[idxp].first;
            idx2++;
            idxp++;
        }
        else
        {
            throw std::string("Zly indeks reki gracza 2");
        }
    }
}
// klocek
klocek::klocek()
{
}
klocek::klocek(int a, int b)
{
    gora = a;
    dol = b;
}
klocek &klocek::operator=(klocek &block)
{
    if (this == &block)
        return *this;
    gora = block.gora;
    dol = block.dol;
    return *this;
}
void klocek::wypisz()
{
    cout << gora << "|" << dol;
}
