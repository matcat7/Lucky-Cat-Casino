//
// Created by Jacob Pancoast on 10/4/2025.
//

#include "Player.h"
#include <iostream>
#include <fstream>
using namespace std;

// TODO: make this save all data to file, not just bank.

void Player::save() {
    json userData;

    if (name.empty()) return;

    string fileName = "user_cache/login_" + name + ".json";
    ifstream in(fileName);
    if (!in) {
        cerr << "Error saving balance for user " << name << endl;
        return;
    }

    in >> userData;
    in.close();
    userData["balance"] = account.getBalance();
    userData["balance-history"].push_back(account.getBalance());

    ofstream out(fileName);
    out << userData.dump(4);
    out.close();
    stats.save(fileName);
}

void Player::printStats() const {
    json userData;
    vector<int> balances;
    
    string fileName = "user_cache/login_" + name + ".json";
    ifstream in(fileName);
    if (!in) {
        cerr << "Error getting stats from json" << name << endl;
        return;
    }

    in >> userData;
    for (int i = 0; i < userData["balance-history"].size(); i++) {
        balances.push_back(userData["balance-history"][i]);
    }

    cout << endl;
    cout << getName() << "'S STATS" << endl;
    cout << "==================================" << endl;
    cout << "Current balance: " << account.getBalance() << endl;
    cout << "Lowest balance: " << *min_element(balances.begin(), balances.end()) << endl;
    cout << "Highest balance: " << *max_element(balances.begin(), balances.end()) << endl;
    cout << endl;
    cout << "Overall wins: " << stats.getWins() << endl;
    cout << "Overall losses: " << stats.getLosses() << endl;
    cout << endl;
    cout << "Roulette wins: " << stats.getRouletteWins() << endl;
    cout << "Roulette losses: " << stats.getRouletteLosses() << endl;
    cout << endl;
    cout << "Slots wins: " << stats.getSlotsWins() << endl;
    cout << "Slots losses: " << stats.getSlotsLosses() << endl;
    cout << endl;
    cout << "Blackjack wins: " << stats.getBlackjackWins() << endl;
    cout << "Blackjack losses: " << stats.getBlackjackLosses() << endl;
    cout << endl;
}