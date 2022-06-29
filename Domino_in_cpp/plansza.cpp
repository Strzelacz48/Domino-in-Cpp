#include "header.hpp"
// plansza
using namespace std;
plansza::plansza()
{
    //size = 9;
    //klocek **board = new klocek *[size];
    for (int i = 0; i < 9; i++)
    {
        for(int j=0;j<9;j++)
        {
            board[i][j]=-1;
        }
    }
}
void plansza::drukuj()
{
    for (int i = 0; i < 9; i++)
    {
        cout<<" ";
        for(int j=0;j<9;j++)
        {
            if(board[i][j]!=-1)
                cout<<board[i][j]<<" ";
            else
                cout<<"X ";
        }
        cout<<"\n";
    }
}
void plansza::add(klocek a,int x, int y,int kierunek)
{
    board[x][y]=a.gora;
    switch (kierunek){
        case 1://gora
            {if(x==0)
                throw("Wyjscie poza plansze");
            else
            {
                board[x-1][y]=a.dol;
            }
            break;
            }
        case 2://lewo
            {if(y==0)
                throw("Wyjscie poza plansze");
            else
            {
                board[x][y-1]=a.dol;
            }
            break;
            }
        case 3://dol
            {if(x==8)
                throw("Wyjscie poza plansze");
            else
            {
                board[x+1][y]=a.dol;
            }
            break;
            }
        case 4://prawo
            {if(y==8)
                throw("Wyjscie poza plansze");
            else
            {
                board[x][y+1]=a.dol;
            }
            break;
            }
    }
}
void plansza::dobierz(int player)
{
    switch(player)
    {
    case 1:
        {
            P1[idx1]=pudelko[idxp];
            idx1++;
            idxp++;
        }
    case 2:
        {
            P2[idx2]=pudelko[idxp];
            idx2++;
            idxp++;
        }
    }
}
bool plansza::check(klocek a)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]==a.gora)
            {
                if(i>=2 && board[i-1][j]==-1 && board[i-2][j]==-1)
                    return true;
                if(i<=6 && board[i+1][j]==-1 && board[i+2][j]==-1)
                    return true;
                if(j>=2 && board[i][j-1]==-1 && board[i][j-2]==-1)
                    return true;
                if(j<=6 && board[i][j+1]==-1 && board[i][j+2]==-1)
                    return true;
            }
            if(board[i][j]==a.dol)
            {
                if(i>=2 && board[i-1][j]==-1 && board[i-2][j]==-1)
                    return true;
                if(i<=6 && board[i+1][j]==-1 && board[i+2][j]==-1)
                    return true;
                if(j>=2 && board[i][j-1]==-1 && board[i][j-2]==-1)
                    return true;
                if(j<=6 && board[i][j+1]==-1 && board[i][j+2]==-1)
                    return true;
            }
        }
    }
    return false;
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
