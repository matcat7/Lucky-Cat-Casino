#include <iostream>
#include "Casino.h"

//k

using namespace std;

int main() {
    Casino casinoGame;
    while (casinoGame.LoginUser() == false) {}
    casinoGame.OpenCasino();
    return 0;
}
