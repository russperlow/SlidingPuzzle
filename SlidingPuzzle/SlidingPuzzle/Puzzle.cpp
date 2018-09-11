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
			Vertex* vertex = new Vertex(value);
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
	* Store the x & y location in the board variable and return the Vertex*
*/
Vertex* Puzzle::GetBlankSpace(int& x, int& y)
{
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			if (board[i][j]->GetValue() == blankSpace) {
				x = i;
				y = j;
				return board[i][j];
			}
		}
	}
}

/*
	* Swap the two given verticies
*/
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
	bool realShuffle = true;

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

			//Swap(blankSpace->GetX(), blankSpace->GetY(), blankNeighbors[neighborSwap]->GetX(), blankNeighbors[neighborSwap]->GetY());
		}
	} else {

		board[0][0]->SetValue(1);
		board[0][1]->SetValue(2);
		board[0][2]->SetValue(9);
		board[1][0]->SetValue(4);
		board[1][1]->SetValue(5);
		board[1][2]->SetValue(3);
		board[2][0]->SetValue(7);
		board[2][1]->SetValue(8);
		board[2][2]->SetValue(6);
	}

}

/*
	* Check to see if the main puzzle is solved
*/
bool Puzzle::CheckSolved()
{
	return CheckSolved(board);
}

/*
	* Checks to see if the given board is solved
*/
bool Puzzle::CheckSolved(vector<vector<Vertex*>> _board) {
	// We use the same loops that we do to create the puzzle, before shuffling, to get the completed puzzle
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {

			// The inital value that this vertex would have prior to shuffling
			int value = (i * dimension) + j + 1;


			if (_board[i][j]->GetValue() != value)
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
	State s = State(board, 0);
	vector<State> states;

	states.push_back(s);

	while (static_cast<int>(states.size()) > 0) {
		State state = states.back();
		states.pop_back();

		vector<vector<Vertex*>> stateBoard = state.GetBoard();

		if (CheckSolved(stateBoard)) {
			// RETURN PATH
		}

		// Get children of state
		VisitState(state);


	}


}

void Puzzle::VisitState(State state)
{
	vector<vector<Vertex*>> stateBoard = state.GetBoard();

	int blankX = 0;
	int blankY = 0;
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			if (stateBoard[i][j]->GetValue() == blankSpace) {
				blankX = i;
				blankY = j;
			}
		}
	}

}

/*
	* Solves the puzzle using Hill Climbing
*/
void Puzzle::SolveHill()
{

}

/*
	* Returns the dimension of the grid
*/
int Puzzle::getDimension()
{
	return dimension;
}

/*
	* Gets the neighbors for the given vertex on the board at (x,y)
*/
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


