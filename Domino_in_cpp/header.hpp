#include <algorithm>
#include <iostream>
using namespace std;

class klocek
{
public:
    int gora;
    int dol;
    bool orientx;

public:
    klocek();
    klocek(int a, int b);
    klocek &operator=(klocek &block);
    void wypisz();
};

class plansza
{
public:
    klocek reka1[21];
    klocek reka2[21];
    std::pair<klocek, float> pula[28];
    int idx1, idx2, idxp;
    int size;
    klocek **board;

private:
    bool pairSort(std::pair<klocek, float> &a, std::pair<klocek, float> &b);

public:
    plansza();
    void mieszaj(std::pair<klocek, float> *table);

    void initPudelko(int x);

    void dobierz(int player);

    void stop(int player);

    void drukuj();
};

class Game1
{
public:
    void start();
    void settings();
    // void stop(int player);
};
class Game2
{
public:
    void start();
    void settings();
    // void stop(int player);
};
class Game3
{
public:
    void start();
    void settings();
    // void stop(int player);
};
class Game4
{
public:
    void start();
    void settings();
    // void stop(int player);
};

class Menu
{
    Game1 zwykle;
    Game2 dobierane;
    Game3 piatkowe;
    Game4 trojkowe;

public:
    void start()
    {
        int pom;
        cout << "Wybierz tryb gry wpisując numer 1-4 : \n 1. Domino zwykle\n 2. Domino dobierane\n 3. Domino piatkowe\n 4. Domnio trojkowe";
        cin >> pom;
        switch (pom)
        {
        case 1:
            zwykle.start();
            break;

        case 2:
            dobierane.start();
            break;

        case 3:
            piatkowe.start();
            break;

        case 4:
            trojkowe.start();
            break;
        }
    }
    void settings();
    void stop(); // sprawdzić exit
};
// klocek pudelko[28]={klocek(0,0),klocek(0,1),klocek(0,2),klocek(0,3),klocek(0,4),klocek(0,5),klocek(0,6),klocek(1,1),klocek(1,2),klocek(1,3),klocek(1,4),
// klocek(1,5),klocek(1,6),klocek(2,2),klocek(2,3),klocek(2,4),klocek(2,5),klocek(2,6),klocek(3,3),klocek(3,4),klocek(3,5),klocek(3,6),klocek(4,4),
// klocek(4,5),klocek(4,6),klocek(5,5),klocek(5,6),klocek(6,6)};
