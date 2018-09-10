#include "stdafx.h"
#include "Puzzle.h"


Puzzle::Puzzle(int _dimension)
{
	dimension = _dimension;

	// Give the board its width dimension
	board.resize(dimension);

	for (int i = 0; i < dimension; i++) {

		// Give the height dimension
		board[i].resize(dimension);

		for (int j = 0; j < dimension; j++) {
			int value = (i * dimension) + j;
			Vertex* vertex = new Vertex(i, j, value);
			board[i][j] = vertex;
		}
	}
}


Puzzle::~Puzzle()
{
}

/*
	* Find the vertex that contains "0" on the board
*/
Vertex* Puzzle::GetBlankSpace()
{
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			if (board[i][j]->GetValue() == 0) {
				return board[i][j];
			}
		}
	}

	return nullptr;
}

/*
	* Swap the chosen space with the blank space
*/
void Puzzle::Swap()
{

}

/*
	* Prints out the current puzle
*/
void Puzzle::Print() {
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			if (board[i][j]->GetValue() == 0)
				cout << " |";
			else
				cout << board[i][j]->GetValue() << "|";
		}
		cout << endl;
	}
}
