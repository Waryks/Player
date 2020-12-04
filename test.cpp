#include <iostream>
#include <assert.h>
#include "player.h"
#include "repo.h"
#include "serv.h"
#include <string.h>

void testPlayer() {
	char* a;
	a = new char[6];
	strcpy_s(a,6, "Ghita");
	Player p(2312, 10000, a);
	assert(p.getNoWins() == 2312);
	assert(p.getNoPlayed() == 10000);
	assert(strcmp(p.getName(), "Ghita") == 0);
	Player p1 = p;
	assert(p1.getNoWins() == p.getNoWins());
	assert(p1.getNoPlayed() == p.getNoPlayed());
	assert(strcmp(p1.getName(), p.getName()) == 0);
}

void testRepo() {
	Repo repo;
	char* a;
	a = new char[6];
	strcpy_s(a, 6, "Stefa");
	Player p1(321, 400, a);
	strcpy_s(a, 6, "Alexa");
	Player p2(123, 400, a);

	repo.addPlayer(p1);
	repo.addPlayer(p2);

	assert(repo.getNumberOfPlayers() == 2);
	assert(repo.getAllPlayers()[0].getNoWins() == p1.getNoWins());
	assert(repo.getAllPlayers()[1].getNoWins() == p2.getNoWins());
}
void testService() {
	Repo repo;
	char* a;
	a = new char[6];
	strcpy_s(a, 6, "Ghita");
	Player p1(4234, 600000, a);
	strcpy_s(a, 6, "Ionut");
	Player p2(21432, 600000, a);
	repo.addPlayer(p1);
	repo.addPlayer(p2);
	Service serv(repo);
	strcpy_s(a, 6, "Mihai");
	serv.add_player(23123, 432523, a);
	assert(serv.getSizeRepo() == 3);
	serv.remove_player(a);
	assert(serv.getSizeRepo() == 2);
}

