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
	board[0][0]->SetValue(1);
	board[0][1]->SetValue(2);
	board[0][2]->SetValue(9);
	board[1][0]->SetValue(4);
	board[1][1]->SetValue(5);
	board[1][2]->SetValue(3);
	board[2][0]->SetValue(7);
	board[2][1]->SetValue(8);
	board[2][2]->SetValue(6);

	//srand(time(NULL));

	//for (int i = 0; i < dimension; i++) {
	//	for (int j = 0; j < dimension; j++) {

	//		// Randomly get an x and y to choose a vert
	//		int randX = rand() % dimension;
	//		int randY = rand() % dimension;

	//		Vertex* thisVert = board[i][j];
	//		Vertex* swapVert = board[randX][randY];

	//		// Swap the values of this vert and the random vert
	//		int thisValue = thisVert->GetValue();
	//		thisVert->SetValue(swapVert->GetValue());
	//		swapVert->SetValue(thisValue);
	//	}
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
	vector<vector<Vertex>> copyOfPuzzle;

	copyOfPuzzle.resize(dimension);

	// Get a copy of the puzzle to use
	for (int i = 0; i < dimension; i++) {
		copyOfPuzzle[i].resize(dimension);
		for (int j = 0; j < dimension; j++) {
			copyOfPuzzle[i][j] = *board[i][j];
		}
	}


	int depth = 5;
	int minX = INT16_MAX;
	int minY = INT16_MAX;
	Vertex blankSpaceVert;
	vector<Vertex*> neighbors;

	
	for (int i = 0; i < depth; i++) {

		// Loop through to find the blank space then its neighbors
		for (int j = 0; j < dimension; j++) {
			for (int k = 0; k < dimension; k++) {
				if (copyOfPuzzle[i][j].GetValue() == blankSpace) {
					blankSpaceVert = copyOfPuzzle[i][j];
					neighbors = GetNeighbors(&blankSpaceVert);
					break;
				}
			}
		}

		for (const auto& v : neighbors) {
			
		}

	}




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

bool Puzzle::CheckClosedList(Vertex& vertex)
{
	for (int i = 0; i < static_cast<int>(closedSet.size()); i++) {
		if (&vertex == closedSet[i]) {
			return true;
		}
	}
	return false;

}

bool Puzzle::CheckOpenList(Vertex& vertex)
{

	for (int i = 0; i < static_cast<int>(openSet.size()); i++) {
		if (&vertex == openSet[i]) {
			return true;
		}
	}
	return false;
}

