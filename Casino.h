#ifndef CASINO_H
#define CASINO_H

#include <string>
#include <vector>
#include <random>
#include <sstream>
#include <chrono>
#include <ctime>
#include <thread>
#include <iostream>
#include <fstream>
#include "Games/Roulette.h"
#include "Games/Slots.h"
#include "Games/Blackjack.h"
#include "Games/War.h"
#include "Player.h"
#include "Bank.h"
#include "json.hpp"

using json = nlohmann::json;


/*
 * This class represents a Casino
 *
 */

class Casino {
public:

    // Default constructor setting bankAccount to 10000 if LoginUser returns false and userName to ""
    Casino();

    // Alternate constructor with manual bankAccount input for testing
    Casino(Player* player);

    // Getters
    int GetStartBalance() const;
    std::string GetUserName() const;

    // Runs the casino and allows games to be played
    void OpenCasino();

    char GetInput();

    // Logs into a user profile to access their info
    bool LoginUser();

    void ChooseGame();
    // Opens user's stats
    void GetStats();
    void GetBank();

    // Gets a loan (max 2 per session) for users out of chips
    void GetLoan();

    static const int MIN_BANK = 0;
    static const int MAX_LOANS= 5;
protected:
    int startBalance;
    int loanAmount;

    Player* player;

    Roulette* roulette;
    Slots* slots;
    Blackjack* blackjack;
    War* war;

};
#endif //CASINO_H
