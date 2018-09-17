#include "stdafx.h"
#include "Puzzle.h"


Puzzle::Puzzle()
{
}


Puzzle::~Puzzle()
{
	while (static_cast<int>(removedStates.size()) > 0) {
		State* state = removedStates.front();
		removedStates.erase(removedStates.begin());
		delete state;
	}

	while (static_cast<int>(states.size()) > 0) {
		State* state = states.front();
		states.erase(states.begin());
		delete state;
	}
}

/*
	* Solves the puzzle using A*
*/
vector<int> Puzzle::SolveA(Board _myBoard)
{
	myBoard = _myBoard;
	int dimension = myBoard.GetDimension();
	blankSpace = dimension * dimension;

	// Put current puzzle in "states" collection
	State* s = new State(myBoard, 0);

	states.push_back(s);

	// Loop through states until empty
	while (static_cast<int>(states.size()) > 0) {

		int best = 0;

		// Find the lowest distance of all states stored
		for (int i = 0; i < static_cast<int>(states.size()); i++) {
			if (states[i]->GetF() < states[best]->GetF()) {
				best = i;
			}
		}


		State* state = states[best];
		states.erase(states.begin() + best);
		removedStates.push_back(state);

		Board stateBoard = state->GetBoard();

		// If solved we are done
		if (stateBoard.CheckSolved()) {
			return stateBoard.GetPath();
		}

		// Get children of state
		vector<Board> children = VisitState(state);

		// Loop through all children to calculate their respective F's
		for (auto& child : children) {
			int f = static_cast<int>(child.GetPath().size()) + child.GetManhattanDistance();
			states.push_back(new State(child, f));
		}
	}


}

/*
	* "Visit" the given state to get its next move
*/
vector<Board> Puzzle::VisitState(State* state)
{
	vector<Board> children;

	Board stateBoard = state->GetBoard();

	// Get this boards blank space
	int blankX = 0;
	int blankY = 0;
	stateBoard.GetBlankSpace(blankX, blankY);

	// Get all possible moves (neighbors to blank space)
	vector<int> neighbors = stateBoard.GetNeighbors(blankX, blankY);

	// Loop through neighbors
	for (int i = 0; i < static_cast<int>(neighbors.size()); i++) {

		// Don't undo the last move
		if (neighbors[i] != stateBoard.GetLastMove()) {
			
			Board newBoard(stateBoard);

			int oldValue = neighbors[i];

			newBoard.AddToPath(oldValue); // Add neighbor to path
			newBoard.Swap(neighbors[i], blankSpace); // Swap neighbor and blank space
			newBoard.SetLastMove(oldValue); // Store the last move
			children.push_back(newBoard); // Add the board to children vector
		}
	}
	return children;
}

/*
	* Solves the puzzle using Hill Climbing
*/
void Puzzle::SolveHill(Board* _myBoard, int depth)
{
	// Loop over all possible move for the current board
	/*myBoard = *_myBoard;
	int x = 0;
	int y = 0;
	int valueToMove = HillMoves(myBoard, depth, depth);
	_myBoard->SetLastMove(valueToMove);
	_myBoard->Swap(_myBoard->GetPosition(valueToMove), _myBoard->GetBlankSpace(x, y));*/
}

/*
	* Loops through all possible moves for current board
	* Returns dF
*/
int Puzzle::HillMoves(Board _myBoard, int depth, int currLevel) {
	return-0;
	//// Return 0 if we have reached the depth
	//if (currLevel == 0)
	//	return 0;

	//// Store this given board
	//Board thisBoard = _myBoard;

	//// Get the blankspace for thisBoard
	//int blankX = 0;
	//int blankY = 0;
	//Vertex* blankVert = thisBoard.GetBlankSpace(blankX, blankY);

	//// Get all possible moves for this state
	//vector<Vertex*> neighbors = thisBoard.GetNeighbors(blankX, blankY);

	//int lowestMove = INT16_MAX; // Lowest dF of all neighbors of given depth
	//int vectorPosition = 0;

	//// Loop through all neighbors
	//for (int i = 0; i < static_cast<int>(neighbors.size()); i++) {

	//	// Don't undo the last move, it's a waste
	//	if (neighbors[i]->GetValue() != thisBoard.GetLastMove()) {

	//		int dF = 0;

	//		// Copy board & make move
	//		Board newBoard = (thisBoard);

	//		Vertex* swapVert = newBoard.GetPosition(neighbors[i]->GetValue());
	//		Vertex* oldBlankVert = newBoard.GetBlankSpace(blankX, blankY);

	//		newBoard.Swap(swapVert, oldBlankVert); // Swap neighbor and blank space
	//		newBoard.SetLastMove(swapVert->GetValue()); // Store the last move

	//		if(depth != currLevel)
	//			return thisBoard.GetManhattanDistance() + HillMoves(newBoard, depth, currLevel-1);
	//		else {
	//			dF = thisBoard.GetManhattanDistance() + HillMoves(newBoard, depth, currLevel - 1);

	//			// If we found a new lowest move, store it and the position of this vector in neighbors
	//			if (dF < lowestMove) {
	//				lowestMove = dF;
	//				vectorPosition = i;
	//			}
	//		}
	//	}
	//}
	//return neighbors[vectorPosition]->GetValue();
}

