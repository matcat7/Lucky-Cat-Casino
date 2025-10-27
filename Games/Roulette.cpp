#include "Games/Roulette.h"

using namespace std;

/**********Roulette class**********/

int Roulette::GetWinningNumber() const {
  return winningNumber;
}

int Roulette::GetUserNumber() const {
  return userNumber;
}

string Roulette::GetWinningColor() const {
  return winningColor;
}

void Roulette::PlayGame() {

  cout << "ROULETTE!" << endl;
  cout << "--------------------" << endl;

  // Values needed from user input
  string userCol;
  string userColChosen;
  string inputVal1;
  string inputVal2;
  string inputVal3;
  string inputVal4;
  int betType = 0;
  int colorChosen = 0;
  int betAmount = 0;

  cin.clear();
  cin.ignore(1000, '\n');

  // Gets player's betting type (color or number)
  // Input validation 1
  while (betType != 1 && betType != 2 && betType != 7) {
    stringstream ss1;
    cout << "Select 1 to bet a color, or 2 to bet a number: " << endl;
    getline(cin, inputVal1);
    ss1 << inputVal1;

    if (ss1 >> betType) {
        string leftoverInput1; // This is checking for something after valid input
        if (ss1 >> leftoverInput1 || (betType != 1 && betType != 2 && betType != 7)) {
            betType = 0;
            cout << "That isn't correct! Please choose an integer, 1 or 2." << endl;
        }
    } else {
        betType = 0;
        cout << "That isn't correct! Please choose an integer, 1 or 2." << endl;
    }
    // Betting a color
    if (betType == 1) {
        // Input validation 2
        while (colorChosen != 1 && colorChosen != 2) {
            stringstream ss2;
            cout << "Please choose a color, 1 for Black or 2 for Red: " << endl;
            getline(cin, inputVal2);
            ss2 << inputVal2;
            if (ss2 >> colorChosen) {
                string leftoverInput2;
                if (ss2 >> leftoverInput2 || (colorChosen != 1 && colorChosen != 2)) {
                    colorChosen = 0;
                    cout << "That isn't correct! Please choose an integer, 1 or 2." << endl;
                } else {
                    userColChosen = (colorChosen == 1 ? "Black" : "Red");
                }
            } else {
                colorChosen = 0;
                cout << "That isn't correct! Please choose an integer, 1 or 2." << endl;
            }
        }
        cout << "You chose " << userColChosen << endl;
    }
    // Betting a number
    else if (betType == 2) {
        // Getting a userNumber to bet
        // Input validation 3
        do {
            stringstream ss3;
            cout << "Please choose a number, 0-36: " << endl;
            getline(cin, inputVal3);
            ss3 << inputVal3;
            if (ss3 >> userNumber) {
                string leftoverInput3;
                if (ss3 >> leftoverInput3 || userNumber < 0 || userNumber > 36) {
                    userNumber = 37; // invalid
                    cout << "That isn't correct! Please choose a whole number between 0 and 36." << endl;
                }
            } else {
                userNumber = 37;
                cout << "That isn't correct! Please choose a whole number between 0 and 36." << endl;
            }
        } while (userNumber < 0 || userNumber > 36);
        userCol = SelectColor(userNumber);
        cout << "You chose " << userNumber << " which is " << userCol << endl;
    }
    // Secret!
    else if (betType == 7) {
        SecretRouletteMethod();
    }
  }

  // Getting bet amount (regardless of bet type)
  // Input validation 4
  while (betAmount > player->account.getBalance() || betAmount < 1) {
    stringstream ss4;
    cout << "Please choose a whole number bet amount up to " << player->account.getBalance() << ": " << endl;
    getline(cin, inputVal4);
    ss4 << inputVal4;
    if (ss4 >> betAmount) {
        string leftoverInput4;
        if (ss4 >> leftoverInput4 || betAmount < 1 || betAmount > player->account.getBalance()) {
            betAmount = 0;
            cout << "That isn't correct! Please enter a whole number between 1 and " << player->account.getBalance() << ": " << endl;
        }
    } else {
        betAmount = 0;
        cout << "That isn't correct! Please enter a whole number between 1 and " << player->account.getBalance() << ": " << endl;
    }
  }
  cout << "You bet " << betAmount << " chips." << endl;

  // Simulates a ball rolling
  cout << "--------------------" << endl;
  RollNumber();
  cout << "Rolling ball..." << endl;

  // Fun timer integration slightly modified
  int seconds = 3;

  while (seconds >= 1) {
    cout << seconds << endl;
    this_thread::sleep_for(chrono::seconds(1));
    seconds--;
  }
  cout << "Ball rolled" << endl;

  // Prints out winning info
  cout << "--------------------" << endl;
  WinningColor(GetWinningNumber());
  cout << "The winning Number is " << GetWinningNumber() << " which is " << GetWinningColor() << endl;
  if (GetUserNumber() == GetWinningNumber()) {
    int payout1 = betAmount * 36;
    cout << "You win " << payout1 << " chips!" << endl;
    player->stats.winRoulette();
    player->account.addToBank(payout1);
    player->save();
  } else if (userColChosen == GetWinningColor()) {
    int payout2 = betAmount * 2;
    cout << "You win " << payout2 << " chips!" << endl;
    player->stats.winRoulette();
    player->account.addToBank(payout2);
    player->save();
  } else {
    int payout3 = betAmount;
    cout << "You lost " << payout3 << " chips." << endl;
    player->stats.loseRoulette();
    player->account.removeFromBank(payout3);
    player->save();
  }
  cout << "--------------------" << endl;
}

