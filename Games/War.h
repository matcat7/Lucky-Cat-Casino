#ifndef WAR_H
#define WAR_H

#include "Card.h"
#include "../Game.h"
#include <vector>
#include <random>
#include <iostream>
#include <sstream>
#include <chrono>
#include <ctime>
#include <thread>

class War : public Game {
public: 

    // Getters 
    Card GetUserCard() const;
    Card GetCpuCard() const;
    vector<Card> GetUserCards() const;
    vector<Card> GetCpuCards() const;

    // Setters - randomly selects half of a 52 card deck for target
    void SetCards();

    War(Player* player) : Game(player) {}

    // Plays the game of War
    void StartGame();

    void PlayGame() override;

protected:
    Card userCard;
    Card cpuCard;
    vector<Card> userCards;
    vector<Card> cpuCards;
};

#endif //WAR_H