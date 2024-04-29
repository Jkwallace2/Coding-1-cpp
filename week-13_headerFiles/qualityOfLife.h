#include "includes.h"

bool devMode = 1;


void Say(string input = "\n") {
  cout << input << "\n";
}

void Log(string input = "devtext"){
	if (devMode){cout<<"\n" << input << "\n";}
}

string NewLine(int repeat){
	string nl = "\n";
	for (int i = 0; i< repeat; i++){
		nl + nl;
	}
	return nl;
}