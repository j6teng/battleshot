#include "game.h"
#include <iostream>
#include <string>


using namespace std;

int main(int argc,char*argv[]){
	cout<<"Please enter the number of players (1-10000)"<<endl;
	int num;
	if(! (cin >> num)){
		cerr << "ERROR:wrong number received" << endl;
	}
	if(num < 1 || num > 10000){
		cerr<<"ERROR: input should be in (1-10000)"<<endl;
		return 0;
	}

	game *newgame = new game(num);
	newgame->init_player();
	int i=0;
	string pause;
	cout<<"Start? (Type in 'Yes' to start the game)"<<endl;
	cin>>pause;
	if(pause != "Yes"){
		newgame->game_error("ERROR: wrong start command" );
		cerr << "ERROR: wrong start command" << endl;
		return 0;
	}
	while(!newgame->game_end()){
		newgame->game_msge("Round End ",i+1);
	//	cout<<"Round "<<i<<endl;
		newgame->eliminate_death();
		newgame->game_start();
		
		i++;
	}
	return 0;



}