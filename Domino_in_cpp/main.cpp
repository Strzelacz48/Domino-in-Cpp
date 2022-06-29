//#include <iostream>
#include "header.hpp"
//#include "plansza.cpp"
using namespace std;

int main()
{
    Game1 a;
    a.start();
    // a.initPudelko(28);
    cout << "test\n";
    /*klocek pom = klocek(1, 2);
    klocek pom2 = klocek(0, 1);
    a.drukuj();
    cout << "\n";
    a.add(pom, 1, 1, 1);
    cout << a.check(pom2) << "\n";
    a.drukuj();
    int pomi = 0, x, y, i, j, kier;
    bool g;
    a.shuffle_pudelko();
    for (int i = 0; i < 28; i++)
    {
        a.pudelko[i].wypisz();
        cout<<", ";
    }
    cout<<"\n";
    while (pomi != -2)
    {
        cout << "Podaj klocek i|j, x, y, kierunek, bool gora czy dol\n";
        a.drukuj();
        cin >> i >> j >> y >> x >> kier;
        if (a.add2(klocek(i, j), x, y, kier))
            cout << "dodanie udane";
        else
            cout << "nie mozna dodac";
        cout << "-2 wyjscie z petli";
        cin >> pomi;
    }

    /*for(int i=0;i<28;i++)
    {
        a.pula[i].wypisz();
        cout<<" ";
    }*/
    cout << "test2";
    // a.reka(1);
    // a.reka(2);
    return 0;
}
