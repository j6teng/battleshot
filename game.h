#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "bslog.h"


using namespace std;


class game{
	int num;
	
public:	
	game(int num);
	bslog* mylog;
	std::vector<player*> plist;
	void init_player();
	void eliminate_death();
	void game_start();
	bool game_end();
	void game_error(string errmsge);
	void game_msge(string msge,int num);


};

#endif