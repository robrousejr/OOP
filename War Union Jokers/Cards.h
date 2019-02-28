#pragma once
#include <deque>
#include <ostream>

// Using
using std::deque;
using std::ostream;


enum Suit {
	Spades, 
	Clubs,
	Diamonds, 
	Hearts
};

enum Color {
	Red, 
	Black
};

enum Rank {
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
	King,
	Ace
};

class StandardCard {
private:
	Suit suit;
	Rank rank;
public:
	// Constructor
	StandardCard(Suit s, Rank r);
	// Getters
	Suit getSuit() { return suit; }
	Rank getRank() { return rank; }
};

class JokerCard {
private:
	Color color;
public:
	// Main joker constructor
	JokerCard(Color c);
	// Getter 
	Color getColor() { return color; }

};


// Union combining both Joker/Standard Cards
union CardUnion
{
	// Initializing the two cards
	JokerCard joker; 
	StandardCard standard;

	// Constructors for both types of cards
	CardUnion(Suit s, Rank r) : standard(s, r) {}
	CardUnion(Color c) : joker(c) {}

};


// Tagged union
enum TypeOfCard {
	Standard,
	Joker
};

class Card {
private:
	CardUnion data;
	TypeOfCard type;
public:
	// Standard constructor
	Card(Suit s, Rank r) : data(s, r), type(Standard) { }
	// Joker constructor
	Card(Color c) : data(c), type(Joker) { }

	// Getters
	bool isStandardCard();
	bool isJokerCard();
	Suit getSuit() { return data.standard.getSuit(); } 
	Rank getRank() { return data.standard.getRank(); }
	Color getColor() { return data.joker.getColor(); }
	StandardCard getStandardCard() { return data.standard; }
	JokerCard getJokerCard() { return data.joker; }
};

struct Deck : deque<Card>
{
	// Shown in class to do this
	using deque<Card>::deque;
};

// Ostream functions
ostream& operator<<(ostream &os, Rank rank); // rank ostream
ostream& operator<<(ostream &os, Suit suit); // suit ostream
ostream& operator<<(ostream& os, Color color); // color ostream
ostream& operator<<(ostream& os, Card card); // Card ostream
ostream& operator<<(ostream& os, Deck &deck); // Deck ostream

// Logical Functions
bool operator==(Card one, Card two);
bool operator<(Card one, Card two);
bool operator>(Card one, Card two);


