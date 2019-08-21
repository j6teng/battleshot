#include "game.h"
#include <iostream>
#include <cstdlib>


using namespace std;

game::game(int n){
	num = n;
}

void game::init_player(){
	bslog* mylog = new bslog();
	srand(time(0));
	for(int i = 0;i<num;i++){
		int vx = rand() % 10;
	    int vy = rand() % 10;
	    player* myplayer = new player(vx,vy);
	    mylog->loginit(i,vx,vy);
	 //   cout <<"initial coordinate of player "<< i <<" is ("<<vx <<","<<vy <<")"<<endl;
	    myplayer->setid(i);
	    plist.push_back(myplayer);
	}
}

void game::eliminate_death(){
	for (int i = 0;i<plist.size();i++){
		if(!plist[i]->status()){
			plist.erase(plist.begin()+i);
		}
	}
}

void game::game_start(){
	bslog* mylog = new bslog();
	int round = 0;
	for(int i = 0; i < plist.size();i++){
		if(plist.size() == 1) break;
		int vx = rand() % 10;
	    int vy = rand() % 10;
	    int enemyID;
	    if(i==0) {
	    	enemyID=plist[plist.size()-1]->getid();
	    }else{
	    	enemyID = plist[i-1]->getid(); 
	    }
	    mylog->logattack(plist[i]->getid(),enemyID,vx,vy);
	  //  cout <<"player "<< plist[i]->getid()<<" being attacked by player "<<enemyID<<" at ("<<vx <<","<<vy <<")"<<endl;
	    bool result = plist[i]->if_click(vx,vy);
	    if(result){
	    	mylog ->logdead(plist[i]->getid());
	    //	cout<<"player "<<plist[i]->getid()<<" dead"<<endl;
	    	plist[i]->kill();
	    }
	}
}


void game::game_error(string errmsge){
	bslog* mylog = new bslog();
	mylog->logerror(errmsge);
}


void game::game_msge(string msge,int num){
	bslog* mylog = new bslog();
	mylog->logmsge(msge,num);
}


bool game::game_end(){
	bslog* mylog = new bslog();
	if(plist.size() == 1){
		mylog->logend(plist[0]->getid(),1);
		cout << "the winner is player No. " << plist[0]->getid() << endl; 
		cout << "See the log for battle details"<<endl;
		return true;
	}else if(plist.size() == 0){
		mylog->logend(0,0);
		cout << "No winner for this game since players dead at same time" << endl; 
		cout << "See the log for battle details"<<endl;
		return true;
	}else{
		return false;
	}
}







