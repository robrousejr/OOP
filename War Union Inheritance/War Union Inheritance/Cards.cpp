#include "stdafx.h"
#include "Cards.h"

// Standard Card constructor
StandardCard::StandardCard(Suit s, Rank r)
{
	// Setting values for suit and rank 
	suit = s;
	rank = r;
}

// Joker card constructor
JokerCard::JokerCard(Color c)
{
	color = c;
}

// Pre: None
// Post: Returns if card is Standard type
bool Card::isStandardCard()
{
	if (type == Standard)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Pre: 
// Post: Returns if card is Joker type
bool Card::isJokerCard()
{
	if (type == Joker)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Pre: Pass in Card's rank value
// Post: Outputs to os the rank
ostream & operator<<(ostream & os, Rank rank)
{
	switch (rank)
	{
	case Two:
		return os << "Two";
	case Three:
		return os << "Three";
	case Four:
		return os << "Four";
	case Five:
		return os << "Five";
	case Six:
		return os << "Six";
	case Seven:
		return os << "Seven";
	case Eight:
		return os << "Eight";
	case Nine:
		return os << "Nine";
	case Ten:
		return os << "Ten";
	case Jack:
		return os << "Jack";
	case Queen:
		return os << "Queen";
	case King:
		return os << "King";
	case Ace:
		return os << "Ace";
	}
}

// Pre: Pass in Card's suit value
// Post: outputs to OS the suit
ostream & operator<<(ostream & os, Suit suit)
{
	switch (suit)
	{
	case Diamonds:
		return os << "Diamonds";
	case Spades:
		return os << "Spades";
	case Hearts:
		return os << "Hearts";
	case Clubs:
		return os << "Clubs";
	}
}

// Pre: Pass in Card's color
// Post: outputs to OS the color
ostream & operator<<(ostream & os, Color color)
{
	switch (color)
	{
	case Red:
		return os << "Red";
	case Black:
		return os << "Black";
	}
}

// Pre: Pass in Card
// Post: Outputs to OS the data for the card
ostream & operator<<(ostream & os, Card card)
{
	// Standard Card
	if (card.isStandardCard())
	{
		return os << card.getRank() << " of " << card.getSuit();
	}
	// Joker Card
	else
	{
		return os << card.getColor() << " Joker";
	}
}

ostream & operator<<(ostream & os, Deck & deck)
{
	int size = deck.size(); // number of elements in deck

							// Iterate through whole deck
	for (int i = 0; i < size; i++)
	{
		os << deck[i] << "\n"; // Prints out card value
	}

	return os;
}

// Returns bool value for if cards are equal
bool operator==(Card one, Card two)
{
	if (one.getRank() == two.getRank())
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Returns bool value for if card one > card two
bool operator<(Card one, Card two)
{
	if (one.getRank() < two.getRank())
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Returns bool value for if card one < card two
bool operator>(Card one, Card two)
{
	if (one.getRank() > two.getRank())
	{
		return true;
	}
	else
	{
		return false;
	}
}


