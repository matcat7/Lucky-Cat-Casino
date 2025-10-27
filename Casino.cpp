#include "Casino.h"

using namespace std;

/**********Casino class**********/

Casino::Casino() {
    loanAmount = 0;
}

Casino::Casino(Player* player) {
    this->player = player;
    startBalance = player->account.getBalance();
}

int Casino::GetStartBalance() const {
    return startBalance;
}

string Casino::GetUserName() const {
    return player->getName();
}

void Casino::OpenCasino() {
    int gameChoice = 5;
    string mainInput;
    char input;
    startBalance = player->account.getBalance();

    // ASCII art!
    cout << R"(               _                _             _____      _      _____          _
              | |              | |           / ____|    | |    / ____|        (_)
              | |    _   _  ___| | ___   _  | |     __ _| |_  | |     __ _ ___ _ _ __   ___
              | |   | | | |/ __| |/ / | | | | |    / _` | __| | |    / _` / __| | '_ \ / _ \
              | |___| |_| | (__|   <| |_| | | |___| (_| | |_  | |___| (_| \__ \ | | | | (_) |
              |______\__,_|\___|_|\_\\__, |  \_____\__,_|\__|  \_____\__,_|___/_|_| |_|\___/
                                      __/ |
                                      |___/

       ------------------------------------------------------------------------------------------
        /\_/\
       ( o.o )          Welcome to the LUCKY CAT CASINO! By Mathew Neves & Jacob Pancoast
        > ^ <
       ------------------------------------------------------------------------------------------
    )" << endl;
    // Setting up and playing casino
    while (true) {
        input = 'z';

        cout << "> (g) View games" << endl;
        cout << "> (b) View bank" << endl;
        cout << "> (s) View your stats" << endl;
        cout << "> (e) Exit casino (ends and closes program)" << endl;

        cin >> input;
        switch (toupper(input)) {
            case 'G': this->ChooseGame(); continue;
            case 'B': this->GetBank(); continue;
            case 'S': this->GetStats(); continue;
            case 'E': cout << "Exiting casino. Thanks for playing!" << endl; return;
            default: continue;
        }

        cout << "Please enter a valid option." << endl;
    }
    
    cout << "You now have " << player->account.getBalance() << " chips!" << endl;
    cout << "Thanks for playing! Come again soon." << endl;
}

char Casino::GetInput() {
    string userInput;
    string userName;
    char choice;

    while (true) {
        cout << "> Create a login (L): " << endl;
        cout << "> Enter your username (E): " << endl;

        // Read input and convert to char
        getline(cin, userInput);
        choice = toupper(userInput[0]);
        if (userInput.empty()) {
            cout << "No input provided." << endl;
        }

        // Break loop if input is valid
        if ((choice ==  'E' ||
            choice == 'L') &&
            userInput.length() < 2) {
            return choice;
            }
        else {
            cout << "Invalid choice, please try again." << endl;
        }
    }
}

