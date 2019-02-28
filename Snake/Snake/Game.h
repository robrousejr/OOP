#pragma once
class Game {
private:
	int columns; // Columns
	int rows; // Rows
	int size = 16; // size of board
	int width; // Width
	int height; // height
	float delay; // delay for snake movement. Changes difficulty
public:

	// Constructor Prototype
	Game(int, int, int, float);

	// Getters
	int getColumns() { return columns; }
	int getRows() { return rows; }
	int getSize() { return size; }
	int getWidth() { return width; }
	int getHeight() { return height; }
	float getDelay() { return delay; }

	// Function Prototypes
};