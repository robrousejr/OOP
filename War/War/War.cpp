#include "stdafx.h"
#include "Card.h"
#include <string>
#include <iostream>
#include <cstdlib>   
#include <ctime>     
#include <vector>
#include <algorithm>
#include <random>

using std::vector;
using std::random_shuffle;

// Prototypes
void printDeck(vector<Card>);
vector<Card> createDeck(int);
void playGame(vector<Card>);
void compareCards(vector<Card>&, vector<Card>&);


int main()
{
	// FIXME: Make More Random!
	srand(time(0)); // seeds for random 
	vector<Card> deck = createDeck(52); // creates vector of deck of cards
	vector<Card> deckWithJokers = createDeck(54); // creates vector including jokers
	random_shuffle(deck.begin(), deck.end()); // shuffles deck before game
	playGame(deck); // Main game func

    return 0;
}

// Pre: Pass in a Card array (deck)
// Post: Creates 52 cards, one for each value/suit combo
vector<Card> createDeck(int numCards)
{
	vector<Card> deck; // create deck

	// fills with int8_t's
	for (int8_t i = 1; i <= numCards; i++)
	{
		deck.push_back(Card(i)); // fill with 52 values
	}

	return deck;
}

// Pre: Pass in a Card array (deck)
// Post: Prints out values of each card
void printDeck(vector<Card> deck)
{
	for (int i = 0; i < deck.size(); i++)
	{
		std::cout << deck.at(i) << "\n";
	}
}

// Pre: need to input card array of main (shuffled) deck
// Post: game ends
void playGame(vector<Card> deck)
{

	// initialize both decks and points
	vector<Card> playerOneDeck;
	vector<Card> playerTwoDeck;

	// deals cards to each player's deck
	for (int i = 0; i < 52; i++)
	{
		if (i % 2 == 0)
		{
			playerOneDeck.push_back(deck[i]); // fill playerOne's deck
		}
		else
		{
			playerTwoDeck.push_back(deck[i]); // fill playerTwo's deck
		}
	}

	compareCards(playerOneDeck, playerTwoDeck); // compares cards to see who wins round
	
}

void compareCards(vector<Card> &deckOne, vector<Card> &deckTwo)
{
	vector<Card> pile; // holds pile of winnings

	// Until a player loses all cards
	while (!deckOne.empty() && !deckTwo.empty())
	{
		std::cout << "\nPlayer 1 Deck: " << deckOne.size();
		std::cout << "\nPlayer 2 Deck: " << deckTwo.size();
		std::cout << std::endl << deckOne.back() << " vs " << deckTwo.back();

		// Push both cards into pile
		pile.push_back(deckOne.back());
		pile.push_back(deckTwo.back());

		// Ace(s) being played
		if (deckOne.back().getValue() % 13 == 0 || deckTwo.back().getValue() % 13 == 0)
		{
			// Player 1: Ace, Player 2: non-Ace
			if (deckOne.back().getValue() % 13 == 0 && deckTwo.back().getValue() % 13 != 0)
			{
				std::cout << "\nPlayer 1 Wins!";
				
				// Deletes played cards
				deckOne.pop_back();
				deckTwo.pop_back();

				// Shuffle pile
				random_shuffle(pile.begin(), pile.end());

				deckOne.insert(deckOne.begin(), pile.begin(), pile.end()); // inserts won cards
				pile.clear(); // clears pile
			}

			// Player 1: non-Ace, player 2: Ace
			else if (deckOne.back().getValue() % 13 != 0 && deckTwo.back().getValue() % 13 == 0)
			{
				std::cout << "\nPlayer 2 Wins!";
				
				// Deletes played cards
				deckOne.pop_back();
				deckTwo.pop_back();

				// Shuffle pile
				random_shuffle(pile.begin(), pile.end());

				deckTwo.insert(deckTwo.begin(), pile.begin(), pile.end()); // inserts won cards
				pile.clear(); // clears pile
			}

			// Player 1: Ace, Player 2: Ace
			else
			{
				std::cout << "\nWAR!";

				// Deletes played cards
				deckOne.pop_back();
				deckTwo.pop_back();

				// If either playere has < 2 Cards they can't do a war
				if (deckOne.size() < 2)
				{
					std::cout << "\nPlayer 1 Doesn't have enough cards for this war. Player 2 Wins!\n";
					return;
				}
				else if (deckTwo.size() < 2)
				{
					std::cout << "\nPlayer 2 Doesn't have enough cards for this war. Player 1 Wins!\n";
					return;
				}

				// Add 2 more cards to pile
				pile.push_back(deckOne.back());
				pile.push_back(deckTwo.back());

				// Delete cards that were added to pile
				deckOne.pop_back();
				deckTwo.pop_back();

			}
		}

		// No Aces
		else
		{
			// Player1 > Player2
			if (deckOne.back().getValue() % 13 > deckTwo.back().getValue() % 13)
			{
				std::cout << "\nPlayer 1 Wins!";

				// Deletes played cards
				deckOne.pop_back();
				deckTwo.pop_back();

				// Shuffle pile
				random_shuffle(pile.begin(), pile.end());

				deckOne.insert(deckOne.begin(), pile.begin(), pile.end()); // inserts won cards
				pile.clear(); // clears pile
			}

			// Player1 < player2
			else if (deckOne.back().getValue() % 13 < deckTwo.back().getValue() % 13)
			{
				std::cout << "\nPlayer 2 Wins!";

				// Deletes played cards
				deckOne.pop_back();
				deckTwo.pop_back();

				// Shuffle pile
				random_shuffle(pile.begin(), pile.end());

				deckTwo.insert(deckTwo.begin(), pile.begin(), pile.end()); // inserts won cards
				pile.clear(); // clears pile
			}

			// player1 == player2
			else
			{
				std::cout << "\nWAR!";

				// Deletes played cards
				deckOne.pop_back();
				deckTwo.pop_back();

				// If either player has < 2 Cards they can't do a war
				if (deckOne.size() < 2)
				{
					std::cout << "\nPlayer 1 Doesn't have enough cards for this war. Player 2 Wins!\n";
					return;
				}
				else if (deckTwo.size() < 2)
				{
					std::cout << "\nPlayer 2 Doesn't have enough cards for this war. Player 1 Wins!\n";
					return;
				}

				// Add 2 more cards each to pile
				pile.push_back(deckOne.back());
				pile.push_back(deckTwo.back());

				// Delete cards that were added to pile
				deckOne.pop_back();
				deckTwo.pop_back();
			}
		}




	}
}

