//week 8 Jaedon wallace
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> SimileYes = {"true", "yes", "sure", "yep",    "y",
                            "yeah", "1",   "ok",   "why not"};

void Print(string input = "\n") {
  cout << input << "\n";
}

// Cout a question to the player returns a Bool based on the response
int RollDie(string prefx, int max = 6, int min = 1, string sufx = "!\n") {
  int x = rand() % max + min;
  cout << prefx << x << sufx;
  return x;
}

bool GetPlayerBool(string question = "") {
  cout << question;
  string input;
  cin >> input;
  // if the player responds any of the reconised versions of yes, return true.
  if (find(SimileYes.begin(), SimileYes.end(), input) !=
      SimileYes.end()) { // Ai showed me the find function.
    return 1;
    // else return false
  }
  return 0;
}

int TakeDamage(int dmg, int block, int hp) {
  if (block >= dmg) {
    cout << "\n You blocked sucessfuly losiing only 1 Hp!\n\n";
    return 1;
  }
  cout << "\n Block failed, Lost " << dmg << " Hp.\n";
  return dmg;
}
string PressAny(string context) {
  Print(context);
  string x;
  cin >> x;
  return x;
}

// go adventuring? y/n //SayGetbool()
// meet ork
// ork rools for an attack
// prees to roll

int Inform(int in, string prefix = "", string suffix = ".\n") {
  // roll the die with how many sides the player responds
  // out put you rolled x !
  // what happens when i enter a int?
  cout << prefix << in << suffix;
  return in;
}

int OrkAttack(bool play, int health) {
  int dmg;
  int block;
  int gold;
  int turns = 0;
  do {
    turns++;
    Print("\nAn Ork appears!");
    dmg = RollDie("The Ork attacks with a power of ");
    PressAny("Press any key to block!");
    block = RollDie("You block with a power of ");
    // if player roll >= ork attack take -1 health, run away get rand gold
    //  if fail take ork attack amount of damage. take no gold
    dmg = TakeDamage(dmg, block, health);
    health = health - dmg;
    if (dmg == 1) {
      gold = RollDie("You ran away and found ", 8, 2, " gold!\n");
    } else {
      Print("The ork got bored and left");
    }
    Inform(health, "You have ", " health left\n");
    if (health > 0) {
      play = GetPlayerBool("Do you want to keep playing?\n");
    }
  } while (play && health > 0);
  // Game over

  Inform(turns, "\n\nYou played a total of ", " rounds ");
  // if player quit
  if (!play) {
    Inform(gold, "and found ", " gold!");
    // return score
    return gold + turns + health - dmg;
    if (health < 5) {
      Inform(health, " But you only have", "health left, so go see a doctor");
    }
  }
  // if player died
  else if (health < 0) {
    Print(" and got f****ing annihilated!");
  } else {
    Print("and died lol.");
  }
  if (gold > 0) {
    Inform(gold, "The ork steals ", " gold of your corpse!\n");
  } else {
    Print("The ork steals your shoes!\n");
  }
  // return score
  return turns - dmg;
}

int main() {
  srand(time(0));
  int health = 10;
  int play = 0;
  play = GetPlayerBool("Do you want to go on an adventure?\n");
  Print("Off we Go!");
  int score = 0;
  score = OrkAttack(play, health);
  cout << "\n\nfinal score:" << score << "\n\n";
}
