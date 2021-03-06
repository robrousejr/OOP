#include "stdafx.h"
#include "Cards.h"
#include <iostream>
#include <algorithm>
#include <ctime>

// Prototypes
void shuffleDeck(Deck&);
void startGame(Deck&);
void dealCards(Deck&, Deck&, Deck&);
void playGame(Deck&, Deck&);

int main()
{
	srand(time(0));
	// Defining mainDeck
	Deck mainDeck {
	{ Spades, Two },
	{ Spades, Three },
	{ Spades, Four },
	{ Spades, Five },
	{ Spades, Six },
	{ Spades, Seven },
	{ Spades, Eight },
	{ Spades, Nine },
	{ Spades, Ten },
	{ Spades, Jack },
	{ Spades, Queen },
	{ Spades, King },
	{ Spades, Ace },

	{ Diamonds, Two },
	{ Diamonds, Three },
	{ Diamonds, Four },
	{ Diamonds, Five },
	{ Diamonds, Six },
	{ Diamonds, Seven },
	{ Diamonds, Eight },
	{ Diamonds, Nine },
	{ Diamonds, Ten },
	{ Diamonds, Jack },
	{ Diamonds, Queen },
	{ Diamonds, King },
	{ Diamonds, Ace },

	{ Hearts, Two },
	{ Hearts, Three },
	{ Hearts, Four },
	{ Hearts, Five },
	{ Hearts, Six },
	{ Hearts, Seven },
	{ Hearts, Eight },
	{ Hearts, Nine },
	{ Hearts, Ten },
	{ Hearts, Jack },
	{ Hearts, Queen },
	{ Hearts, King },
	{ Hearts, Ace },

	{ Clubs, Two },
	{ Clubs, Three },
	{ Clubs, Four },
	{ Clubs, Five },
	{ Clubs, Six },
	{ Clubs, Seven },
	{ Clubs, Eight },
	{ Clubs, Nine },
	{ Clubs, Ten },
	{ Clubs, Jack },
	{ Clubs, Queen },
	{ Clubs, King },
	{ Clubs, Ace },

	// Jokers
	{ Black },
	{ Red }
	};
	shuffleDeck(mainDeck); // Shuffles deck to begin
	startGame(mainDeck); // Starts game

	return 0;
}

// Pre: Pass in deck
// Post: Shuffles order of cards in deck
void shuffleDeck(Deck &deck) {
	int size = deck.size(); // holds # of elements in deck
	for (int i = 0; i < size; i++) {

		int r = i + (rand() % (size - i)); // random location
		std::swap(deck[i], deck[r]); // swaps places

	}

}

// Pre: Pass in player's decks and the main deck
// Post: deals cards evenly to each player
void dealCards(Deck &player1, Deck &player2, Deck &deck)
{
	// Iterate through cards in mainDeck
	for (int i = 0; i < deck.size(); i++)
	{
		if (i % 2 == 0) // populate player1 deck 
		{
			player1.push_back(deck[i]);
		}
		else // populate player2 deck
		{
			player2.push_back(deck[i]);
		}
	}

}

// Pre: Must pass in main deck
// Deals cards and starts game
void startGame(Deck &deck)
{
	Deck player1;
	Deck player2;

	dealCards(player1, player2, deck); // Deals cards to players
	playGame(player1, player2); // playGame() function starts comparing cards

}

// Pre: Must pass in players' decks and an empty pile for the winnings
// Post: Plays out game until a player wins
void playGame(Deck &player1, Deck &player2)
{
	Deck pile; // Holds winnings

			   // Until a player loses all cards
	while (player1.size() != 0 && player2.size() != 0)
	{
		std::cout << "\nPlayer 1 Deck: " << player1.size() << std::endl;
		std::cout << "Player 2 Deck: " << player2.size() << std::endl;
		std::cout << player1.back() << " vs " << player2.back() << std::endl;

		// Push both cards into pile
		pile.push_back(player1.back());
		pile.push_back(player2.back());

		// If a joker is being played
		if (player1.back().isJokerCard() || player2.back().isJokerCard())
		{
			// JOKER/JOKER WAR
			if (player1.back().isJokerCard() && player2.back().isJokerCard())
			{
				std::cout << "WAR!\n";
				// Deletes cards from their decks
				player1.pop_back();
				player2.pop_back();


				// If either playere has < 2 Cards they can't do a war
				if (player1.size() < 2)
				{
					std::cout << "\nPlayer 1 Doesn't have enough cards for this war. Player 2 Wins!\n";
					return;
				}
				else if (player2.size() < 2)
				{
					std::cout << "\nPlayer 2 Doesn't have enough cards for this war. Player 1 Wins!\n";
					return;
				}

				// Add 2 more cards to pile
				pile.push_back(player1.back());
				pile.push_back(player2.back());

				// Delete cards that were added to pile
				player1.pop_back();
				player1.pop_back();

			}

			// Joker/Standard Card
			else if (player1.back().isJokerCard() && player2.back().isStandardCard())
			{
				// Delete Cards from their decks
				player1.pop_back();
				player2.pop_back();

				// Player 2 Wins
				std::cout << "Player 2 Wins!\n";
				player2.insert(player2.end(), pile.begin(), pile.end());
				pile.clear(); // clear pile
			}

			// Standard/Joker Card
			else if (player1.back().isStandardCard() && player2.back().isJokerCard())
			{
				// Delete Cards from their decks
				player1.pop_back();
				player2.pop_back();

				// Player 1 Wins
				std::cout << "Player 1 Wins!\n";
				player1.insert(player1.end(), pile.begin(), pile.end());
				pile.clear(); // clear pile
			}
		}

		// Both Are Standard Cards
		else
		{
			// Standard == Standard Card
			if (player1.back() == player2.back())
			{
				std::cout << "WAR!\n";

				// Deletes cards from their decks
				player1.pop_back();
				player2.pop_back();

				// If either playere has < 2 Cards they can't do a war
				if (player1.size() < 2)
				{
					std::cout << "\nPlayer 1 Doesn't have enough cards for this war. Player 2 Wins!\n";
					return;
				}
				else if (player2.size() < 2)
				{
					std::cout << "\nPlayer 2 Doesn't have enough cards for this war. Player 2 Wins!\n";
					return;
				}

				// Add 2 more cards to pile
				pile.push_back(player1.back());
				pile.push_back(player2.back());

				// Delete cards that were added to pile
				player1.pop_back();
				player1.pop_back();

			}

			// Standard > Standard Card
			else if (player1.back() > player2.back())
			{
				// Delete Cards from their decks
				player1.pop_back();
				player2.pop_back();

				// Player 1 Wins
				std::cout << "Player 1 Wins!\n";
				player1.insert(player1.end(), pile.begin(), pile.end());
				pile.clear(); // clear pile
			}

			// Standard < Standard Card
			else if (player1.back() < player2.back())
			{
				// Delete Cards from their decks
				player1.pop_back();
				player2.pop_back();

				// Player 2 Wins
				std::cout << "Player 2 Wins!\n";
				player2.insert(player2.end(), pile.begin(), pile.end());
				pile.clear(); // clear pile
			}
		}



	}

}
