#pragma once
#include "serv.h"
#include "player.h"
#include "serv.h"
class Console {
private:
    Service s;
    void main_menu();
    char* read_player();
public:
    Console() {};
    Console(Service& service);
    ~Console() {};
    int run();

};