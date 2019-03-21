#include "Game.h"
#include <SFML\Graphics.hpp>
using namespace sf;

// Constructor
Game::Game(int n, int m, int s, float d)
{
	columns = n;
	rows = m;
	size = s;
	delay = d;

	width = s * n; 
	height = s * m;
}
