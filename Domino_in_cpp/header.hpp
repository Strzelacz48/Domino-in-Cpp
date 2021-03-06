#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class klocek
{
public:
    int gora;
    int dol;

public:
    klocek();
    klocek(int a, int b);
    void wypisz();
};

class plansza
{
public:
    int board[9][9];
    klocek P1[21];
    int idx1, idx2, idxp;
    klocek P2[21];
    klocek pudelko[28] = {klocek(0, 0), klocek(0, 1), klocek(0, 2), klocek(0, 3), klocek(0, 4), klocek(0, 5), klocek(0, 6), klocek(1, 1), klocek(1, 2), klocek(1, 3), klocek(1, 4),
                          klocek(1, 5), klocek(1, 6), klocek(2, 2), klocek(2, 3), klocek(2, 4), klocek(2, 5), klocek(2, 6), klocek(3, 3), klocek(3, 4), klocek(3, 5), klocek(3, 6), klocek(4, 4),
                          klocek(4, 5), klocek(4, 6), klocek(5, 5), klocek(5, 6), klocek(6, 6)};

public:
    plansza();
    void drukuj();
    void add(klocek a, int x, int y, int kierunek);
    void dobierz(int player);
    bool check(klocek a);
    bool add2(klocek a, int x, int y, int kierunek);
    void shuffle_pudelko();
    void reka(int player);
};
class Game1 : plansza
{
private:
    plansza board;
    int left1, left2;
    klocek help[1]={klocek(-1,-1)};
public:
    void start();
    bool end();
    // void drukuj();
    // void add(klocek a, int x, int y, int kierunek);
    // void dobierz(int player);
    // bool check(klocek a);
    // bool add2(klocek a, int x, int y, int kierunek);
    // void shuffle_pudelko();
};
class Game2 : plansza
{
private:
    plansza tabula;
    int wynik1, wynik2;
    klocek help[1]={klocek(-1,-1)};
public:
    int suma();
    void start();
    bool end();
};
class Game3 : plansza
{
private:
    plansza tabula;
    int wynik1, wynik2;
    klocek help[1]={klocek(-1,-1)};
public:
    int suma();
    void start();
    bool end();
};
