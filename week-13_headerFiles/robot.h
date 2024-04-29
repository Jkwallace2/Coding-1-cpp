#include "includes.h"

class Robot{
	private:
	string name = "robert";
	int power = 10;
	
	public:
	void MyName(){
		cout<<"my name is "<<name<<"!\n";
	}
	int GetPower(){
		return power;
	}
	int TrippleInt(int num){
		return num * num * num;
	}
	string TripleStr(string str){
		return str + str + str;
	}
	
};