bool Casino::LoginUser() {
    char choice;
    string userInput;
    int initial;

    choice = GetInput();

    if (choice == 'L') {
        while (true) {
            json userData;

            cout << "Enter a new username: " << endl;
            getline(cin, userInput);

            // prompt for new username if no input
            if (userInput.empty()) {
                cout << "Invalid username." << endl;
                continue;
            }

            string fileName = "user_cache/login_" + userInput + ".json";
            ifstream checkFile(fileName);
            // if a file exists, user exists already
            if (checkFile) {
                cout << "Username already in use, try again: " << endl;
                checkFile.close();
                continue;
            }

            // otherwise, write out to this new user's file
            ofstream outFile(fileName);

            // if not possible, throw error
            if (!outFile) {
                cerr << "Error creating file for " << player->getName() << endl;
                return false;
            }

            // create json data
            userData["username"] = userInput;
            userData["balance"] = 10000;
            userData["balance-history"].push_back(10000);
            userData["wins"]["blackjack"] = 0;
            userData["wins"]["slots"] = 0;
            userData["wins"]["roulette"] = 0;
            userData["losses"]["blackjack"] = 0;
            userData["losses"]["slots"] = 0;
            userData["losses"]["roulette"] = 0;

            outFile << userData.dump(4);
            outFile.close();

            player = new Player(userInput, Bank(userInput, 10000), StatTracker());
           
            cout << "Created new login for " << player->getName() << " with starting balance of 10000 chips." << endl;
            roulette = new Roulette(player);
            slots = new Slots(player);
            blackjack = new Blackjack(player);
            war = new War(player);
            return true;
        }
    }
    else {
        json userData;

        cout << "Please enter your username: ";
        userInput.clear();
        getline(cin, userInput);

        string fileName = "user_cache/login_" + userInput + ".json";
        ifstream fileIn(fileName);

        // try 2nd path
        if (!fileIn) {
            fileName = "user_cache/login_" + userInput + ".json";
            fileIn.open(fileName);
        }

        // throws error if no
        while (!fileIn) {
            cout << "Unrecognized username, please try again. " << endl;
            fileIn.close();
            return false;
        }

        fileIn >> userData;

        string user = userData["username"];
        int bal = userData["balance"];

        fileIn.close();

        player = new Player(user, Bank(user, bal), StatTracker(fileName));

        cout << "Welcome back, " << player->getName() << ". Your balance is " << player->account.getBalance() << " chips." << endl;
        roulette = new Roulette(player);
        slots = new Slots(player);
        blackjack = new Blackjack(player);
        war = new War(player);
        return true;
    }

}

void Casino::ChooseGame() {
    char input;

    while (true) {
        input = 'z';

        cout << endl;
        cout << "So you're feeling lucky today!" << endl;
        cout << "Which game would you like to play?" << endl;
        cout << "> (r) Roulette" << endl;
        cout << "> (s) Slots" << endl;
        cout << "> (b) Blackjack" << endl;
        cout << "> (w) War" << endl;
        cout << "> (e) Return to main screen" << endl;

        cin >> input;
        switch (toupper(input)) {
            case 'R': {
                if (player->account.getBalance() < 1) {
                    cout << "Not enough chips for this game!" << endl;
                }
                roulette->PlayGame();
                continue;
            }
            case 'S': {
                if (player->account.getBalance() < 500) {
                    cout << "Not enough chips for this game!" << endl;
                }
                slots->PlayGame();
                continue;
            }
            case 'B': {
                if (player->account.getBalance() < 1) {
                    cout << "Not enough chips for this game!" << endl;
                }
                blackjack->PlayGame();
                continue;
            }
            case 'W': {
                war->StartGame();
                continue;
            }
            case 'E': break;
            default: continue;
        }
        cout << "Please enter a valid option." << endl;
        cout << endl;
        if (toupper(input) == 'E') {
            break;
        }
    }
}

void Casino::GetStats() {
    player->save();
    
    const string python = "py";

    string fileName = "user_cache/login_" + player->getName() + ".json";
    string command = python + " graph.py " + fileName + " " + player->getName();
    char input;

    this->player->printStats();

    system(command.c_str());

    cout << "> (e) Return to main screen." << endl;
    while (true) {
        cin >> input;
        if (toupper(input) == 'E') {
            break;
        }
    }
}

void Casino::GetBank() {
    player->save();
    cout << endl;
    cout << "Hey, " << player->getName() << "! You have " << player->account.getBalance() << " chips." << endl;
        if (player->account.getBalance() == 0) {
            GetLoan();
        }
}

void Casino::GetLoan() {
    if (loanAmount < 2) {
        cout << "Here's a loan of 5000 chips, for your broke self." << endl;
        cout << "You're lucky this isn't real money...we wouldn't be so generous :)" << endl;
        player->account.addToBank(5000);
        loanAmount++;
    } else {
        cout << "Alright...that's enough out of you." << endl;
        cout << "https://www.ncpgambling.org/help-treatment/" << endl;
    }
}
