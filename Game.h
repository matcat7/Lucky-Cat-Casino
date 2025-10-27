#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Player.h"

/*
 * Abstract class representing a casino game
 */

class Casino;

class Game {
public:
    explicit Game(Player* player) : player(player) {}

    virtual ~Game() = default;

    virtual void PlayGame() = 0;

protected:
    Player* player;
};
#endif //GAME_H
