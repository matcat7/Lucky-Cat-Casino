#ifndef ROULETTE_H
#define ROULETTE_H

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
 * This class represents a Roulette table
 *
 */

class Roulette : public Game {
public:
    // Getters
    int GetWinningNumber() const;
    int GetUserNumber() const;
    std::string GetWinningColor() const;
    
    Roulette(Player* player) : Game(player) {}

    // Plays the game of roulette
    void PlayGame() override;

    // Creates a vector representing a roulette wheel
    // This is currently unused and will be implemented in a later project
    std::vector<int> CreateWheel(std::vector<int>);

    // Rolls a ball and randomly selects a winning number
    void RollNumber();

    // Assigns correct color to user number based on its value
    std::string SelectColor(int userNumber);

    // Assigns correct color to winning number based on its value
    void WinningColor(int rolledNumber);

    // A secret Easter Egg method, to be implemented fully someday
    void SecretRouletteMethod();
protected:
    // Fields
    int winningNumber;
    int userNumber;
    std::string winningColor;
    std::string userColor;
};
#endif //ROULETTE_H
