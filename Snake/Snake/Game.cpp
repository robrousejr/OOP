#include "Game.h"

// Constructor
Game::Game(int n, int m, int s)
{
	columns = n;
	rows = m;
	size = s;
	width = s * n; 
	height = s * m;
}
