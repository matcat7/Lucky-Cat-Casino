#include "Games/War.h"

using namespace std;

Card War::GetUserCard() const {
    return userCard;
}

Card War::GetCpuCard() const {
    return cpuCard;
}

vector<Card> War::GetUserCards() const {
    return userCards;
}

vector<Card> War::GetCpuCards() const {
    return cpuCards;
}

void War::SetCards() {
    // Creates full deck of cards
    vector<Card> fullDeck;
    Card tempCard;
    for (int s = 0; s < tempCard.GetNumSuits(); ++s) {
        for (int r = 0; r < tempCard.GetNumRanks(); ++r) {
            fullDeck.push_back(Card(static_cast<Card::Suits>(s), static_cast<Card::Ranks>(r)));
        }
    }
    
    // Shuffles deck
    random_device rd;
    mt19937 g(rd());
    shuffle(fullDeck.begin(), fullDeck.end(), g);

    // Ensures decks are clear
    userCards.clear();
    cpuCards.clear();

    // Loads user cards and cpu cards
    userCards.insert(userCards.end(), fullDeck.begin(), fullDeck.begin() + 26);
    cpuCards.insert(cpuCards.end(), fullDeck.begin() + 26, fullDeck.end());
}

void War::StartGame() {
    SetCards();
    char choice;
    cout << "Welcome to War, this has been made as a 'time-waster' and is free to play!" << endl;

    // User input
    while (true) {
        cout << "Select (p) to play, (r) to view rules, or (e) to exit to main menu." << endl;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        char uppercaseChoice = static_cast<char>(std::toupper(choice));

        // Input options
        if (uppercaseChoice == 'R') {
            cout << endl;
            cout << "Welcome to War! A very simple and fun game!" << endl;
            cout << "In this game you play against a CPU and both 'flip' a card." << endl;
            cout << "Whoever has the higher card takes both into their deck." << endl;
            cout << "If both cards are the same rank, then a WAR ensues! Players draw three prize cards." << endl;
            cout << "The fourth cards drawn are flipped and compared against each other, the higher winning the WAR" << endl;
            cout << "The last player with cards remaining wins!" << endl;
            cout << endl;
        } else if (uppercaseChoice == 'E') {
            cout << "Exiting..." << endl;
            return;
        } else if (uppercaseChoice == 'P') {
            PlayGame();
            break;
        } else {
            cout << "Invalid choice." << endl;
        }
    }
}

void War::PlayGame() {
    cout << "Starting the game of WAR!" << endl;
    cout << "-------------------------" << endl;

    // Local variables for gameplay
    int round = 1;
    vector<Card> cardPile;

    while (!userCards.empty() && !cpuCards.empty()) {
        // Begins round
        cout << "Round " << round << "!" << endl;
        cout << "Press ENTER to flip cards or (e) to exit to the games menu." << endl;
        string input;
        getline(cin, input);

        // Checks if user wants to exit
        if (input == "e" || input == "E") {
        cout << "\nReturning to main menu...\n";
        break;
        }
        round++;

        // Flips cards
        Card userFlipped = userCards.front();
        Card cpuFlipped = cpuCards.front();

        cout << endl;
        cout << "You flipped: " << userFlipped << endl;
        cout << "CPU flipped: " << cpuFlipped << endl;
        cout << endl;

        // Remove cards from hand
        userCards.erase(userCards.begin());
        cpuCards.erase(cpuCards.begin());

        // Adds to pile
        cardPile.push_back(userFlipped);
        cardPile.push_back(cpuFlipped);

        int userValue = userFlipped.getWarValue();
        int cpuValue = cpuFlipped.getWarValue();

        // Round win conditions
        if (userValue > cpuValue) {
            cout << "You win this round, " << userValue << " beats " << cpuValue << "." << endl;
            userCards.insert(userCards.end(), cardPile.begin(), cardPile.end());
            cardPile.clear();
        } else if (userValue < cpuValue) {
            cout << "CPU wins this round, " << cpuValue << " beats " << userValue << "." << endl;
            cpuCards.insert(cpuCards.end(), cardPile.begin(), cardPile.end());
            cardPile.clear();
        } else {
            cout << "WAR!" << endl;
            bool warTime = true;

            while (warTime) {
                // Ends war if a player has too few cards
                if (userCards.size() < 4 || cpuCards.size() < 4) {
                    cout << "A player does not have enough cards to fight this war." << endl;
                    warTime = false;
                    break;
                }
                cout << "Press ENTER to continue the war.";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                // Loops through 3x to place cards 'face down'
                for (int i = 0; i < 3; i++) {
                    cardPile.push_back(userCards.front());
                    userCards.erase(userCards.begin());
                    cardPile.push_back(cpuCards.front());
                    cpuCards.erase(cpuCards.begin());
                    int seconds = 1;
                    while (seconds >= 1) {
                        this_thread::sleep_for(chrono::seconds(1));
                        seconds--;
                    }
                    cout << i + 1 << " cards placed...";
                }

                // Places 'face up' cards
                Card userWar = userCards.front();
                Card cpuWar = cpuCards.front();

                cout << endl;
                cout << "\nYou flipped: " << userWar << endl;
                cout << "CPU flipped: " << cpuWar << endl;
                cout << endl;

                // Removes cards from hand
                userCards.erase(userCards.begin());
                cpuCards.erase(cpuCards.begin());

                // Adds to pile
                cardPile.push_back(userWar);
                cardPile.push_back(cpuWar);

                int userWarValue = userWar.getWarValue();
                int cpuWarValue = cpuWar.getWarValue();

                // War win conditions
                if (userWarValue > cpuWarValue) {
                    cout << "You win this war, " << userWarValue << " beats " << cpuWarValue << "." << endl;
                    userCards.insert(userCards.end(), cardPile.begin(), cardPile.end());
                    cardPile.clear();
                    warTime = false;
                } else if (userWarValue < cpuWarValue) {
                    cout << "CPU wins this war, " << cpuWarValue << " beats " << userWarValue << "." << endl;
                    cpuCards.insert(cpuCards.end(), cardPile.begin(), cardPile.end());
                    cardPile.clear();
                    warTime = false;
                } else {
                    cout << "WAR CONTINUES ON! STAKES DOUBLE!" << endl;
                }

            }
        }
        cout << "You now have " << userCards.size() << " cards." << endl;
        cout << "The CPU has " << cpuCards.size() << " cards." << endl;
        cout << "-------------------------" << endl;
    }
    if (userCards.empty()) {
        cout << "You are out of cards! CPU wins the war!" << endl;
    } else if ( cpuCards.empty()) {
         cout << "CPU is out of cards! You win the war!" << endl;
         cout << "You have won 1000 bonus chips." << endl;
         player->account.addToBank(1000);
         player->save();
    }
}
