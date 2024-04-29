//week 13 jaedon wallace coding 1
// cool stuff Header files and reading and writing to file
#include "includes.h"
#include "functions.h" // referancing header file
#include "robot.h"
#include "qualityOfLife.h"
#include <fstream> // for input and putput of files

int main() {
  cout << "Hello World!\n";
	Hellow();  // header file code

	// create a new header file named classes. h with a robot class.
	// then include it to create a robot here
	Robot robert;
	robert.MyName();
	cout<<robert.GetPower();
	cout<<robert.TripleStr("billy");
	ofstream file;
	
	file.open("names.txt");
		file<< "billy\njoel\nbob\n";
	file.close();

	// a new variable with the type ifstream named read from file
	
	ifstream readFromFile ("names.txt");
	string line;
	if(readFromFile.is_open()){
		while(getline(readFromFile, line))
			{
				Say(line);
			}
		readFromFile.close();
	} else{
		Say("Could not read from file");
	}

	Log("this is dev only text\n");
	Say("this is user readable text");
	Say(NewLine(3));
	Say("did it?");
}