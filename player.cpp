#include "player.h"
#include <cstdlib>

using namespace std;

player::player(int x,int y){
	if_live = true;
	x_coor = x;
	y_coor = y;
}



bool player::if_click(int x, int y){
	if(x == x_coor && y == y_coor){
		return true;
	}else{
		return false;
	}
}

void player::kill(){
	this->if_live = false;
}

bool player::status(){
	return if_live;
}

void player::setid(int i){
	ID = i;
}

int player::getid(){
	return ID;
}