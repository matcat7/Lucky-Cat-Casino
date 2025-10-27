//
// Created by Jacob Pancoast on 10/5/2025.
//

#include "Bank.h"
#include "Casino.h"
#include "Player.h"
#include "Games/Blackjack.h"
#include "Games/Roulette.h"
#include "Games/Slots.h"
#include "Games/War.h"
#include <iostream>
#include <fstream>
using namespace std;

bool testBank();
bool testPlayer();
bool testCasino();

int main() {
  if (testBank() == false) {
    cout << "FAILED 1 or more Bank tests!" << endl;
  }
  if (testPlayer() == false) {
    cout << "FAILED 1 or more Player tests!" << endl;
  }
  if (testCasino() == false) {
    cout << "FAILED 1 or more Casino tests!" << endl;
  }

  cout << "PASSED all tests!" << endl;

  return 0;
}

bool testBank() {
  bool passed = true;
  Bank b1 = Bank("Mat");
  Bank b2 = Bank("Jacob", 500);

  if (b1.getBalance() != 0) {
    cout << "FAILED Bank no initial balance test" << endl;
    passed = false;
  }

  if (b1.getName() != "Mat") {
    cout << "FAILED Bank name test" << endl;
    passed = false;
  }

  if (b2.getBalance() != 500) {
    cout << "FAILED Bank initial balance test" << endl;
    passed = false;
  }

  b1.removeFromBank(500);

  if (b1.getBalance() != -500) {
    cout << "FAILED Bank negative test" << endl;
    passed = false;
  }

  b2.addToBank(500);
  if (b2.getBalance() != 1000) {
    cout << "FAILED Bank add test" << endl;
    passed = false;
  }

  b2.removeFromBank(300);
  if (b2.getBalance() != 700) {
    cout << "FAILED Bank remove test" << endl;
    passed = false;
  }

  return passed;
}

bool testPlayer() {
  bool passed = true;
  Player p1("brokeuser", Bank("brokeuser"));

  if (p1.account.getBalance() != 0) {
    cout << "FAILED Player constructor test" << endl;
    passed = false;
  }

  p1.account.addToBank(500);
  p1.saveBankToFile();
  string filePath = "../user_cache/login_brokeuser.txt";
  string str;
  int balance;
  ifstream file(filePath);

  if (!(file.is_open())) {
    cout << "FAILED opening file " << filePath << endl;
    passed = false;
  }

  getline(file, str);
  balance = stoi(str);
  if (balance != 500) {
    cout << "FAILED Player balance test" << endl;
    passed = false;
  }

  return passed;
}

bool testCasino() {
  bool passed = true;
  Player* p1 = new Player("richuser", Bank("richuser", 10000));
  Casino casino(p1);

  if (casino.GetStartBalance() != 10000) {
    cout << "FAILED Casino getstartbalance test" << endl;
    passed = false;
  }

  if (casino.GetUserName() != "richuser") {
    cout << "FAILED Casino getusername test" << endl;
    passed = false;
  }

  return passed;
}
