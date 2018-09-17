#include "stdafx.h"
#include "Board.h"
#include <stdio.h>
#include <math.h>
#include <iomanip>

Board::Board() {

}

/*
	* COPY CONSTRUCTOR
*/
Board::Board(const Board& _board)
{
	// Copy over the dimension
	dimension = _board.dimension;

	// Store blank space
	blankSpace = dimension * dimension;

	// Copy values over for myBoard
	myBoard.resize(dimension);
	for (int i = 0; i < dimension; i++) {
		myBoard[i].resize(dimension);
		for (int j = 0; j < dimension; j++) {
			myBoard[i][j] = _board.myBoard[i][j];
		}
	}

	// Copy path
	int pathSize = static_cast<int>(_board.path.size());
	for (int i = 0; i < pathSize; i++) {
		path.push_back(_board.path[i]);
	}

	// Store last move
	lastMovedValue = _board.lastMovedValue;
}

Board::Board(int _dimension, int numOfShuffles)
{
	dimension = _dimension;

	blankSpace = dimension * dimension;

	// Give the board its width dimension
	myBoard.resize(dimension);

	for (int i = 0; i < dimension; i++) {

		// Give the height dimension
		myBoard[i].resize(dimension);

		for (int j = 0; j < dimension; j++) {
			int value = (i * dimension) + j + 1;
			myBoard[i][j] = value;
		}
	}

	Shuffle(numOfShuffles);
}

Board::~Board()
{
}

/*
	* Find the vertex that contains dimension^2 on the board
	* Store the x & y location in the board variable and return the Vertex*
*/
void Board::GetBlankSpace(int& x, int& y)
{
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			if (myBoard[i][j] == blankSpace) {
				x = i;
				y = j;
				//return myBoard[i][j];
			}
		}
	}
}

/*
	* Swap the two given verticies
*/
void Board::Swap(int vert1, int vert2) {
	int x1 = 0;
	int y1 = 0;
	GetPosition(vert1, x1, y1);
	int x2 = 0;
	int y2 = 0;
	GetPosition(vert2, x2, y2);

	myBoard[x1][y1] = vert2;
	myBoard[x2][y2] = vert1;
}

/*
	* Swaps the given value with the blank tile
*/
void Board::SwapWithBlank(int value) {
	Swap(value, blankSpace);
}

/*
	* Prints out the current board
*/
void Board::Print() {
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			if (myBoard[i][j] == blankSpace)
				cout << std::setw(3) << std::setfill(' ') << "|";
			else
				cout << std::setw(2) << std::setfill('0') << myBoard[i][j] << "|";
		}
		cout << endl;
	}
}

/*
	* Randomly swaps the blank and its neighbors to shuffle
*/
void Board::Shuffle(int numOfShuffles)
{
	// Init rand
	srand(time(NULL));

	// If numOfShuffles is 0, the user request a random shuffle number
	int numMoves = numOfShuffles;
	if (numOfShuffles == 0) {
		numMoves = (rand() % 10) + 10;
	}

	int shuffLastMoveValue = 0; // We use this so it doesn't interfere with our solution algorithims 

	// Loop for shuffling pieces
	for (int i = 0; i < numMoves; i++) {

		int blankX = 0;
		int blankY = 0;
		GetBlankSpace(blankX, blankY);

		vector<int> blankNeighbors = GetNeighbors(blankX, blankY);

		int neighborSwap = 0;

		do {
			neighborSwap = rand() % static_cast<int>(blankNeighbors.size());
		} while (blankNeighbors[neighborSwap] == shuffLastMoveValue); // Don't undo the last move we shuffled

		// Store the move we are about to make, then move it
		shuffLastMoveValue = blankNeighbors[neighborSwap];
		Swap(blankSpace, blankNeighbors[neighborSwap]);
	}
}

/*
	* Check to see if this board is solved
*/
bool Board::CheckSolved()
{
	// We use the same loops that we do to create the puzzle, before shuffling, to get the completed puzzle
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {

			// The inital value that this vertex would have prior to shuffling
			int value = (i * dimension) + j + 1;

			// If a value is misplaced, it is not solved
			if (myBoard[i][j] != value)
				return false;
		}
	}

	return true;
}


/*
	* Returns the dimension of the grid
*/
int Board::GetDimension()
{
	return dimension;
}

/*
	* Return the solution path that has gotten us to this point
*/
vector<int> Board::GetPath()
{
	return path;
}

/*
	* Add the move that got us here to the path
*/
void Board::AddToPath(int node)
{
	path.push_back(node);
}

/*
	* Gets the values of the neighbors for the given vertex on the board at (x,y)
*/
vector<int> Board::GetNeighbors(int x, int y)
{
	vector<int> neighbors;

	if (x > 0) {
		neighbors.push_back(myBoard[x - 1][y]);
	}

	if (x < dimension - 1) {
		neighbors.push_back(myBoard[x + 1][y]);
	}

	if (y > 0) {
		neighbors.push_back(myBoard[x][y - 1]);
	}

	if (y < dimension - 1) {
		neighbors.push_back(myBoard[x][y + 1]);
	}


	return neighbors;
}

/*
	* Will get the sum of all tiles distance from their current position and 
	* their goal position
*/
int Board::GetManhattanDistance()
{
	int distance = 0;

	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			int piece = myBoard[i][j];

			if (piece != blankSpace) {
				// Get the inital row & inital column
				int ogRow = floor((piece - 1) / dimension);
				int ogColumn = (piece - 1) % dimension;

				// Absolute value distance from original space to current
				distance += abs(i - ogRow) + abs(j - ogColumn);
			}

		}
	}

	return distance;
}

/*
	* Returns the x and y positions for the given value
*/
void Board::GetPosition(int _value, int& x, int& y) {
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			if (myBoard[i][j] == _value) {
				x = i;
				y = j;
				return;// myBoard[i][j];
			}
		}
	}
}

/*
	* Stores the last move we made
*/
void Board::SetLastMove(int _lastMovedValue)
{
	lastMovedValue = _lastMovedValue;
}

/*
	* Returns the last move we made
*/
int Board::GetLastMove()
{
	return lastMovedValue;
}

