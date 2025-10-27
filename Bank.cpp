//
// Created by Jacob on 10/4/2025.
//

#include "Bank.h"

void Bank::addToBank(int money) {
  balance += money;
}

void Bank::removeFromBank(int money) {
  balance -= money;
}
