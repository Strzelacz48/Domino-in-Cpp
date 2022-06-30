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
// Game1
void Game1::start()
{
    shuffle_pudelko();
    drukuj();
    for (int i = 0; i < 7; i++)
    {
        dobierz(1);
        dobierz(2);
    }
    left1 = 7;
    left2 = 7;
    reka(1);
    reka(2);
    // cout << "Przed tym powinny byc wypisne tablice \n";
    int indeks, x, y, kierunek, pom;
    klocek a = klocek(0, 0);
    // pierwszy wpis
    reka(1);
    cout << "Wybierz klocek z reki gdzie go wlozyc i w ktorym kierunku(1-gora 2-lewo 3-dol 4-prawo): ";
    cin >> indeks >> x >> y >> kierunek;
    a = P1[indeks];
    add(a, x, y, kierunek);
    P1[indeks] = klocek(-1, -1);
    left1--;
    drukuj();

    while (!end())
    {
        reka(2);
        cout << "Wybierz klocek z reki gdzie go wlozyc i w ktorym kierunku(1-gora 2-lewo 3-dol 4-prawo): ";
        cin >> indeks;
        // cout << "Czy chcesz wlozyc na gore(1) czy na dol(2): ";
        // cin >> pom;
        // if (pom == 1)
        //     // a = P2[indeks];
        //     // else
        //     // a = klocek(board.P2[indeks].dol, board.P2[indeks].gora);
        cin >> x >> y >> kierunek;
        if (indeks < 0 || indeks > idx2)
        {
            cout << "Nie ma takiego klocka" << endl;
            continue;
        }
        if (add2(P2[indeks], x, y, kierunek))
        {
            cout << "Dodano klocek" << endl;
            P2[indeks] = klocek(-1, -1);
            left2--;
            // break;
        }
        else
            cout << "Nie mozna dodac klocka" << endl;

        drukuj();
        reka(1);
        cout << "Wybierz klocek z reki gdzie go wlozyc i w ktorym kierunku(1-gora 2-lewo 3-dol 4-prawo): ";
        cin >> indeks;
        /*cout << "Czy chcesz wlozyc na gore(1) czy na dol(2): ";
        cin >> pom;
        if (pom == 1)
            a = P1[indeks];
        else
        {
            int pom1 = P1[indeks].dol;
            int pom2 = P1[indeks].gora;
            cout << "pom1 : " << pom1 << " pom2 : " << pom2 << "\n";
            // a = klocek(pom1, pom2);
        }*/
        cin >> x >> y >> kierunek;
        if (indeks < 0 || indeks > idx1)
        {
            cout << "Nie ma takiego klocka" << endl;
            continue;
        }
        if (add2(P1[indeks], x, y, kierunek))
        {
            cout << "Dodano klocek" << endl;
            P1[indeks] = klocek(-1, -1);
            left1--;
            // break;
        }
        else
            cout << "Nie mozna dodac klocka" << endl;

        drukuj();
    }
}
bool Game1::end()
{
    if (left1 == 0)
    {
        cout << "Wygral gracz 1\n";
        return true;
    }
    else if (left2 == 0)
    {
        cout << "Wygral gracz 2\n";
        return true;
    }
    return false;
}
void Game2::start()
{
    shuffle_pudelko();
    drukuj();
    for (int i = 0; i < 7; i++)
    {
        dobierz(1);
        dobierz(2);
    }
    wynik1 = 0;
    wynik2 = 0;
    reka(1);
    reka(2);
    // cout << "Przed tym powinny byc wypisne tablice \n";
    int indeks, x, y, kierunek, pom;
    klocek a = klocek(0, 0);
    // pierwszy wpis
    reka(1);
    cout << "Wybierz klocek z reki gdzie go wlozyc i w ktorym kierunku(1-gora 2-lewo 3-dol 4-prawo): ";
    cin >> indeks >> x >> y >> kierunek;
    a = P1[indeks];
    add(a, x, y, kierunek);
    if (suma() % 5 == 0)
        wynik += suma;
    P1[indeks] = klocek(-1, -1);
    drukuj();
    while (!end())
    {
        reka(2);
        cout << "Wybierz klocek z reki gdzie go wlozyc i w ktorym kierunku(1-gora 2-lewo 3-dol 4-prawo): ";
        cin >> indeks;
        cin >> x >> y >> kierunek;
        if (indeks < 0 || indeks > idx2)
        {
            cout << "Nie ma takiego klocka" << endl;
            continue;
        }
        if (add2(P2[indeks], x, y, kierunek))
        {
            cout << "Dodano klocek" << endl;
            P2[indeks] = klocek(-1, -1);
            if (suma() % 5 == 0)
                wynik2 += suma;
            // break;
        }
        else
            cout << "Nie mozna dodac klocka" << endl;

        drukuj();
        reka(1);
        cout << "Wybierz klocek z reki gdzie go wlozyc i w ktorym kierunku(1-gora 2-lewo 3-dol 4-prawo): ";
        cin >> indeks;

        cin >> x >> y >> kierunek;
        if (indeks < 0 || indeks > idx1)
        {
            cout << "Nie ma takiego klocka" << endl;
            continue;
        }
        if (add2(P1[indeks], x, y, kierunek))
        {
            cout << "Dodano klocek" << endl;
            P1[indeks] = klocek(-1, -1);
            if (suma() % 5 == 0)
                wynik1 += suma;
            // break;
        }
        else
            cout << "Nie mozna dodac klocka" << endl;

        drukuj();
    }
}
int Game2::suma()
{
    int suma = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            suma += board[i][j];
        }
    }
    return suma;
}
bool Game2::end()
{
    if (wynik1 >= 100)
    {
        cout << "Wygral gracz 1\n";
        return true;
    }
    else if (wynik2 >= 100)
    {
        cout << "Wygral gracz 2\n";
        return true;
    }
    return false;
}
