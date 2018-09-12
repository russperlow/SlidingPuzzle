#include "stdafx.h"
#include "Board.h"
#include <stdio.h>
#include <math.h>

Board::Board() {

}

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
			int value = _board.myBoard[i][j]->GetValue();
			myBoard[i][j] = new Vertex(value);// = *_board.myBoard[i][j];
		}
	}

}

Board::Board(int _dimension)
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
			Vertex* vertex = new Vertex(value);
			myBoard[i][j] = vertex;
		}
	}

	Shuffle();
}

Board::~Board()
{
}

/*
* Find the vertex that contains dimension^2 on the board
* Store the x & y location in the board variable and return the Vertex*
*/
Vertex* Board::GetBlankSpace(int& x, int& y)
{
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			if (myBoard[i][j]->GetValue() == blankSpace) {
				x = i;
				y = j;
				return myBoard[i][j];
			}
		}
	}
}

/*
* Swap the two given verticies
*/
void Board::Swap(Vertex* vert1, Vertex* vert2) {
	Vertex tempVert = *vert1;
	*vert1 = *vert2;
	*vert2 = tempVert;
}

/*
* Prints out the current puzle
*/
void Board::Print() {
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			if (myBoard[i][j]->GetValue() == blankSpace)
				cout << " |";
			else
				cout << myBoard[i][j]->GetValue() << "|";
		}
		cout << endl;
	}
}

/*
* Randomly moves around pieces to shuffle
*/
void Board::Shuffle()
{
	bool realShuffle = false;

	if (realShuffle) {
		// Shuffle by randomly swaping pieces starting from the goal form
		srand(time(NULL));

		int numMoves = (rand() % 15) + 10; // Shuffle between 10 and 20 times

		for (int i = 0; i <= numMoves; i++) {

			// ****************************THIS WILL NEED TO BE CHANGED IN THE FUTURE*****************************
			int blankX = 0;
			int blankY = 0;
			Vertex* blankSpace = GetBlankSpace(blankX, blankY);

			vector<Vertex*> blankNeighbors = GetNeighbors(blankX, blankY);

			int neighborSwap = rand() % static_cast<int>(blankNeighbors.size());
			Swap(blankSpace, blankNeighbors[neighborSwap]);

		}
	}
	else {

		myBoard[0][0]->SetValue(1);
		myBoard[0][1]->SetValue(2);
		myBoard[0][2]->SetValue(3);
		myBoard[1][0]->SetValue(4);
		myBoard[1][1]->SetValue(5);
		myBoard[1][2]->SetValue(6);
		myBoard[2][0]->SetValue(7);
		myBoard[2][1]->SetValue(9);
		myBoard[2][2]->SetValue(8);
	}

}

/*
* Check to see if the main puzzle is solved
*/
bool Board::CheckSolved()
{
	// We use the same loops that we do to create the puzzle, before shuffling, to get the completed puzzle
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {

			// The inital value that this vertex would have prior to shuffling
			int value = (i * dimension) + j + 1;


			if (myBoard[i][j]->GetValue() != value)
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

vector<Vertex*> Board::GetPath()
{
	return path;
}

void Board::AddToPath(Vertex* node)
{
	path.push_back(node);
}

/*
* Gets the neighbors for the given vertex on the board at (x,y)
*/
vector<Vertex*> Board::GetNeighbors(int x, int y)
{
	vector<Vertex*> neighbors;

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

int Board::GetManhattanDistance()
{
	int distance = 0;

	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			Vertex* piece = myBoard[i][j];

			if (piece->GetValue() != blankSpace) {
				// Get the inital row & inital column
				int ogRow = floor((piece->GetValue() - 1) / dimension);
				int ogColumn = (piece->GetValue() - 1) % dimension;

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
Vertex* Board::GetPosition(int _value) {
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			if (myBoard[i][j]->GetValue() == _value) {
				return myBoard[i][j];
			}
		}
	}
}

void Board::SetLastMove(int _lastMovedValue)
{
	lastMovedValue = _lastMovedValue;
}

int Board::GetLastMove()
{
	return lastMovedValue;
}

