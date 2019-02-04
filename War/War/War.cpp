#include "stdafx.h"
#include "Card.h"
#include <string>
#include <iostream>
#include <cstdlib>   
#include <ctime>     
#include <vector>

using std::vector;


// Prototypes
void shuffleDeck(vector<Card>&);
void printDeck(vector<Card>);
vector<Card> createDeck();
void playGame(vector<Card>);
void compareCards(vector<Card>&, vector<Card>&, vector<Card>&);


int main()
{
	srand(time(0)); // seeds for random
	vector<Card> deck = createDeck(); // creates vector of deck of cards
	shuffleDeck(deck); // Shuffles Deck Order
	playGame(deck); // Main game func





    return 0;
}

// Pre: Pass in a Card array (deck)
// Post: Creates 52 cards, one for each value/suit combo
vector<Card> createDeck()
{
	vector<Card> deck;

	// for value
	for (int i = 1; i <= 13; i++)
	{
		// for suit
		for (int s = 0; s < 4; s++)
		{
			switch (s)
			{
			case 0:
				deck.push_back(Card(i, "Diamonds"));
				break;
			case 1:
				deck.push_back(Card(i, "Hearts"));
				break;
			case 2:
				deck.push_back(Card(i, "Spades"));
				break;
			case 3:
				deck.push_back(Card(i, "Clubs"));
				break;
			default:
				break;
			}
		}
	}
	return deck;
}

// Pre: Pass in a Card array (deck)
// Post: Prints out values of each card
void printDeck(vector<Card> deck)
{
	for (int i = 0; i < deck.size(); i++)
	{
		std::cout << deck.at(i);
	}
}

// Pre: Need to input Card array object
// Post: Shuffles deck of cards
void shuffleDeck(vector<Card> &deck)
{
	for (int i = 0; i < deck.size(); i++)
	{
		int rand = (std::rand() % deck.size()); // random number between 0 and deck size
		Card tmp = deck[i]; // tmporary card
		deck[i] = deck[rand]; // swaps i and rand positions
		deck[rand] = tmp;
	}
}

// Pre: Need to input Card array of main (shuffled) deck
// Post: Game ends
void playGame(vector<Card> deck)
{

	// Initialize both decks and points
	vector<Card> playerOneDeck;
	vector<Card> playerTwoDeck;

	// Deals Cards to each player's deck
	for (int i = 0; i < 52; i++)
	{
		if (i % 2 == 0)
		{
			playerOneDeck.push_back(deck[i]); // fill playerOne's deck =
		}
		else
		{
			playerTwoDeck.push_back(deck[i]); // fill playerTwo's deck
		}
	}

	vector<Card> tmpStack; // temporary deck stack
	compareCards(playerOneDeck, playerTwoDeck, tmpStack); // compares cards to see who wins round
	


	

	
}

// Pre: Need to pass in both player's decks and tmpStack which holds cards that winner of round will get
// Post: Keeps comparing cards until a deck reaches zero.
void compareCards(vector<Card> &deckOne, vector<Card> &deckTwo, vector<Card> &tmpStack)
{
	// If either deck is empty, game ends
	if (deckOne.empty() || deckTwo.empty())
	{
		return; // game over
	}

	// Each round outputs to console # of cards in each player's deck
	std::cout << "Player 1 Cards: " << deckOne.size() << "\nPlayer 2 Cards: " << deckTwo.size() << "\n\n";

	Card playerOneCard = deckOne.back(); // stores value of player1's card
	Card playerTwoCard = deckTwo.back(); // stores value of player2's card

	// Adds two played cards to tmpStack
	tmpStack.push_back(playerOneCard);
	tmpStack.push_back(playerTwoCard);

	std::cout << playerOneCard << " vs " << playerTwoCard << "\n";

	// Only if Aces being played
	if (playerOneCard.getValue() == 1 || playerTwoCard.getValue() == 1)
	{
		// Player 1 has Ace, Player 2 doesn't
		if (playerOneCard.getValue() == 1 && playerTwoCard.getValue() != 1)
		{
			std::cout << "Player 1 wins\n";
			shuffleDeck(tmpStack); // shuffles tmpStack 
			deckOne.insert(deckOne.begin(), tmpStack.begin(), tmpStack.end()); // inserts tmpStack at beginning of winner's deck
			tmpStack.clear(); // clears tmpStack for next round
			deckOne.pop_back(); // deletes top 2 cards on deck
			deckTwo.pop_back();
			compareCards(deckOne, deckTwo, tmpStack); // recursively continues the game
		}
		// Player 2 has Ace, Player 1 Doesn't
		else if (playerOneCard.getValue() != 1 && playerTwoCard.getValue() == 1)
		{
			std::cout << "Player 2 wins\n";
			shuffleDeck(tmpStack);
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
			tmpStack.push_back(deckOne.back());
			tmpStack.push_back(deckOne.back());
			deckOne.pop_back();
			deckTwo.pop_back();
			compareCards(deckOne, deckTwo, tmpStack); // recursively continues the game
		}
	}
	// if Aces not played
	else
	{
		// player1 Wins
		if (playerOneCard.getValue() > playerTwoCard.getValue())
		{
			std::cout << "Player one wins \n";
			shuffleDeck(tmpStack);
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
			shuffleDeck(tmpStack); // shuffle tmpStack
			deckTwo.insert(deckTwo.begin(), tmpStack.begin(), tmpStack.end()); // put tmpStack Cards on bottom
			tmpStack.clear(); // empty TmpStack
			// Delete 2 played cards
			deckOne.pop_back(); 
			deckTwo.pop_back();
			compareCards(deckOne, deckTwo, tmpStack); // recursively continues the game
		}
		else // their cards are the same
		{
			std::cout << "WAR!";
			// delete top cards from each deck
			deckOne.pop_back();
			deckTwo.pop_back();
			tmpStack.push_back(deckOne.back());
			tmpStack.push_back(deckOne.back());
			deckOne.pop_back();
			deckTwo.pop_back();
			compareCards(deckOne, deckTwo, tmpStack); // recursively continues the game
		}
	}

}

