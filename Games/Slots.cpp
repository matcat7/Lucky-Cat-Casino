#include "Games/Slots.h"

using namespace std;

int Slots::GetSlotOneNum() const {
  return slotOneNum;
}

int Slots::GetSlotTwoNum() const {
  return slotTwoNum;
}

int Slots::GetSlotThreeNum() const {
  return slotThreeNum;
}

void Slots::PlayGame() {
  // Plays the game of slots
  cout << "SLOTS!" << endl;
  cout << "--------------------" << endl;
  cout << "500 chips will be removed from your account upon a loss." << endl;

  int seconds0 = 1;
  while (seconds0 >= 1) {
    this_thread::sleep_for(chrono::seconds(1));
    seconds0--;
  }
  SpinSlots();

  slotOneFruit = SlotFruits(slotOneNum);
  slotTwoFruit = SlotFruits(slotTwoNum);
  slotThreeFruit = SlotFruits(slotThreeNum);

  cout << "SPINNING!" << endl;

  int seconds1 = 1;
  while (seconds1 >= 1) {
    this_thread::sleep_for(chrono::seconds(1));
    seconds1--;
  }
  cout << "->";
  cout << slotOneFruit;

  int seconds2 = 1;
  while (seconds2 >= 1) {
    this_thread::sleep_for(chrono::seconds(1));
    seconds2--;
  }
  cout << "->";
  cout << slotTwoFruit;

  int seconds3 = 2;
  while (seconds3 >= 1) {
    this_thread::sleep_for(chrono::seconds(1));
    seconds3--;
  }
  cout << "->";
  cout << slotThreeFruit << endl;

  int seconds4 = 1;
  while (seconds4 >= 1) {
    this_thread::sleep_for(chrono::seconds(1));
    seconds4--;
  }
  // Win conditions
  if (slotOneNum == slotTwoNum && slotTwoNum == slotThreeNum) {
    cout << "All fruits matched! You win 10000 chips for this play!" << endl;
    player->stats.winSlots();
    player->account.addToBank(10000);
    player->save();
  } else if (slotOneNum == slotTwoNum || slotOneNum == slotThreeNum || slotTwoNum == slotThreeNum) {
    cout << "Two fruits matched! You lose no chips for this play." << endl;
  } else {
    cout << "No fruits matched! You lose 500 chips for this play." << endl;
    player->stats.loseSlots();
    player->account.removeFromBank(500);
    player->save();
  }
  cout << "Thanks for playing!" << endl;
  cout << "--------------------" << endl;
}

void Slots::SpinSlots() {
  // Randomly selects a number for slotOneNum
  std::random_device rd1;
  std::mt19937 gen(rd1());
  std::uniform_int_distribution<> distrib1(0, 4);
  slotOneNum = distrib1(gen);

  // Randomly selects a number for slotTwoNum
  std::random_device rd2;
  std::mt19937 gen2(rd2());
  std::uniform_int_distribution<> distrib2(0, 4);
  slotTwoNum = distrib2(gen);

  // Randomly selects a number for slotThreeNum
  std::random_device rd3;
  std::mt19937 gen3(rd3());
  std::uniform_int_distribution<> distrib3(0, 4);
  slotThreeNum = distrib3(gen3);
}

string Slots::SlotFruits(int slotNum) {
  // Creates a vector for fruits - returns the fruit based on slotNum input
  vector<string> fruits = {"ORANGE", "BANANA", "CHERRY",
                            "GRAPES", "STRAWBERRY"};
  for (int i = 0; i < fruits.size(); i++) {
    if (slotNum == i) {
      return fruits[i];
    }
  }
  return "Unknown error";
}

void Slots::SecretSlotsMethod() {
  // Unused currently! Will be added to running secrets/Easter eggs soon
  // Need to make so players can only call this once...will use file I/O.
  cout << "You found a secret!" << endl;
  int seconds1 = 1;
  while (seconds1 >= 1) {
    cout << "..." << endl;
    this_thread::sleep_for(chrono::seconds(1));
    seconds1--;
  }
  cout << "Wait...what's going on?" << endl;
  int seconds2 = 1;
  while (seconds2 >= 1) {
    this_thread::sleep_for(chrono::seconds(1));
    seconds2--;
  }
  cout << "->";
  cout << "CHERRY";

  int seconds3 = 1;
  while (seconds3 >= 1) {
    this_thread::sleep_for(chrono::seconds(1));
    seconds3--;
  }
  cout << "->";
  cout << "CHERRY";

  int seconds4 = 3;
  while (seconds4 >= 1) {
    this_thread::sleep_for(chrono::seconds(1));
    seconds4--;
  }
  cout << "->";
  cout << "CHERRY" << endl;
  cout << "JACKPOT! YOU WIN 1000 CHIPS!" << endl;
  player->account.addToBank(1000);
  cout << "Now, get some rest." << endl;
}
