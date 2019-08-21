#include "bslog.h"
#include<string>
#include<iostream>
#include<sstream>


using namespace std;

bslog::bslog(){
	time_t now = time(0);
    struct tm tstruct;
    char buf1[80];
    tstruct = *localtime(&now);
    strftime(buf1,sizeof(buf1),"%Y-%m-%d",&tstruct);
    stringstream ss;
//init the filename
    ss<<buf1<<".txt";
    ss>>filename;
    ofile.open(filename,ostream::out|ofstream::app);
//init the file;


}

string bslog::getcurrenttime(){
	time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf,sizeof(buf),"%Y-%m-%d.%X",&tstruct);
    stringstream ss;
    string currenttime;
    ss<<buf;
    ss>>currenttime;
    return currenttime;
}


void bslog::loginit(int pid, int vx, int vy){
	string ct = getcurrenttime();
	ofile <<"["<<ct<<"] "<<"initial coordinate of player "<< pid <<" is ("<<vx <<","<<vy <<")"<<endl;
}


void bslog::logattack(int pid, int eid,int vx, int vy){
	string ct = getcurrenttime();
	ofile << "["<<ct<<"] "<<"player "<< pid<<" being attacked by player "<<eid<<" at ("<<vx <<","<<vy <<")"<<endl;

}


void bslog::logdead(int pid){
	string ct = getcurrenttime();
    ofile <<"["<<ct<<"] "<<"player "<<pid<<" dead"<<endl; 
}



void bslog::logend(int pid,int idx){
    if(idx == 1){
	    string ct = getcurrenttime();
        ofile <<"["<<ct<<"] "<< "the winner is player No. " << pid << endl; 
        ofile<<"Game End Properly"<<"                         "<<ct<<endl;
        ofile<<"********************************logend********************************"<<endl;
        ofile.close();
    }else{
        string ct = getcurrenttime();
        ofile <<"["<<ct<<"] "<< "No winner for this game since players dead at same time" << endl; 
        ofile<<"Game End Properly"<<"                         "<<ct<<endl;
        ofile<<"********************************logend********************************"<<endl;
        ofile.close();

    }
}

void bslog::logmsge(string msge,int num){
    string ct = getcurrenttime();
    ofile<<"["<<ct<<"] "<< msge <<num<<endl;
}


void bslog::logerror(string errmsge){
	string ct = getcurrenttime();
	ofile<<"["<<ct<<"] "<< errmsge <<endl;
	ofile<<"Game End With Error"<<"                         "<<ct<<endl;
	ofile<<"********************************logend********************************"<<endl;
	ofile.close();
}
















