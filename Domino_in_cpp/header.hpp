#include <algorithm>



class plansza{
    klocek reka1[21];
    klocek reka2[21];
    std::pair<klocek, float> pula[28];

private:
bool pairSort(pair<klocek,float> &a,pair<klocek,float> &b){
    return a.second < b.second;
}

public:
    void mieszaj(std::pair<klocek,float> *table)
    {
        for(int i = 0; i < 28; i++){
            table[i].second =  random() * 100000.f;
        }

        std::sort(table, table + 28, pairSort );
    }

    void initPudelko(int x){
        for(int i = 0; i < x; i++){
            for(int j = i; j < x; j++)
                pula[i + j].first = klocek(i, j);
        }
    }
};
class Game1{
public:
    void start();
    void settings();
    void stop();
};
class Game2{
public:
    void start();
    void settings();
    void stop();
};
class Game3{
public:
    void start();
    void settings();
    void stop();
};
class Game4{
public:
    void start();
    void settings();
    void stop();
};

class klocek{
public:
    int gora;
    int dol;
public:
    klocek(int a,int b)
    {
        gora=a;
        dol=b;
    }
};

class Menu{
    Game1 dobierane;
    Game2 zwykle;
    Game3 piatkowe;
    Game4 trojkowe;
public:
    void start();
    void settings();
    void stop();
};
// klocek pudelko[28]={klocek(0,0),klocek(0,1),klocek(0,2),klocek(0,3),klocek(0,4),klocek(0,5),klocek(0,6),klocek(1,1),klocek(1,2),klocek(1,3),klocek(1,4),
// klocek(1,5),klocek(1,6),klocek(2,2),klocek(2,3),klocek(2,4),klocek(2,5),klocek(2,6),klocek(3,3),klocek(3,4),klocek(3,5),klocek(3,6),klocek(4,4),
// klocek(4,5),klocek(4,6),klocek(5,5),klocek(5,6),klocek(6,6)};
