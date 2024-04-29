// Jaedon wallace coding 1 at 11 am
// Spring 2024 week 5
// loops and lists
#include <iostream>
#include <string>
using namespace std;

int main() {
  std::cout << "Hello World!\n";
  // keep playing( yes/ no)? do -while loop
  // random name generator
  // battlebot orderer (shuffels list)

  // while(true) {
  // cout << "may name is dan \n";
  // }
  // do while loop tests at the end of a

  string response = "";
  // cout << "do you want to continue y/n\n";
  // while (response != "no") {
  //     cout << "we adventure!\n";
  //     cout << "do you want to keep going\n";
  //     cin >> response;
  // }

  // do {
  //     cout << "do you want to keep adventureing?\n";
  //     cin>> response;
  // } while (response != "no");

  // while (true) {
  //     cout << "yay adventure\n do you want to continue\n";
  //     string response;
  //     cin>>response;

  //     if(response == "no") {
  //         cout <<"go home\n";
  //         break;
  //     }
  // }
  // cout<<"outside final loop\n";

  //  lets build a list of names
  //  build an array of strings
  string names[10];
  names[0] = "depresso";
  names[1] = "cattiva";
  names[3] = "laball";
  names[2] = "anubis";
  names[4] = "glaceclaw";
  names[5] = "tocotoco";

  cout << "my favorate pal is " << names[1] << ". \n";

  // the for loop is a great way to go through a list, i am not graded for my
  // speling lol i = iterator, but it can be renamed. for (initialisation, test,
  // action) {code block}
  for (int i = 0; i < 10; i++) {
    if (names[i] == "")
      continue;
    cout << names[i] << "\n";
  }
  cout << "thats all\n";

  // create a list of favorite games (array)
  string favGames[10];
  // create a while loop that asks the player what they would like to do
  string input = "";
  int index = 0;
  while (input != "quit") {
    cout << "\nwhat would you like to do?\n(add, show, quit)\n";
    cin >> input;
    if (input == "add") {
      // find free space
      for (int i = 0; i < 10; i++) {
        if (names[i] != "") {
          continue;
        } else if (i < 11) {
          index = i;
          cout << "who do you want to add?\n";
          cin >> names[index];
          cout << "added " << names[index] << "!\n";
        } else {
          cout << "no more room\n";
        }
        break;
      }
    } else if (input == "show") {
      for (int i = 0; i < 10; i++) {
        if (names[i] == "")
          continue;
        cout << i+1 << " " << names[i] << "\n";
      }
    }
  }

  // the player can add a game, or show game, or "quit"
  // when adding when size is max dont add more
  // when showing =, ignore blank spaces
  // when quiting tell them thanks
}
