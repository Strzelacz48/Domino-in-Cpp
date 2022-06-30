#include "header.hpp"
// plansza
using namespace std;
void swap(klocek &a, klocek &b)
{
    klocek temp = a;
    a = b;
    b = temp;
}
plansza::plansza()
{
    // size = 9;
    // klocek **board = new klocek *[size];
    // initialization of P1 and P2

    klocek *P1 = new klocek[21];
    klocek *P2 = new klocek[21];
    idx1 = 0;
    idx2 = 0;
    idxp = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            board[i][j] = -1;
        }
    }
}
void random_shuffle(klocek *begin, klocek *end)
{
    srand(time(NULL));
    for (klocek *i = begin; i < end; i++)
    {
        klocek *j = begin + rand() % (end - begin);
        swap(*i, *j);
    }
}
void plansza::shuffle_pudelko()
{
    random_shuffle(pudelko, pudelko + 28);
}
void plansza::drukuj()
{
    for (int i = 0; i < 9; i++)
    {
        cout << " ";
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != -1)
                cout << board[i][j] << " ";
            else
                cout << "X ";
        }
        cout << "\n";
    }
}
void plansza::add(klocek a, int x, int y, int kierunek)
{
    board[x][y] = a.gora;
    switch (kierunek)
    {
    case 1: // gora
    {
        if (x == 0)
            throw("Wyjscie poza plansze");
        else
        {
            board[x - 1][y] = a.dol;
        }
        break;
    }
    case 2: // lewo
    {
        if (y == 0)
            throw("Wyjscie poza plansze");
        else
        {
            board[x][y - 1] = a.dol;
        }
        break;
    }
    case 3: // dol
    {
        if (x == 8)
            throw("Wyjscie poza plansze");
        else
        {
            board[x + 1][y] = a.dol;
        }
        break;
    }
    case 4: // prawo
    {
        if (y == 8)
            throw("Wyjscie poza plansze");
        else
        {
            board[x][y + 1] = a.dol;
        }
        break;
    }
    }
}
bool plansza::add2(klocek a, int x, int y, int kierunek)
{
    if (board[x][y] != -1 || (board[x][y - 1] != a.gora && board[x][y + 1] != a.gora && board[x - 1][y] != a.gora && board[x + 1][y] != a.gora))
        return false;
    switch (kierunek)
    {
    case 1: // gora
    {
        if (x == 0)
            return false;
        else
        {
            board[x][y] = a.gora;
            board[x - 1][y] = a.dol;
        }
        break;
    }
    case 2: // lewo
    {
        if (y == 0)
            return false;
        else
        {
            board[x][y] = a.gora;
            board[x][y - 1] = a.dol;
        }
        break;
    }
    case 3: // dol
    {
        if (x == 8)
            return false;
        else
        {
            board[x][y] = a.gora;
            board[x + 1][y] = a.dol;
        }
        break;
    }
    case 4: // prawo
    {
        if (y == 8)
            return false;
        else
        {
            board[x][y] = a.gora;
            board[x][y + 1] = a.dol;
        }
        break;
    }
    }
    return true;
}
void plansza::dobierz(int player)
{
    switch (player)
    {
    case 1:
    {
        P1[idx1] = pudelko[idxp];
        idx1++;
        idxp++;
        break;
    }
    case 2:
    {
        P2[idx2] = pudelko[idxp];
        idx2++;
        idxp++;
        break;
    }
    }
}
bool plansza::check(klocek a)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == a.gora)
            {
                if (i >= 2 && board[i - 1][j] == -1 && board[i - 2][j] == -1)
                    return true;
                if (i <= 6 && board[i + 1][j] == -1 && board[i + 2][j] == -1)
                    return true;
                if (j >= 2 && board[i][j - 1] == -1 && board[i][j - 2] == -1)
                    return true;
                if (j <= 6 && board[i][j + 1] == -1 && board[i][j + 2] == -1)
                    return true;
            }
            if (board[i][j] == a.dol)
            {
                if (i >= 2 && board[i - 1][j] == -1 && board[i - 2][j] == -1)
                    return true;
                if (i <= 6 && board[i + 1][j] == -1 && board[i + 2][j] == -1)
                    return true;
                if (j >= 2 && board[i][j - 1] == -1 && board[i][j - 2] == -1)
                    return true;
                if (j <= 6 && board[i][j + 1] == -1 && board[i][j + 2] == -1)
                    return true;
            }
        }
    }
    return false;
}
void plansza::reka(int player)
{
    switch (player)
    {
    case 1:
    {
        for (int i = 0; i < idx1; i++)
        {
            if (P1[i].gora != -1)
            {
                P1[i].wypisz();
                cout << " ";
            }
        }
        break;
    }
    case 2:
    {
        for (int i = 0; i < idx2; i++)
        {
            if (P2[i].gora != -1)
            {
                P2[i].wypisz();
                cout << " ";
            }
        }
        break;
    }
    }
    cout << "\n";
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
void klocek::wypisz()
{
    cout << gora << "|" << dol;
}

