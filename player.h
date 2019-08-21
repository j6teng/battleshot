#ifndef PLAYER_H
#define PLAYER_H
#include<vector>

class player{

	bool if_live;
	int x_coor;
	int y_coor;
	int ID;

public:
	player(int x,int y);
	bool if_click(int x, int y);
	void kill();
	bool status();
	void setid(int i);
	int getid();

};
#endif


