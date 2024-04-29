// Jaedon Wallace 1/31/2024
// to compare and then average scores

//  Coding 1, Am
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;
int main() {
  srand(time(0)); // seeding the Random Number Generator
  cout << "Welcome to week 3 day 2!\n";
  int counter = 0;
  int highScore = 0;
  float sum = 0;
  while (counter < 10) {
    counter += 1;
    int randNum = rand() % 45 + 5;
    // cout << "counter is now "<< counter<<".\n";

    cout << counter << ". " << randNum << "\n";

    if (randNum > highScore) {
      cout << "new High score found\n";
      highScore = randNum;
    }
    cout << "HS = " << highScore << "\n";

    // for average calculations
    sum += randNum;
  }
  cout << "Final Score = " << highScore << "\n";
  cout << "The average number was = " << sum / counter << "\n";
}