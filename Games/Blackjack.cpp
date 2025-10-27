//
// Created by Jacob Pancoast on 9/9/2025.
//

#include "Blackjack.h"
#include <iostream>
#include <sstream>
using namespace std;

void Blackjack::PlayGame() {
  // Create local variables
  string choice;
  string playAgain;

  // Reset the game state
  reset();

  // If the player has no money, kick them out
  if (player->account.getBalance() == 0) {
    cout << "You don't have enough to bet... goodbye." << endl;
    return;
  }

  // Print the rules for the player
  Blackjack::rules();

  // Read in the player's choice
  getline(cin,choice);

  // Validate the player's choice
  while (choice != "b" && choice != "e") {
    // If player keeps pressing v it will keep showing the values
    // and prompt them for new input
    if (choice == "v") {
      cardValues();
      options();
      getline(cin,choice);
    }
    else {
      cout << "Please enter a valid choice" << endl;
      options();
      getline(cin,choice);
    }
  }
  // If player chooses b, start betting phase
  if (choice == "b") {
    bet();
  }
  // If player choses e, exit the program
  // For project 2 when combining
  else if (choice == "e") {
    cout << "Exiting..." << endl;
    return;
  }
  // Error handling
  else {
    cout << "Error entering choice" << endl;
  }

  // Call phase 1 to deal 2 cards to the player and 1 to the dealer
  phase1();

  // After the player and dealer both have a starting total, let the player
  // Choose to hit or stand while they are below 21
  while (playerTotal < 21) {
    // Validates input within the function
    char choice = choose();

    // Hit
    if (choice == 'h') {
      hit();
    }
    // Stand
    else if (choice == 's') {
      stand();
      break;
    }
  }

  // Once the player chose to stand or is above 21, evaluate their
  // hands and determine the win condition
  evaluate();

  // Replayability functionality
  cout << "Would you like to play again?" << endl;
  cout << "* (y) yes" << endl;
  cout << "* (n) no" << endl;
  getline(cin,playAgain);

  // Input validation on replay
  while (playAgain != "y" && playAgain != "n") {
    cout << "Please enter a valid choice." << endl;
    cout << "* (y) yes" << endl;
    cout << "* (n) no" << endl;
    getline(cin,playAgain);
  }

  // if yes, play again
  if (playAgain == "y") {
    PlayGame();
  }
  // if no, exit the play function
  else if (playAgain == "n") {
    return;
  }
  // error handling
  else {
    cout << "End of game error." << endl;
  }

  return;
}

void Blackjack::rules() {
  cout << endl;
  cout << "Welcome to Blackjack! First, place a starting bet." << endl;
  cout << "In this game you play against the dealer to draw cards (hit)" << endl;
  cout << "to get as close to 21 as possible (stand) without going over 21." << endl;
  cout << "Whoever is closer between the player and the dealer wins the bet." << endl;
  cout << endl;
  options();
}

void Blackjack::options() const {
  cout << "* (b) to bet (Balance: $" << player->account.getBalance() << ")" << endl << "* (v) to view card values" << endl << "* (e) to exit" << endl;
}

void Blackjack::bet() {
  string input;
  string test;
  stringstream ss;
  int bet;
  bool flag = false;

  cout << endl;
  cout << "How much would you like to bet on this hand? (Balance: $" << player->account.getBalance() << ")" << endl;
  getline(cin, input);
  ss << input;

  if (ss >> bet) {
    flag = true;
    gameBet = bet;
    if (ss >> test) {
      flag = false;
      ss.clear();
      ss.str("");
    }

    if (bet <= 0) {
      flag = false;
      cout << "Ha-ha, very funny. Try again." << endl;
    }

    else if (bet > player->account.getBalance()) {
      flag = false;
      cout << "You came up just short enough to make that bet... try again." << endl;
    }
  }

  while (flag == false) {
    cout << "Please enter a valid bet within your price range. (Balance: $" << player->account.getBalance() << ")" << endl;
    cin.clear();
    getline(cin, input);
    ss << input;

    if ((ss >> bet) && (bet > 0) && (bet <= player->account.getBalance())) {
      flag = true;
      gameBet = bet;
      if (ss >> input) {
        flag = false;
      }
    }

    if (bet <= 0) {
      flag = false;
      cout << "Ha-ha, very funny. Try again." << endl;
    }

    else if (bet > player->account.getBalance()) {
      flag = false;
      cout << "You came up just short enough to make that bet... try again." << endl;
    }
    ss.clear();
    ss.str("");
  }
}

