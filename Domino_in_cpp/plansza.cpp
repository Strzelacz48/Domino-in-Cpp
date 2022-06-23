#include "header.hpp"
// plansza
bool plansza::pairSort(std::pair<klocek, float> &a, std::pair<klocek, float> &b)
{
    return a.second < b.second;
}

void plansza::mieszaj(std::pair<klocek, float> *table)
{
    for (int i = 0; i < 28; i++)
    {
        table[i].second = rand() * 100000.f;
    }

    std::sort(table, table + 28, pairSort);
    idxp = 14;
    idx1 = 7;
    idx2 = 7;
}

void plansza::initPudelko(int x)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = i; j < x; j++)
            pula[i + j].first = klocek(i, j);
    }
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