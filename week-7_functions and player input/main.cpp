// jaedon wallace
// week 7 part 2
// funtions and player input

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
//
//
// Vectors and Variables
vector<string> SimileYes = {"true", "yes",  "sure", "yep",
                            "y",    "yeah", "1",    "ok"};
//
//
// Functions

int TripleInt(int n) {
  for (int i = 1; i < 4; i++) {
    int n3 = i * 3 * n;
    cout << n * i << " x 3 = " << n3 << "! \n";
  }
  return 0;
}

int multBy(int a, int b) { return a * b; }

string NewLine(int x = 1) {
  string hold = "\n";
  for (int i = 0; i < x; i++) {
    hold += hold;
  }
  return hold;
}

// repeat what x input times
string sayWhatXtimes(string what, int x = 1) {
  string hold = what;
  for (int i = 0; i < x; i++) {
    hold += what;
  }
  return hold;
}

// cout a question to the player, return an int.
int GetPlayerInt(string question = "") {
  int x;
  cout << question;
  cin >> x;
  return x;
}

// cout a question to the player, return a string.
string getPlayerString(string question = "") {
  string x;
  cout << question;
  cin >> x;
  return x;
}

// Cout a question to the player returns a Bool based on the response
bool GetPlayerBool(string question = "") {
  cout << question;
  string input;
  cin >> input;
  // if the player responds any of the reconised versions of yes, return true.
  if (find(SimileYes.begin(), SimileYes.end(), input) !=
      SimileYes.end()) { // Ai showed me the find function.
    return 1;
    // else return false
  } else {
    return 0;
  }
}

string Triple(string givStr, bool Vert) {
  if (Vert) {
    string output;
    for (int i = 0; i < 3; i++) {
      output += givStr + NewLine();
    }
    return output;
  } else {
    return givStr + givStr + givStr;
  }
}

int Print(string input = "\n") {
  cout << input << "\n";
  return 0;
}

int addRecursive(int startNum) {
  if (startNum == 0) {
    return 0;
  }
  return startNum + addRecursive(startNum - 1);
}

int RollDie(int sides = 6, int min = 1) { return rand() % sides + min; }

string ConditionalString(bool x = 1, string t = "true", string f = "false") {
  if (x) {
    return t;
  }
  return f;

}
string OutputPlusInput(string in, string prefix = "", string suffix = ".\n") {
  // roll the die with how many sides the player responds
  // out put you rolled x !
  // what happens when i enter a int?
  return prefix + in + suffix;
}

int main() {
  // Introduction
  bool happy = (GetPlayerBool("are you having a good day?\n"));
  cout << ConditionalString(happy, "Glad to hear!\n", "thats unfortunate.\n");
  srand(time(0));
  cout << OutputPlusInput(getPlayerString("What is your name?\n"), "Greetings ",
                          "!\n");
  int playerInt =
      GetPlayerInt("what number would you like to multipy by 3s?\n");
  TripleInt(playerInt);

  cout << multBy(playerInt, 3) << NewLine(3);

  cout << sayWhatXtimes("jimmy ", 5) << NewLine();
  cout << multBy(GetPlayerInt("multipy what?\n"), GetPlayerInt("by what ? \n"));
  cout << NewLine(2);
  // cout << OutputPlusInput(RollDie(GetPlayerInt("how many sides?\n")),"you
  // rolled a ","!\n"); cannot use int with this function
  cout << RollDie(GetPlayerInt("how many sides?\n"));
  cout << "\ni was born in the year " << RollDie(50, 1970) << NewLine();
  cout << ConditionalString(happy, "you are having a good day!\n",
                            "you are having a bad day\n");
}