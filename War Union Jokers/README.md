# War (Union Joker Version)

### How Game Works

1. The deck is divided evenly, with each player receiving half the deck, dealt one at a time, face down. Anyone may deal first. Each player places his stack of cards face down, in front of him.
2. Each player turns up a card at the same time and the player with the higher card takes both cards and puts them, face down, on the bottom of his stack.
3. If the cards are the same rank, it is War. Each player turns up one card each face down and one card face up. The player with the higher cards takes both piles (six cards). If the turned-up cards are again the same rank, each player places another card face down and turns another card face up. The player with the higher card takes all 10 cards, and so on.
4. This continues until one player runs out of cards, marking the other player the winner
5. In this version, **Jokers are the lowest card** and Aces are the highest.  

*[Source](https://www.bicyclecards.com/how-to-play/war/)*

### Implementing The Game

The *main.cpp* file starts by seeding using the time. Then, a deck is made with every combination, including the jokers. The deck is then shuffled, and the *startGame()* function is called, which then creates a deck for each player, and deals cards to them evenly distributing the main deck using the *dealCards()* function. Then, the *playGame()* function is called which is the final function of the game, and compares cards in a while loop, awarding the winning player the cards layed down in the pile until a player runs out of cards or cannot play anything, resulting in a victory for the other player. 

* Cards.h - Enums were created in increasing order for Suit, Rank, and Color. A class, *StandardCard* was then created which takes a suit and a rank. Then a class, *JokerCard* was created which just took a color. **Then, a union was created between StandardCard and JokerCard for optimization.** Then, a *Card* class was made which took in the union and was a parent over both the JokerCard and StandardCards. Finally, all of the ostream functions and operator overloading functions were defined which helped with the logic of the game tremendously. 
