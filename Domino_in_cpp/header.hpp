<<<<<<< HEAD
class Menu
{
    Game1 dobierane;
    Game2 zwykle;
    Game3 piatkowe;
    Game4 trojkowe;

public:
    void start();
    void settings();
    void stop();
};
class Game1
{
public:
    void start();
    void settings();
    void stop();
};
class Game2
{
public:
    void start();
    void settings();
    void stop();
};
class Game3
{
public:
    void start();
    void settings();
    void stop();
};
class Game4
{
public:
    void start();
    void settings();
    void stop();
};
class klocek
{
    int gora;
    int dol;
};
class plansza
{
    klocek reka1[];
    klocek reka2[];
    klocek pula[];
};
=======
#include <algorithm>



class plansza{
    klocek reka1[21];
    klocek reka2[21];
    std::pair<klocek, float> pula[28];
    int idx1,idx2,idxp;
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
        idxp=14;
        idx1=7;
        idx2=7;
    }

    void initPudelko(int x){
        for(int i = 0; i < x; i++){
            for(int j = i; j < x; j++)
                pula[i + j].first = klocek(i, j);
        }
    }

    void dobierz(int player)
    {
        switch(player){
            case 1 :
                if(idx1 >= 7 && idx1 < 21)
                {
                    reka1[idx1]=pula[idxp].first;
                    idx1++;
                    idxp++;
                } 
                else
                {
                    throw std::string("Zly indeks reki gracza 1");
                }
            case 2 :
                if(idx2 >= 7 && idx2 < 21)
                {
                    reka1[idx2]=pula[idxp].first;
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
    klocek& operator =(klocek &block)
    {
        if(this == &block) return *this;
        gora = block.gora;
        dol = block.dol;
        return *this;
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
>>>>>>> ee0a32f44284522bc9e409a80a3141838480b9fa
