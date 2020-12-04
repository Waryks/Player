#pragma once
#include "player.h"
#include "repo.h"
#include <iostream>
class Service {
    Repo r;
public:
    Service() {};
    Service(Repo& repo);
    ~Service() {};
    void add_player(int numWin, int numPlayed, char* pName);
    void remove_player(char* pName);
    void update_player(char* p1Name, int n2Win, int n2Played, char* p2Name);
    void players_noWins();
    void order_byWins();
    Player* getAll();
    int getSizeRepo();
};