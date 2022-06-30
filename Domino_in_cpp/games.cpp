#include "header.hpp"
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
    cout << "Reka 1 gracza :  \n";
    int indeks, x, y, kierunek, pom;
    klocek a = klocek(0, 0);
    // pierwszy wpis
    reka(1);
    cout << "Wybierz klocek z reki gdzie go wlozyc i w ktorym kierunku(1-gora 2-lewo 3-dol 4-prawo): ";
    cin >> indeks >> x >> y >> kierunek;
    a = P1[indeks];
    add(a, x, y, kierunek);
    P1[indeks] = help[0];
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
            P2[indeks] = help[0];
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
            P1[indeks] = help[0];
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
    klocek a(0, 0);
    // pierwszy wpis
    //reka(1);
    cout << "Wybierz klocek z reki gdzie go wlozyc i w ktorym kierunku(1-gora 2-lewo 3-dol 4-prawo): ";
    cin >> indeks >> x >> y >> kierunek;
    a = P1[indeks];
    add(a, x, y, kierunek);
    if (suma() % 5 == 0)
        wynik1 += suma();
    P1[indeks] = klocek(-1,-1);//help[0];
    cout<< "\nWynik gracza 1 : "<<wynik1<<"\nWynik gracza 2 : "<<wynik2<<"\n";
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
            P2[indeks] = help[0];
            if (suma() % 5 == 0)
                wynik2 += suma();
            // break;
        }
        else
            cout << "Nie mozna dodac klocka" << endl;
        cout<< "\nWynik gracza 1 : "<<wynik1<<"\nWynik gracza 2 : "<<wynik2<<"\n";
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
            P1[indeks] = help[0];
            if (suma() % 5 == 0)
                wynik1 += suma();
            // break;
        }
        else
            cout << "Nie mozna dodac klocka" << endl;
        cout<< "\nWynik gracza 1 : "<<wynik1<<"\nWynik gracza 2 : "<<wynik2<<"\n";
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
//Game3
void Game3::start()
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
    klocek a(0, 0);
    // pierwszy wpis
    //reka(1);
    cout << "Wybierz klocek z reki gdzie go wlozyc i w ktorym kierunku(1-gora 2-lewo 3-dol 4-prawo): ";
    cin >> indeks >> x >> y >> kierunek;
    a = P1[indeks];
    add(a, x, y, kierunek);
    if (suma() % 3 == 0)
        wynik1 += suma();
    P1[indeks] = klocek(-1,-1);//help[0];
    cout<< "\nWynik gracza 1 : "<<wynik1<<"\nWynik gracza 2 : "<<wynik2<<"\n";
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
            P2[indeks] = help[0];
            if (suma() % 3 == 0)
                wynik2 += suma();
            // break;
        }
        else
            cout << "Nie mozna dodac klocka" << endl;

        drukuj();
        cout<< "\nWynik gracza 1 : "<<wynik1<<"\nWynik gracza 2 : "<<wynik2<<"\n";
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
            P1[indeks] = help[0];
            if (suma() % 3 == 0)
                wynik1 += suma();
            // break;
        }
        else
            cout << "Nie mozna dodac klocka" << endl;
    cout<< "\nWynik gracza 1 : "<<wynik1<<"\nWynik gracza 2 : "<<wynik2<<"\n";
        drukuj();
    }
}
int Game3::suma()
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
bool Game3::end()
{
    if (wynik1 >= 90)
    {
        cout << "Wygral gracz 1\n";
        return true;
    }
    else if (wynik2 >= 90)
    {
        cout << "Wygral gracz 2\n";
        return true;
    }
    return false;
}