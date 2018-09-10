#include "stdafx.h"
#include "Puzzle.h"


Puzzle::Puzzle(int _dimension)
{
	dimension = _dimension;

	blankSpace = dimension * dimension;

	// Give the board its width dimension
	board.resize(dimension);

	for (int i = 0; i < dimension; i++) {

		// Give the height dimension
		board[i].resize(dimension);

		for (int j = 0; j < dimension; j++) {
			int value = (i * dimension) + j + 1;
			Vertex* vertex = new Vertex(i, j, value);
			board[i][j] = vertex;
		}
	}

	Shuffle();
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
			if (board[i][j]->GetValue() == blankSpace) {
				return board[i][j];
			}
		}
	}

	return nullptr;
}

/*
	* Swap the chosen space with the blank space
*/
void Puzzle::Swap(int x1, int y1, int x2, int y2)
{
	int tempValue = board[x1][y1]->GetValue();
	board[x1][y1]->SetValue(board[x2][y2]->GetValue());
	board[x2][y2]->SetValue(tempValue);
}

/*
	* Prints out the current puzle
*/
void Puzzle::Print() {
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			if (board[i][j]->GetValue() == blankSpace)
				cout << " |";
			else
				cout << board[i][j]->GetValue() << "|";
		}
		cout << endl;
	}
}

/*
	* Randomly swaps around pieces to shuffle
*/
void Puzzle::Shuffle()
{
	srand(time(NULL));

	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {

			// Randomly get an x and y to choose a vert
			int randX = rand() % dimension;
			int randY = rand() % dimension;

			Vertex* thisVert = board[i][j];
			Vertex* swapVert = board[randX][randY];

			// Swap the values of this vert and the random vert
			int thisValue = thisVert->GetValue();
			thisVert->SetValue(swapVert->GetValue());
			swapVert->SetValue(thisValue);
		}
	}

}

/*
	* Check to see if the puzzle is solved
*/
bool Puzzle::CheckSolved()
{
	// We use the same loops that we do to create the puzzle, before shuffling, to get the completed puzzle
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {

			// The inital value that this vertex would have prior to shuffling
			int value = (i * dimension) + j + 1;


			if (board[i][j]->GetValue() != value)
				return false;
		}
	}

	return true;
}

/*
	* Gets the neighbors for the given vertex
*/
vector<Vertex*> Puzzle::GetNeighbors(Vertex* vertex)
{
	int x = vertex->GetX();
	int y = vertex->GetY();

	vector<Vertex*> neighbors;

	if(x > 0){
		neighbors.push_back(board[x - 1][y]);
	}

	if (x < dimension - 1) {
		neighbors.push_back(board[x + 1][y]);
	}

	if (y > 0) {
		neighbors.push_back(board[x][y - 1]);
	}

	if (y < dimension - 1) {
		neighbors.push_back(board[x][y + 1]);
	}


	return neighbors;
}
