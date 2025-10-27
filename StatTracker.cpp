//
// Created by Jacob on 10/12/2025.
//

#include "StatTracker.h"
#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

StatTracker::StatTracker(string path) {
    ifstream inFile(path);
    if (inFile) {
        json userData;
        inFile >> userData;
        inFile.close();

        blackjackWins = userData["wins"]["blackjack"];
        slotsWins = userData["wins"]["slots"];
        rouletteWins = userData["wins"]["roulette"];

        blackjackLosses = userData["losses"]["blackjack"];
        slotsLosses = userData["losses"]["slots"];
        rouletteLosses = userData["losses"]["roulette"];
    } else {
        resetAll();
        cout << "Error loading stats from user's file!" << endl;
    }
}

void StatTracker::save(string path) {
     ifstream inFile(path);
     json userData;
    if (inFile) {
        inFile >> userData;
        inFile.close();

        userData["wins"]["blackjack"] = blackjackWins;
        userData["wins"]["slots"] = slotsWins;
        userData["wins"]["roulette"] = rouletteWins;

        userData["losses"]["blackjack"] = blackjackLosses;
        userData["losses"]["slots"] = slotsLosses;
        userData["losses"]["roulette"] = rouletteLosses;
    } else {
        cout << "Error editing stats!" << endl;
    }

    ofstream outFile(path);
    if (outFile) {
        outFile << userData.dump(4);
        outFile.close();
    } else {
        cerr << "Error writing stats to file!" << endl;
    }
}

void StatTracker::resetAll() {
    blackjackWins = slotsWins = rouletteWins = 0;
    blackjackLosses = slotsLosses = rouletteLosses = 0;
}