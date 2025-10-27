//
// Created by Jacob Pancoast on 9/9/2025.
//
#ifndef CARD_H
#define CARD_H
#include <map>
#include <iostream>
using namespace std;

/* Card Class
 * The Card class represents a standard playing card, for this case it is
 * used for Blackjack, but it could be adapted for other card games. At
 * initialization, a card is randomly assigned a suit and rank which can
 * be retrieved as well as the Blackjack value of the card.
 */

class Card {

public:
  // The Suits enumerated class defines the different suits a card can have
  enum class Suits {
    Spades,
    Hearts,
    Diamonds,
    Clubs
  };

  // The ranks enumerated class defines the different ranks a card can have
  enum class Ranks {
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
  };

  /* Default constructor
   * Requires: nothing
   * Modifies: suit and rank
   * Effects: Creates a new card object with a random suit
   *          and a random rank
   */
  Card();

  /* Alternate constructor
   * Requires: suit and rank
   * Modifies: suit and rank
   * Effects: Creates a new card object with a specific suit and rank
   */
  Card(Suits s, Ranks r);

  /* Getters use a switch statement to return the string
   * value of the suit/rank
   */
  Suits getSuit() const;
  Ranks getRank() const;
  int GetNumSuits() const;
  int GetNumRanks() const;


  /* getValue
   * Requires: nothing
   * Modifies: nothing
   * Effects: returns the point value of the card object,
   *          ex. King = 10, Seven = 7.
   */
  int getValue(Ranks rank);

  /* getWarValue
   * Requires: nothing
   * Modifies: nothing
   * Effects: returns the point value in war of the card object,
   *          ex. King = 13, Seven = 7, with Ace being highest (14).
   */
  int getWarValue() const;

  friend ostream& operator<<(ostream& os, const Card& obj);

private:
  // Each card has a suit and a rank
  Suits suit;
  Ranks rank;

  // Defines how many possible suits and ranks there are
  static const int NUMSUITS = 4;
  static const int NUMRANKS = 13;

};

#endif //CARD_H
