//
// Created by Jacob Pancoast on 9/9/2025.
//

#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Card.h"
#include "../Game.h"
#include <vector>

/* Blackjack Class
 * The Blackjack class represents a Blackjack object (a game of Blackjack).
 * A Blackjack game interacts with the player to play a standard game of
 * Blackjack and keeps track of their hand and value total, as well as that
 * same information for the dealer. Each of the methods of the class are
 * defined below.
 */

class Blackjack : public Game {
    private:
        /* Private class constant
         */
        int const BLACKJACK = 21;

        /* Private class instance variables
         */
        int gameBet;
        int dealerTotal;
        int playerTotal;
        std::vector<Card> dealerHand;
        std::vector<Card> playerHand;

        /* Rules()
        * Requires: N/A
        * Modifies: N/A
        * Effects: Prints the rules for Blackjack and calls options()
        */
        void rules();

        /* Options()
         * Requires: N/A
         * Modifies: N/A
         * Effects: Prints the possible pre-game options to the console
         */
        void options() const;

        /* Bet()
         * Requires: N/A
         * Modifies: N/A
         * Effects: If bet is chosen in the pre-game, user is prompted
         *  for an amount (with input validation) where the bet must be
         *  between 0 and their balance.
         */
        void bet();

        /* CardValues()
         * Requires: N/A
         * Modifies: N/A
         * Effects: Prints the card values
         */
        void cardValues();

        /* Phase1()
         * Requires: N/A
         * Modifies: dealerHand, dealerTotal, playerHand, playerTotal
         * Effects: Draws 2 cards for the dealer and 2 for the player, then
         *  adds them to each player's deck and hand. Also prints what cards
         *  were drawn and what each person's current total is.
         */
        void phase1();

        /* Choose()
         * Requires: N/A
         * Modifies: N/A
         * Effects: Gets a character "h" or "s" to determine if the user wants
         *  to hit or stand.
         */
        char choose();

        /* Hit()
         * Requires: N/A
         * Modifies: playerHand and playerTotal
         * Effects: Draws another card for the user and adds it to their hand
         *  and value total.
         */
        void hit();

        /* Stand()
         * Requires: N/A
         * Modifies: dealerHand and dealerTotal
         * Effects: Lets the dealer draw until they are >= 17 in total.
         */
        void stand();

        /* Evaluate()
         * Requires: N/A
         * Modifies: balance
         * Effects: Evaluates the win condition factoring in if the player or
         *  dealer went bust, as well as who had more value if both were <= 21.
         */
        void evaluate();

        /* Reset()
         * Requires: N/A
         * Modifies: dealerTotal, dealerHand, playerTotal, playerHand, gameBet
         * Effects: Resets all class instance variables in case user wants to
         *  play again.
         */
        void reset();

    public:
        /* Default constructor
        * Requires: balance, an integer
        * Modifies: this->balance
        * Effects: Initializes the object and sets this->balance for the object
        */
        explicit Blackjack(Player* player) : Game(player), playerTotal(0), dealerTotal(0), gameBet(0) {}

        /* Play()
         * Requires: N/A
         * Modifies: Game state
         * Effects: Runs the game itself and handles transitions between game
         *  states.
         */
        void PlayGame() override;


};



#endif //BLACKJACK_H
