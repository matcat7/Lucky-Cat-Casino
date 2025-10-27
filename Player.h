//
// Created by Jacob Pancoast on 10/4/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Bank.h"
#include "StatTracker.h"
#include "json.hpp"

using json = nlohmann::json;


class Player {
public:
  // Player "has-a" Bank account and
  // a Stat Tracker
  Bank account;
  StatTracker stats;

  // Constructor
  Player(string name, Bank bank, StatTracker stat) : name(name), account(bank), stats(stat) {};

  // Destructor
  ~Player() = default;

  // Getter
  string getName() const { return name; };
  StatTracker getStats() const { return stats; };

  // Prints stats
  void printStats() const;

  // Saves current amount in player's bank to their file
  void save();

private:
  // Instance variables
  std::string name;

};



#endif //PLAYER_H
