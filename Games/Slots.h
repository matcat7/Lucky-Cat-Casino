#ifndef SLOTS_H
#define SLOTS_H

#include <string>
#include <vector>
#include <random>
#include <sstream>
#include <chrono>
#include <ctime>
#include <thread>
#include <iostream>
#include "../Game.h"
#include "../Player.h"

/*
 * This class represents a Slots machine
 *
 */

class Slots : public Game {
public:

    // Getters 
    int GetSlotOneNum() const;
    int GetSlotTwoNum() const;
    int GetSlotThreeNum() const;

    Slots(Player* player) : Game(player) {}

    // Plays the game of slots
    void PlayGame() override;

    // Spins machine and randomly selects 5 numbers
    void SpinSlots();

    // Assigns a fruit to the slot number
    std::string SlotFruits(int slotNum);

    // Assigns win conditions/values based on results
    void WinConditions();

    // A secret Easter Egg method, to be implemented fully someday
    void SecretSlotsMethod();

protected:
    int slotOneNum;
    int slotTwoNum;
    int slotThreeNum;
    std::string slotOneFruit;
    std::string slotTwoFruit;
    std::string slotThreeFruit;
};

#endif //SLOTS_H
