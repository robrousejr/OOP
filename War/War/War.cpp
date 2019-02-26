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

struct Card
{

};

// Prototypes
void printDeck(vector<Card>);
vector<Card> createDeck(int);
void playGame(vector<Card>);
void compareCards(vector<Card>&, vector<Card>&, vector<Card>&);


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

	vector<Card> tmpStack; // temporary deck stack
	compareCards(playerOneDeck, playerTwoDeck, tmpStack); // compares cards to see who wins round
	
}

// pre: need to pass in both player's decks and tmpStack which holds cards that winner of round will get
// post: keeps comparing cards until a deck reaches zero.
void compareCards(vector<Card> &deckOne, vector<Card> &deckTwo, vector<Card> &tmpStack)
{
	// game over if either deck is empty
	if (deckOne.empty() || deckTwo.empty())
	{
		if (deckOne.empty())
		{
			std::cout << "\n\nPLAYER TWO WINS GAME\n\n";
		}
		else
		{
			std::cout << "\n\nPLAYER ONE WINS GAME\n\n";
		}
		return;
	}

	// Each round outputs to console # of cards in each player's deck
	std::cout << "Player 1 Cards: " << deckOne.size() << "\nPlayer 2 Cards: " << deckTwo.size() << "\n\n";

	Card playerOneCard = deckOne.back(); // stores value of player1's card
	Card playerTwoCard = deckTwo.back(); // stores value of player2's card

	// Adds two played cards to tmpStack
	tmpStack.push_back(playerOneCard);
	tmpStack.push_back(playerTwoCard);

	std::cout << playerOneCard << " vs " << playerTwoCard << "\n";


	// Aces being played
	if (playerOneCard.getValue() % 13 == 0 || playerTwoCard.getValue() % 13 == 0)
	{
		// Player one has Ace, player two doesn't
		if (playerOneCard.getValue() % 13 == 0 && playerTwoCard.getValue() % 13 != 0)
		{
			std::cout << "Player 1 wins\n";
			random_shuffle(tmpStack.begin(), tmpStack.end()); // shuffles tmpStack 
			deckOne.insert(deckOne.begin(), tmpStack.begin(), tmpStack.end()); // inserts tmpStack at beginning of winner's deck
			tmpStack.clear(); // clears tmpStack for next round
			// deletes top 2 cards on deck
			deckOne.pop_back(); 
			deckTwo.pop_back();
			compareCards(deckOne, deckTwo, tmpStack); // recursively continues the game
		}
		// Player two has Ace, player one doesn't
		else if (playerOneCard.getValue() % 13 != 0 && playerTwoCard.getValue() % 13 == 0)
		{
			std::cout << "Player 2 wins\n";
			random_shuffle(tmpStack.begin(), tmpStack.end());
			deckTwo.insert(deckTwo.begin(), tmpStack.begin(), tmpStack.end());
			tmpStack.clear();
			deckOne.pop_back();
			deckTwo.pop_back();
			compareCards(deckOne, deckTwo, tmpStack); // recursively continues the game
		}
		// They both have Aces
		else
		{
			std::cout << "WAR!\n";
			// delete top cards from each deck
			deckOne.pop_back();
			deckTwo.pop_back();
			// Puts 2 top cards on each player's deck into tmpStack
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


	
}