vector<int> Roulette::CreateWheel(vector<int> numbers) {
    // Creates numbers for a wheel
    // Will likely be used for a "wheel" object
     for (int i = 0; i <= 36; i++) {
       numbers.push_back(i);
     }
     return numbers;
}

void Roulette::RollNumber() {
  // Randomly selects a number
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(0, 36);
  winningNumber = distrib(gen);
}

string Roulette::SelectColor(int userNumber) {
  // Selecting a user number based on European Roulette
  if ((1 <= userNumber && userNumber <=10) || (19 <= userNumber && userNumber <= 28)) {
    if (userNumber % 2 == 0) {
      return "Black";
    } else if (userNumber % 2 == 1) {
      return "Red";
    }
  } else if ((11 <= userNumber && userNumber <= 18) || (29 <= userNumber && userNumber <= 36)) {
    if (userNumber % 2 == 0) {
      return "Red";
    } else if (userNumber % 2 == 1) {
      return "Black";
    }
  } else if (userNumber == 0) {
    return "Green";
  }
  return "ERROR";
}

void Roulette::WinningColor(int rolledNumber) {
  if ((1 <= rolledNumber && rolledNumber <=10) || (19 <= rolledNumber && rolledNumber <= 28)) {
    if (rolledNumber % 2 == 0) {
      winningColor = "Black";
    } else if (rolledNumber % 2 == 1) {
      winningColor =  "Red";
    }
  } else if ((11 <= rolledNumber && rolledNumber <= 18) || (29 <= rolledNumber && rolledNumber <= 36)) {
    if (rolledNumber % 2 == 0) {
      winningColor =  "Red";
    } else if (rolledNumber % 2 == 1) {
      winningColor = "Black";
    }
  } else if (rolledNumber == 0) {
    winningColor = "Green";
  }
}
void Roulette::SecretRouletteMethod() {
  cout << "You found a secret!" << endl;

  // Timer, again!
  int seconds = 1;
  while (seconds >= 1) {
    cout << "..." << endl;
    this_thread::sleep_for(chrono::seconds(1));
    seconds--;
  }
  cout << "Here's 1000 chips! Come back when you need a pick-me-up!" << endl;
  player->account.addToBank(1000);
  cout << "Happy gambling!" << endl;
  cout << endl;
  PlayGame();
}
