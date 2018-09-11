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
	* Find the vertex that contains dimension^2 on the board
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

void Puzzle::GetBlankSpace(int& x, int& y)
{
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			if (board[i][j]->GetValue() == blankSpace) {
				x = i;
				y = j;
			}
		}
	}
}

/*
	* Swap the chosen space with the blank space
*/
void Puzzle::Swap(int x1, int y1, int x2, int y2)
{
	// Swap the number value
	int tempValue = board[x1][y1]->GetValue();
	board[x1][y1]->SetValue(board[x2][y2]->GetValue());
	board[x2][y2]->SetValue(tempValue);
}

void Puzzle::Swap(Vertex* vert1, Vertex* vert2) {
	Vertex tempVert = *vert1;
	*vert1 = *vert2;
	*vert2 = tempVert;
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
	* Randomly moves around pieces to shuffle
*/
void Puzzle::Shuffle()
{
	board[0][0]->SetValue(1);
	board[0][1]->SetValue(2);
	board[0][2]->SetValue(9);
	board[1][0]->SetValue(4);
	board[1][1]->SetValue(5);
	board[1][2]->SetValue(3);
	board[2][0]->SetValue(7);
	board[2][1]->SetValue(8);
	board[2][2]->SetValue(6);


	// Shuffle by randomly swaping pieces starting from the goal form

	//srand(time(NULL));

	//int numMoves = rand() % 15 + 5; // Shuffle between 5 and 15 times

	//for (int i = 0; i <= numMoves; i++) {
	//	Vertex* blankSpace = GetBlankSpace();

	//	vector<Vertex*> blankNeighbors = GetNeighbors(blankSpace);

	//	int neighborSwap = rand() % static_cast<int>(blankNeighbors.size());
	//	Swap(blankSpace->GetX(), blankSpace->GetY(), blankNeighbors[neighborSwap]->GetX(), blankNeighbors[neighborSwap]->GetY());
	//}
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
	* Solves the puzzle using A*
*/
void Puzzle::SolveA()
{

}

/*
	* Solves the puzzle using Hill Climbing
*/
void Puzzle::SolveHill()
{

}

int Puzzle::getDimension()
{
	return dimension;
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

vector<Vertex*> Puzzle::GetNeighbors(int x, int y)
{
	vector<Vertex*> neighbors;

	if (x > 0) {
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


