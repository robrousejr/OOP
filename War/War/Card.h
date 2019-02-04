#pragma once
#include <string>
using std::string;

class Card
{
private:
	string suit;
	int value;

public:

	// Default constructor
	Card() {};

	
	// Prototypes
	Card(int, string);
	~Card();

	Card(const Card &c2) { suit = c2.suit; value = c2.value; } // Copy Constructor


	// getters
	int getValue() const{ return value; };
	string getSuit() const{ return suit; };

	// setters
	void setValue(int v) { value = v; };
	void setSuit(string s) { suit = s; };

	// Overloaded << so we can print out card object
	friend std::ostream& operator<< (std::ostream& os, const Card& item)
	{
		switch (item.value)
		{
		case 13: 
			return os << "King of " << item.suit;
			break;
		case 12:
			return os << "Queen of " << item.suit;
			break;
		case 11:
			return os << "Jack of " << item.suit;
			break;
		case 1:
			return os << "Ace of " << item.suit;
			break;
		default:
			return os << item.value << " of " << item.suit;
			break;
		}
		
	}

};

