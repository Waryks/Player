#include <iostream>
#include "player.h"
#include "test.h"
#include "repo.h"
#include "ui.h"
#include <string.h>

using namespace std;

Console::Console(Service& service) {
    this->s = service;
}

void Console::main_menu()
{
    cout << "1. Add a player" << endl;
    cout << "2. Modify a player" << endl;
    cout << "3. Delete a player" << endl;
    cout << "4. Players that didn't win a single game" << endl;
    cout << "5. Top players" << endl;

}
char* Console::read_player()
{
    char b[100];
    cin >> b;
    char* a = new char[strlen(b) + 1];
    strcpy_s(a, strlen(b) + 1, b);
    return a;
}

int Console::run()
{
    cout << "Merge";
    int op = 0;
    bool work = 0;
    while (work == 0)
    {
        this->main_menu();
        cin >> op;
        if (op == 1)
        {
            cout << "Name of the player: ";
            char* player = this->read_player();
            cout << "Number of played games: ";
            int numPlayed = 0;
            cin >> numPlayed;
            int numWin = -1;
            cout << "Write the number of wins: ";
            cin >> numWin;
            while ((numPlayed < numWin) || (numWin = -1))
            {
                cout << "Write the number of wins (correctly this time): ";
                cin >> numWin;
            }
            this->s.add_player(numWin, numPlayed, player);
        }
        else if (op == 2)
        {
            cout << "The name of the player that u wish to modify: ";
            char* player1 = this->read_player();
            cout << "The new name of that player: ";
            char* player2 = this->read_player();
            cout << "The number of games: ";
            int numPlayed;
            cin >> numPlayed;
            cout << "The number of wins: ";
            int numWin = 0;
            cin >> numWin;
            while ((numPlayed < numWin) || (numWin = -1))
            {
                cout << "Write the number of wins (correctly this time): ";
                cin >> numWin;
            }
            this->s.update_player(player1, numWin, numPlayed, player2);
        }
        else if (op == 3)
        {
            cout << "The name of the player that u wish to delete: ";
            char* player = this->read_player();
            this->s.remove_player(player);
        }
        else if (op == 4)
        {
            this->s.players_noWins();
        }
        else if (op == 5)
        {
            this->s.order_byWins();
            Player* players;
            players = this->s.getAll();
            int len = this->s.getSizeRepo();
            for (int i = 0; i < len; i++)
                cout << "Player: " << players[i].getName() << " Wins: " << players[i].getNoWins() << 'n';
        }
        else
            return 0;
    }
}
