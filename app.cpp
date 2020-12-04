#include <iostream>
#include "test.h"
#include "ui.h"
#include "repo.h"
#include "serv.h"
#include "player.h"

using namespace std;

int main()
{
	testPlayer();
	testRepo();
	Repo rep;
	Service serv(rep);
	Console c(serv);
	c.run();
	return 0;
}
