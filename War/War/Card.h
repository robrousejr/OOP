#pragma once
#include <string>
using std::string;

class Card
{
private:
	int8_t suitAndValue;

public:

	// Default constructor
	Card() {};


	// Prototypes
	Card(int8_t);
	~Card();


	Card(const Card &c2) { suitAndValue = c2.suitAndValue; } // Copy Constructor

	//Getters
	int getValue()
	{
		return (int)suitAndValue % 13;
	}


	// setters
	/*void setValue(int v) { value = v; };
	void setSuit(string s) { suit = s; };*/

	// Overloaded << so we can print out card object
	friend std::ostream& operator<< (std::ostream& os, const Card& item)
	{

		if (item.suitAndValue <= 13)
		{
			if ((int)item.suitAndValue == 13)
			{
				return os << "Ace of Spades";
			}
			if (item.suitAndValue == 12)
			{
				return os << "King of Spades";
			}
			if (item.suitAndValue == 11)
			{
				return os << "Queen of Spades";
			}
			if (item.suitAndValue == 10)
			{
				return os << "Jack of Spades";
			}
			else
			{
				return os << (int)item.suitAndValue + 1 << " of Spades";
			}
		}
		if (item.suitAndValue > 13 && item.suitAndValue <= 26)
		{
			if ((int)item.suitAndValue % 13 == 0)
			{
				return os << "Ace of Diamonds";
			}
			if ((int)item.suitAndValue % 13 == 12)
			{
				return os << "King of Diamonds";
			}
			if ((int)item.suitAndValue % 13 == 11)
			{
				return os << "Queen of Diamonds";
			}
			if ((int)item.suitAndValue % 13 == 10)
			{
				return os << "Jack of Diamonds";
			}
			else
			{
				return os << (int)item.suitAndValue % 13 + 1 << " of Diamonds";
			}
		}
		if (item.suitAndValue > 26 && item.suitAndValue <= 39)
		{
			if ((int)item.suitAndValue % 13 == 0)
			{
				return os << "Ace of Hearts";
			}
			if ((int)item.suitAndValue % 13 == 12)
			{
				return os << "King of Hearts";
			}
			if ((int)item.suitAndValue % 13 == 11)
			{
				return os << "Queen of Hearts";
			}
			if ((int)item.suitAndValue % 13 == 10)
			{
				return os << "Jack of Hearts";
			}
			else
			{
				return os << (int)item.suitAndValue % 13 + 1 << " of Hearts";
			}
		}
		if (item.suitAndValue > 39 && item.suitAndValue <= 52)
		{
			if ((int)item.suitAndValue % 13 == 0)
			{
				return os << "Ace of Clubs";
			}
			if ((int)item.suitAndValue % 13 == 12)
			{
				return os << "King of Clubs";
			}
			if ((int)item.suitAndValue % 13 == 11)
			{
				return os << "Queen of Clubs";
			}
			if ((int)item.suitAndValue % 13 == 10)
			{
				return os << "Jack of Clubs";
			}
			else
			{
				return os << (int)item.suitAndValue % 13 + 1 << " of Clubs";
			}
		}
		else
		{
			if (item.suitAndValue == 53)
			{
				return os << "Red Joker";
			}
			else if (item.suitAndValue == 54)
			{
				return os << "Black Joker";
			}
		}

		
	}




};

