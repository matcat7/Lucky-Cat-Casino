//
// Created by Jacob on 10/12/25
//

#ifndef STATTRACKER_H
#define STATTRACKER_H

#include <string>
using namespace std;

class StatTracker {
    private:
        // Instance variable
        int blackjackWins, slotsWins, rouletteWins;
        int blackjackLosses, slotsLosses, rouletteLosses;
    public:
        // Constructor  
        StatTracker() : blackjackWins(0), slotsWins(0), rouletteWins(0), blackjackLosses(0), slotsLosses(0) {};
        StatTracker(string path);

        void winBlackjack() { blackjackWins++; }
        void winSlots() { slotsWins++; }
        void winRoulette() { rouletteWins++; };

        void loseBlackjack() { blackjackLosses++; }
        void loseSlots() { slotsLosses++; }
        void loseRoulette() { rouletteLosses++; }

        int getBlackjackWins() const { return blackjackWins; }
        int getSlotsWins() const { return slotsWins; }
        int getRouletteWins() const { return rouletteWins; }

        int getBlackjackLosses() const { return blackjackLosses; }
        int getSlotsLosses() const { return slotsLosses; }
        int getRouletteLosses() const { return rouletteLosses; }

        int getWins() const { return (blackjackWins + slotsWins + rouletteWins); }
        int getLosses() const { return (blackjackLosses + slotsLosses + rouletteLosses); }

        void save(string path);

        // Resets all stats
        void resetAll();
};

#endif //STATTRACKER_H