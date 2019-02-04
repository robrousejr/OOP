
# War
### How Game Works

1.  The deck is divided evenly, with each player receiving 26 cards, dealt one at a time, face down. Anyone may deal first. Each player places his stack of cards face down, in front of him.
2. Each player turns up a card at the same time and the player with the higher card takes both cards and puts them, face down, on the bottom of his stack.
3. If the cards are the same rank, it is War. Each player turns up one card face down and one card face up. The player with the higher cards takes both piles (six cards). If the turned-up cards are again the same rank, each player places another card face down and turns another card face up. The player with the higher card takes all 10 cards, and so on.
4. This continues until one player runs out of cards, marking the other player the winner

*[Source](https://www.bicyclecards.com/how-to-play/war/)*

---

### Implementing The Game

The *war.cpp* main function begins with seeding using the time. Then, a vector of **Card** objects is created and defined with the function createDeck() which makes a Card Object for every possible suit/rank combination. After this, the deck is then shuffled via shuffleDeck(), which is able to randomly assort the deck due to the srand(time(0)) at  the beginning of the main function.
Once this occurs, the playGame() function is called which starts off the game. 
* **playGame()** - In this function, two vectors of cards are initialized and filled with 26 cards of the 52 card deck which was passed in. Then, a vector of cards called "tmpStack" is made and used as a parameter in the most important function of the game, compareCards().
* **compareCards()** - This recursive function checks to see if either players' decks are empty at the beginning of the function, if this is true, then the game ends. If not, the function compares the values of the two played cards (not considering the suit), while maintaining Aces as the highest valued card in the deck. On the occasion when both players lay down equal value cards, a *war* is called. This makes both players lay another card down in the tmpStack (which we can assume were laid face down), and then they play their next cards, which calls the compareCards() function yet again for this. This can go on many times, with one player eventually winning the tmpStack of cards.  
--- 




