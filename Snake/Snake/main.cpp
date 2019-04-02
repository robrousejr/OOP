#include <time.h>
#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace sf;

int main();

// Prototypes
void Tick(Game&, RenderWindow&);
void timeDelay(float&, Game&, RenderWindow&);
void directionTick(int&);
void startGame();

int dir;
int num = 4; // starting tiles in snake body

struct Snake
{
	int x, y;
} s[100]; // Creates a Snake array

struct Fruct
{
	int x, y; // x blocks in, y blocks down
}f; // Snake food

struct evilFruct
{
	int x, y; // x blocks in, y blocks down
}ef; // evil food

int main()
{
	srand(time(0)); // Seed time
	startGame(); // starts game

	return 0;
}

void startGame()
{
	// columns, rows, size, delay (difficulty)
	Game mainGame(30, 20, 16, 0.1); // Columns: 30, Rows: 20, Size: 16
	RenderWindow window(VideoMode(mainGame.getWidth(), mainGame.getHeight()), "Snake Game!"); // Create window

	// Loads images
	Texture t1, t2, t3;
	t1.loadFromFile("images/white.png");
	t2.loadFromFile("images/red.png");
	t3.loadFromFile("images/evil.png");

	// Creates sprites from images
	Sprite sprite1(t1); // Background blocks
	Sprite sprite2(t2); // Snake/Food
	Sprite sprite3(t3); // Evil Snake Food

	Clock clock;
	float timer = 0;

	// Starting spot for Snake food is 1
	// 10 blocks in, 10 blocks down (start from 0)
	f.x = 10;
	f.y = 10;

	// 15 * 15 is location of evil food
	ef.x = 15;
	ef.y = 15;

	while (window.isOpen()) {
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
			dir = 1;
		if (Keyboard::isKeyPressed(Keyboard::Right))
			dir = 2;
		if (Keyboard::isKeyPressed(Keyboard::Up))
			dir = 3;
		if (Keyboard::isKeyPressed(Keyboard::Down))
			dir = 0;

		timeDelay(timer, mainGame, window); // calls game

		////// draw  ///////
		window.clear();

		// Draws background tiles for game
		for (int i = 0; i < mainGame.getColumns(); i++)
			for (int j = 0; j < mainGame.getRows(); j++) {
				sprite1.setPosition(i * mainGame.getSize(), j * mainGame.getSize());
				window.draw(sprite1);
			}

		// num is snake size
		// Draws snake 
		for (int i = 0; i < num; i++) {
			sprite2.setPosition(s[i].x * mainGame.getSize(), s[i].y * mainGame.getSize());
			window.draw(sprite2);
		}

		
		// Draws snake food
		sprite2.setPosition(f.x * mainGame.getSize(), f.y * mainGame.getSize());
		window.draw(sprite2);

		sprite3.setPosition(ef.x * mainGame.getSize(), ef.y * mainGame.getSize());
		window.draw(sprite3);

		window.display();
	}

}

// Resets timer if delay > timer
void timeDelay(float &timer, Game &mainGame, RenderWindow &window)
{
	if (timer > mainGame.getDelay()) {
		timer = 0;
		Tick(mainGame, window);
	}
}

void Tick(Game &mainGame, RenderWindow &window)
{
	// Sets up initial snake spot
	for (int i = num; i > 0; --i) {
		s[i].x = s[i - 1].x;
		s[i].y = s[i - 1].y;
	}

	directionTick(dir); // Changes direction of Snake

	// if snake eats food
	if ((s[0].x == f.x) && (s[0].y == f.y)) {
		num++;
		// Randomly place food elsewhere
		f.x = rand() % mainGame.getColumns();
		f.y = rand() % mainGame.getRows();
	}

	// If snake leaves boundaries, come in through other side
	if (s[0].x > mainGame.getColumns())
		window.close();
	if (s[0].x < 0)
		window.close();
	if (s[0].y > mainGame.getRows())
		window.close();
	if (s[0].y < 0)
		window.close();

	// checks if snake runs into itself
	for (int i = 1; i < num; i++)
		if (s[0].x == s[i].x && s[0].y == s[i].y)
			// num = i;
			window.close(); // game over
}

// Changes diretion of Snake
void directionTick(int &dir)
{
	if (dir == 0) // Down
		s[0].y += 1;
	if (dir == 1) // Left
		s[0].x -= 1;
	if (dir == 2) // Right
		s[0].x += 1;
	if (dir == 3) // Up
		s[0].y -= 1;
}