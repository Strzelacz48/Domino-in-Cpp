#include "header.hpp"
#include "plansza.cpp"
void Game1::start()
{
    board.shuffle_pudelko();
    board.drukuj();
    for (int i = 0; i < 7; i++)
    {
        dobierz(1);
        dobierz(2);
    }
    board.reka(1);
    board.reka(2);
    int indeks;
    cout << "Pierwszy gracz może położyć domino na planszy.\n indeks na w ręce: ";
    while (true)
    {
        cout << "Wybierz klocek: ";
        cin >> indeks;
        if (indeks < 0 || indeks > 21)
        {
            cout << "Nie ma takiego klocka" << endl;
            continue;
        }
        if (board.add2(board.P1[indeks], 0, 0, 0))
        {
            cout << "Dobrze" << endl;
            board.drukuj();
            board.reka(1);
            board.reka(2);
        }
        else
        {
            cout << "Zle" << endl;
            board.drukuj();
            board.reka(1);
            board.reka(2);
        }
    }
}