void Blackjack::cardValues() {
  cout << "Card Values:" << endl;
  cout << "* Two - Ten = Actual" << endl;
  cout << "* Jack, King, Queen = 10" << endl;
  cout << "* Ace = 1 or 11" << endl;
  cout << "The value of the Ace depends on the player's choice." << endl;
}

void Blackjack::phase1() {
  Card card1;
  Card card2;
  Card card3;
  dealerHand.push_back(card1);
  playerHand.push_back(card2);
  playerHand.push_back(card3);

  dealerTotal += card1.getValue(card1.getRank());
  playerTotal += card2.getValue(card2.getRank());
  playerTotal += card3.getValue(card3.getRank());

  cout << endl;
  cout << "Dealer draws the " << dealerHand.at(0) << ". (Total: " << dealerTotal << ")" << endl;
  cout << "You are dealt the " << playerHand.at(0) << " and the " << playerHand.at(1);
  cout << ". (Total: " << playerTotal << ")" << endl;

}

char Blackjack::choose() {
  string choice;

  while (choice != "h" && choice != "s") {
    cout << endl;
    cout << "Would you like to hit or stand?" << endl;
    cout << "* (h) to hit" << endl;
    cout << "* (s) to stand" << endl;
    getline(cin,choice);
  }
  if (choice == "h") {
    return 'h';
  }
  else if (choice == "s") {
    return 's';
  }
  else {
    cout << "Something went wrong while choosing." << endl;
    return 'e';
  }
}

void Blackjack::hit() {
  Card card;
  playerHand.push_back(card);
  playerTotal += card.getValue(card.getRank());

  cout << endl;
  cout << "You hit and drew the " << playerHand.at(playerHand.size() - 1);
  cout << ". (Total: " << playerTotal << ")" << endl;

  if (playerTotal == BLACKJACK) {
    cout << "You hit 21" << endl;
    stand();
  }

  if (playerTotal > BLACKJACK) {
    cout << "You went bust!" << endl;
  }
}

void Blackjack::stand() {
  cout << endl;
  cout << "You chose to stand." << endl;

  while (dealerTotal < 17) {
    Card card;
    dealerTotal += card.getValue(card.getRank());
    cout << "The dealer draws the " << card << "... (Total: " << dealerTotal << ")" << endl;
  }

  if (dealerTotal > BLACKJACK) {
    cout << "The dealer went bust!" << endl;
  }
}
void Blackjack::evaluate() {
  if (playerTotal > BLACKJACK) {
    cout << "You lost this bet." << endl;
    player->stats.loseBlackjack();
    player->account.removeFromBank(gameBet);
    player->save();
  }

  else if (dealerTotal > BLACKJACK) {
    cout << "You won this bet!" << endl;
    player->stats.winBlackjack();
    player->account.addToBank(gameBet);
    player->save();
  }

  else if (playerTotal < dealerTotal) {
    cout << "You lost this bet." << endl;
    player->stats.loseBlackjack();
    player->account.removeFromBank(gameBet);
    player->save();
  }

  else if (playerTotal > dealerTotal || dealerTotal > BLACKJACK) {
    cout << "You won this bet!" << endl;
    player->stats.winBlackjack();
    player->account.addToBank(gameBet);
    player->save();
  }

  else if (playerTotal == dealerTotal) {
    cout << "This bet was a tie." << endl;
  }
}

void Blackjack::reset() {
  dealerTotal = 0;
  playerTotal = 0;
  playerHand.clear();
  dealerHand.clear();
  gameBet = 0;
  cin.clear();
  cin.ignore(1000, '\n');
}

