//
// Created by Jacob on 10/4/2025.
//

#ifndef BANK_H
#define BANK_H

#include <string>
using namespace std;



class Bank {
public:
  // Constructors
  // If no balance is given, set balance to 0
  Bank(string name) : name(name), balance(0) {};
  // Otherwise set to given initial balance
  Bank(string name, int initial) : name(name), balance(initial) {};

  // Default destructor
  ~Bank() = default;


  // Standard bank operations
  void addToBank(int money);
  void removeFromBank(int money);
  int getBalance() const { return balance; };
  string getName() const { return name; };

private:
  // Instance variables
  std::string name;
  int balance;

};



#endif //BANK_H
