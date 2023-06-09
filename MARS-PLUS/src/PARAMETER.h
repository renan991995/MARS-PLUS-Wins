#ifndef PARAMETER_H
#define PARAMETER_H
#include <sys/types.h>
#include <dirent.h>
#include <cerrno>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <vector>
#include <ctime>
#include <cstdio>
#include <cctype>
#include <sstream>
using namespace std;


class PARAMETER {
	public :
		PARAMETER () {
			/*
		    system("pwd > pwddir.txt");
		    ifstream PWD("pwddir.txt");
		    pwd="";
		    PWD >> pwd >> ws;
		    PWD.close();
			system("rm pwddir.txt 2> /dev/null");
			*/
			
			char* b1 = NULL;	
			b1 = _getcwd( NULL, 0 );
			pwd = b1;
			free(b1);
			cout << "Current path: " << pwd << endl;
			
			/*
			for (unsigned int q=0;q<pwd.length();q++) {
				if (pwd[q]=='\\') {
					//pwd.insert(pwd.begin()+q,'\\');
					//q++;
					pwd[q]='/';
				}	
			}
			*/
   			
			programdir = pwd+"/src/";
			logdir = pwd+"/LOG_FILES/";
			
			gssize=0;
			ion=0;		
			protect=0;
			enumeration=0;
			redu_duplicates=0;
			operation="All";
			obabel="";
			round=1;
			epoch=1;
			mdsdir=logdir+"mds/";
			ifwritemds=0;
			element_list="none";
			glbouf.close();
			glbouf1.close();
			stat.close();
		}
		~PARAMETER() {
			glbouf.close();
			glbouf1.close();
			stat.close();
		}
		int gssize;
		string guess;
		string logdir;
		string operation;
		string obabel;
		bool ion;
		bool protect;
		bool enumeration;
		bool ifwritemds;
		bool redu_duplicates;
		int round;
		int epoch;
		string programdir;
		string element_list;
		string pwd;	
		string mdsdir;
		ofstream glbouf;
		ofstream glbouf1;
		ofstream stat;
};


#endif

