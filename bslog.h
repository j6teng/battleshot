#ifndef BSLOG_H
#define BSLOG_H
#include <ctime> 
#include<string>
#include<fstream>

using namespace std;

class bslog{
	string currentime;
	string filename;
	ofstream ofile;

public:
	bslog();
	string getcurrenttime();
	//void logbegin();
	void loginit(int pid, int vx, int vy);
	void logattack(int pid, int eid,int vx, int vy);
	void logdead(int pid);
	void logend(int pid,int idx);
	void logmsge(string msge,int num);
	void logerror(string errmsge);




};

#endif