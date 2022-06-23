#include "header.hpp"
class plansza
{
    klocek reka1[21];
    klocek reka2[21];
    std::pair<klocek, float> pula[28];
    int idx1, idx2, idxp;

private:
    bool pairSort(pair<klocek, float> &a, pair<klocek, float> &b)
    {
        return a.second < b.second;
    }

public:
    void mieszaj(std::pair<klocek, float> *table)
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

    void initPudelko(int x)
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = i; j < x; j++)
                pula[i + j].first = klocek(i, j);
        }
    }

    void dobierz(int player)
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
};