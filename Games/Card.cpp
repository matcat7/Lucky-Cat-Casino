//
// Created by Jacob Pancoast on 9/9/2025.
//
#include "Games/Card.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;

Card::Card() {
  int random1 = rand() % Card::NUMSUITS;
  int random2 = rand() % Card::NUMRANKS;

  suit = Card::Suits(random1);
  rank = Card::Ranks(random2);
}

Card::Card(Suits s, Ranks r) {
  suit = s;
  rank = r;
}

Card::Suits Card::getSuit() const {
  return this->suit;
}

Card::Ranks Card::getRank() const {
  return this->rank;
}

int Card::GetNumSuits() const {
  return NUMSUITS;
}

int Card::GetNumRanks() const {
  return NUMRANKS;
}

int Card::getValue(Ranks rank) {
  switch (rank) {
    case Card::Ranks::Ace: return 1;
    case Card::Ranks::Two: return 2;
    case Card::Ranks::Three: return 3;
    case Card::Ranks::Four: return 4;
    case Card::Ranks::Five: return 5;
    case Card::Ranks::Six: return 6;
    case Card::Ranks::Seven: return 7;
    case Card::Ranks::Eight: return 8;
    case Card::Ranks::Nine: return 9;
    case Card::Ranks::Ten:
    case Card::Ranks::Jack:
    case Card::Ranks::Queen:
    case Card::Ranks::King: return 10;
    default: return 0;
  }
}

int Card::getWarValue() const {
  if (rank == Ranks::Ace) {
    return 14;
  } else {
    return static_cast<int>(rank) + 1;
  }
}

ostream& operator<<(ostream& os, const Card& obj) {
  string rank;
  string suit;

  switch (obj.getRank()) {
    case Card::Ranks::Ace: rank = "Ace"; break;
    case Card::Ranks::Two: rank = "Two"; break;
    case Card::Ranks::Three: rank = "Three"; break;
    case Card::Ranks::Four: rank = "Four"; break;
    case Card::Ranks::Five: rank = "Five"; break;
    case Card::Ranks::Six: rank = "Six"; break;
    case Card::Ranks::Seven: rank = "Seven"; break;
    case Card::Ranks::Eight: rank = "Eight"; break;
    case Card::Ranks::Nine: rank = "Nine"; break;
    case Card::Ranks::Ten: rank = "Ten"; break;
    case Card::Ranks::Jack: rank = "Jack"; break;
    case Card::Ranks::Queen: rank = "Queen"; break;
    case Card::Ranks::King: rank = "King"; break;
    default: rank = "Error encountered in card rank"; break;
  }

  switch (obj.getSuit()) {
    case Card::Suits::Hearts: suit = "Hearts"; break;
    case Card::Suits::Diamonds: suit = "Diamonds"; break;
    case Card::Suits::Spades: suit = "Spades"; break;
    case Card::Suits::Clubs: suit = "Clubs"; break;
    default: suit = "Error encountered in card suit"; break;
  }

  os << rank << " of " << suit;
  return os;
}
