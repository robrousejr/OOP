#include <time.h>
#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace sf;

int main();

// Prototypes
void Tick(Game&);
void timeDelay(float&, Game&);
void directionTick(int&);


int dir, num = 4;

struct Snake
{
	int x, y;
} s[100]; // ASK: What significance does this have?

struct Fruct
{
	int x, y;
}f;

int main()
{
	srand(time(0));
	Game mainGame(30, 20, 16, 0.1); // Columns: 30, Rows: 20, Size: 16

	RenderWindow window(VideoMode(mainGame.getWidth(), mainGame.getHeight()), "Snake Game!");

	Texture t1, t2;
	t1.loadFromFile("images/white.png");
	t2.loadFromFile("images/red.png");

	Sprite sprite1(t1);
	Sprite sprite2(t2);

	Clock clock;
	float timer = 0;

	f.x = 10;
	f.y = 10;

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

		timeDelay(timer, mainGame);

		////// draw  ///////
		window.clear();

		for (int i = 0; i < mainGame.getColumns(); i++)
			for (int j = 0; j < mainGame.getRows(); j++) {
				sprite1.setPosition(i * mainGame.getSize(), j * mainGame.getSize());
				window.draw(sprite1);
			}

		for (int i = 0; i < num; i++) {
			sprite2.setPosition(s[i].x * mainGame.getSize(), s[i].y * mainGame.getSize());
			window.draw(sprite2);
		}

		sprite2.setPosition(f.x * mainGame.getSize(), f.y * mainGame.getSize());
		window.draw(sprite2);

		window.display();
	}

	return 0;
}

void Tick(Game &mainGame)
{
	for (int i = num; i > 0; --i) {
		s[i].x = s[i - 1].x;
		s[i].y = s[i - 1].y;
	}

	directionTick(dir); // Changes direction of Snake

	if ((s[0].x == f.x) && (s[0].y == f.y)) {
		num++;
		f.x = rand() % mainGame.getColumns();
		f.y = rand() % mainGame.getRows();
	}

	if (s[0].x > mainGame.getColumns())
		s[0].x = 0;
	if (s[0].x < 0)
		s[0].x = mainGame.getColumns();
	if (s[0].y > mainGame.getRows())
		s[0].y = 0;
	if (s[0].y < 0)
		s[0].y = mainGame.getRows();

	for (int i = 1; i < num; i++)
		if (s[0].x == s[i].x && s[0].y == s[i].y)
			num = i;
}

// Resets timer if delay > timer
void timeDelay(float &timer, Game &mainGame)
{
	if (timer > mainGame.getDelay()) {
		timer = 0;
		Tick(mainGame);
	}
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