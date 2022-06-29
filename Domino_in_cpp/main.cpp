//#include <iostream>
#include "header.hpp"
//#include "plansza.cpp"
using namespace std;

int main()
{
    plansza a;
    // a.initPudelko(28);
    cout<<"test\n";
    klocek pom=klocek(1,2);
    klocek pom2=klocek(0,1);
    a.drukuj();
    cout<<"\n";
    a.add(pom,1,1,1);
    cout<<a.check(pom2)<<"\n";
    a.drukuj();
    /*for(int i=0;i<28;i++)
    {
        a.pula[i].wypisz();
        cout<<" ";
    }*/
    cout<<"test2";
    //a.reka(1);
    //a.reka(2);
    return 0;
}