// pre: need to pass in both player's decks and tmpStack which holds cards that winner of round will get
// post: keeps comparing cards until a deck reaches zero.
/*void compareCards(vector<Card> &deckOne, vector<Card> &deckTwo, vector<Card> &tmpStack)
{
	
	
	// no aces played
	else
	{
		// player1 Wins
		if (playerOneCard.getValue() % 13 > playerTwoCard.getValue() % 13)
		{
			std::cout << "Player one wins \n";
			random_shuffle(tmpStack.begin(), tmpStack.end());
			deckOne.insert(deckOne.begin(), tmpStack.begin(), tmpStack.end());
			tmpStack.clear();
			deckOne.pop_back();
			deckTwo.pop_back();
			compareCards(deckOne, deckTwo, tmpStack); // recursively continues the game
		}
		// Player 2 wins
		else if (playerTwoCard.getValue() > playerOneCard.getValue())
		{
			std::cout << "Player two wins \n";
			random_shuffle(tmpStack.begin(), tmpStack.end()); // shuffle tmpStack
			deckTwo.insert(deckTwo.begin(), tmpStack.begin(), tmpStack.end()); // put tmpStack Cards on bottom
			tmpStack.clear(); // empty TmpStack
			// Delete 2 played cards
			deckOne.pop_back();
			deckTwo.pop_back();
			compareCards(deckOne, deckTwo, tmpStack); // recursively continues the game
		}
		else // their cards are the same
		{
			std::cout << "WAR!\n";
			// delete top cards from each deck
			deckOne.pop_back();
			deckTwo.pop_back();
			tmpStack.push_back(deckOne.back());
			tmpStack.push_back(deckTwo.back());
			tmpStack.push_back(deckOne.back());
			tmpStack.push_back(deckTwo.back());
			// Deletes top cards from each deck
			if (deckOne.size() <= 2 || deckTwo.size() <= 2)
			{
				if (deckOne.size() <= 2)
				{
					deckOne.clear();
				}
				else
				{
					deckTwo.clear();
				}
			}
			else
			{
				deckOne.pop_back();
				deckOne.pop_back();
				deckTwo.pop_back();
				deckTwo.pop_back();
			}
			compareCards(deckOne, deckTwo, tmpStack); // recursively continues the game
		}
	}


	
}*/


