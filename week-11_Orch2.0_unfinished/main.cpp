// Week 11.2 Jaedon Wallace
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool debug = true;

void devPrint(string input = "Help!"){cout<<input<<"\n";}
// an enumerator is a custom varible that evaluates to an intager.
enum itemType{
//  0 1 and 2
	weapon, tool, consumable
};

enum elementalType{
//  0 1 and 2
	basic, fire , ice , candy , slime 
};

// create a class with a constructor, it is named enemy, take notes from the adventure assignemnt
class item{
public:
	itemType type = weapon;
	int damage = 13;
	string wepName = "UNDEFINED WEAPON!";
	elementalType element = basic;
	int toolHealth;
	int healingAmount;

//// overloading the Constructor Start
	item(string n = "UnNamedWeapon", itemType t = weapon)
	{
		wepName = n;
		type = t;

		if(type == weapon){
			// calculate damage.and element
			damage = rand()% 5 +3;
			element = (elementalType)(rand()%4);//type cast an int into an elementalType
			toolHealth = 9999;
			healingAmount = 0;

		}
		if(type == tool){
			damage = 1;
			element = basic;
			toolHealth = rand()%5 +1;
			healingAmount = 0;
		}
		if(type == consumable){
			healingAmount = rand()%5+1;
			damage = -healingAmount;
			element = basic;
			toolHealth = 1;
		}
	}
///Constructor End

	void Inspect()
	{
		cout << wepName<<" has a damage of "<< damage<<", it's element is "<< element<<"\n it can be used "<<toolHealth<<" more times, heals for "<<healingAmount<<". It is of the item type "<< typeToString(type) <<".\n\n";
	}
	string typeToString(itemType type)
	{
		// this is a switch statement, it is similar to an if statement, but it only tests once
		// all possible values are mapped,
		switch(type)
		{
			case weapon: 
				return "weapon";
					break;// break make sures it stops cheking.
			case tool: 
				return "tool";
					break;
			case consumable: 
				return "consumable";
					break;
		}
	}
	string GetName(){
		return wepName;
	}
	int GetDmg(){
		return damage;
	}

	string ElementToString(elementalType element)
	{
		switch(element)
		{
			case basic: 
				return "basic";
					break;// break make sures it stops cheking.
			case fire: 
				return "fire";
					break;
			case ice: 
				return "ice";
					break;
			case candy: 
			return "candy";
				break;
			case slime: 
			return "slime";
				break;
			default: return "unknown";
		}
	}

};

class character{
	private:
	item heldItem;
	int health;
	int gold;
	int boost;
	string myWeapon;
	int weaponId;
	string race;
	string name;
	int agression;

	public:
//enemy(randRace,randName, health, agression, weapon[X])
	character(string defName = "kenny", string defRace = "Human", int defHp = 5, int defAgr = 5, /*int wepID = 0, string wepName = "DefWep",*/ item givenItem = item(), int inGold = 0,int inBoost =0)//:heldItem(item("sward",weapon))
	{
		devPrint("Character COnstructor sucsess");	
		heldItem = givenItem;
		gold = inGold;
		name = defName;
		race = defRace;
		health = defHp;
		agression = defAgr;
		boost = inBoost;
	}
	void Inspect(){
		cout<<race<<" "<<name<<" has entered the fight!";
		if(agression < 3){
			cout<< "( they look like they dont want to be here. )";
		}
		cout<< "\nThey are holding "<< heldItem.GetName() << "!\n";
	}
	int GetWepID(){ return weaponId; }
	int GetGold(){return gold;}
	int AddGold(int x = 0){gold = gold+x; return gold;}
	int GetHp(){return health;}
	string GetName(){return name;}
	int GetAggr(){return agression;}

	
	

};

//encounter loop

// Game initiates recruiter()
// Recruiter()
// 	for i < x
//		enemy(randRace,randName, health, agression, weapon[X])


// player
	// health.
	// invertory array
	// damage bonus,
	// gold
	// luck = rand%5
// get set, ect.

// into text,

//// game loop
	// for y number of rounds
// player meets and orc
// what does the player want to do?
	// run : if the players luck is greater than the enemys agression
	// use wepon.
	// use item.
		// flower: pacifyes enemy. returns no loot, 
	// use consumable.

				// enemy attacks, (if 0 agression and player does not attack they will run away)
//Enum Round()
	// int DmgIN
	// bool win
	// if enemy[y].GetAgression.{  
			// cout<< you are chaleneged by Enemy.race Enemy.Name.
			// cout<< they are using the wepon Enemy.wepon
			//DmgIn = enemy[Y].Attack()
	//}
	// else{
		//Cout enemy is a coward or something.
		// they are holding enemy.weapon
	//}

	// while != win && PlayerAlive. (repeats untill enemy or player is dead)
				// Attack, show inventory use item(which item 1-x?; cin<x)
		// if...
		// showInventory()
	   	// useItem(item) (sets player.using item to 1, wich means that player.attack() returns 0)
		// run() 
			// if luck> enemy[x].Agression: break;

		// win = battle(DmgIn)
			//comare x == player.GetAtack and DmgIn
			// if player attack is greater
				//Enemy.takeDamage(x)
				//player.takeDamage(1)
			// if enemy is greater
				// player.TakeDamage(DmgIn)
				//Enemy.TakeDamage(1)
			// if enemy is still alive
				// return 0 say "enemy[x] has died"
			// enemy dead
				//geTloot()
				// if enemy has an item.
					// player items.push_Back(enemy.Weapon)
				// player.GiveGold(enemy[x].getGold())
				// return 1
		//
	// if player is still alive
		//cout<< you win this round, there are still X-max rounds, left, keep playing?
		// if keep playing return 1
	// if player is dead
		//gameOver()	
	//}
	
		


	
			
			
		
// outro text

int main() {

	devPrint("Starting main!\n");
	vector<string> weaponNames { 
	"Sword", 
	"Axe", 
	"Hammer", 
	"Bow", 
	"Scythe", 
	"Trident", 
	"Spear", 
	"club", 
	"Mace",
	"Half Sword",
	"Jaw Bone"
	};
	devPrint("Created weapons\n");
	random_shuffle(weaponNames.begin(),weaponNames.end());

	vector<item> weapons;

	for(int i = 0; i < weaponNames.size(); i++){
		weapons.push_back(item(weaponNames[i], weapon));// create a weapon
		//weapons[i].Inspect();
	}
	
	vector<string> GladNames { 
	"Gorbash", 
	"Grum", 
	"Glubdub", 
	"Morg", 
	"Skab", 
	"Snarl", 
	"Ugluk", 
	"Grishnakh", 
	"Snaga", 
	"Mauhur" 
	};
	random_shuffle(GladNames.begin(),GladNames.end());
	devPrint("got Gladiator names\n");
		
	vector<string> GladRaces { "Human", "Elf", "Orc", "Dwarf", "Halfling" };
	vector<character> gladiator;
	devPrint("started gladiator vector!\n");
	
	for(int i = 0; i < GladNames.size(); i++){
		gladiator.push_back(character(GladNames[i], GladRaces[rand()%5], rand()%5+10, rand()%5, weapons[i], /*i, weapons[i].GetName()*/rand()%5+10,0));
	}
	devPrint("Hired Gladiators!\n");
	string playerName;
	cout<<"\nWhat is your name?\n";
	cin >> playerName;
	character player(playerName,"Human",20, rand()%3+2, weapons[0] , 0,0);
	cout<<"Greetings "<< player.GetName()<<"!\n";

	

}

/* 
	enum
	switch
*/