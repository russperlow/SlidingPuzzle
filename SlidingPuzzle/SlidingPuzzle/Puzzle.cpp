#include "stdafx.h"
#include "Puzzle.h"


Puzzle::Puzzle()
{
}


Puzzle::~Puzzle()
{
}

/*
	* Solves the puzzle using A*
*/
vector<Vertex*> Puzzle::SolveA(Board _myBoard)
{
	myBoard = _myBoard;

	// Put current puzzle in "states" collection
	State s = State(myBoard, 0);
	vector<State> states;

	states.push_back(s);

	// Loop through states until empty
	while (static_cast<int>(states.size()) > 0) {

		int best = 0;

		// Find the lowest distance of all states stored
		for (int i = 0; i < static_cast<int>(states.size()); i++) {
			if (states[i].GetF() < states[best].GetF()) {
				best = i;
			}
		}


		State state = states[best];
		states.erase(states.begin() + best);

		Board stateBoard = state.GetBoard();

		// If solved we are done
		if (stateBoard.CheckSolved()) {
			return stateBoard.GetPath();
		}

		// Get children of state
		vector<Board> children = VisitState(state);

		// Loop through all children to calculate their respective F's
		for (auto& child : children) {
			int f = static_cast<int>(child.GetPath().size()) + child.GetManhattanDistance();
			states.push_back(State(child, f));
		}

	}


}

/*
	* "Visit" the given state to get its next move
*/
vector<Board> Puzzle::VisitState(State state)
{
	vector<Board> children;

	Board stateBoard = state.GetBoard();

	// Get this boards blank space
	int blankX = 0;
	int blankY = 0;
	Vertex* blankSpace = stateBoard.GetBlankSpace(blankX, blankY);

	// Get all possible moves (neighbors to blank space)
	vector<Vertex*> neighbors = stateBoard.GetNeighbors(blankX, blankY);

	// Loop through neighbors
	for (int i = 0; i < static_cast<int>(neighbors.size()); i++) {

		// Don't undo the last move
		if (neighbors[i]->GetValue() != stateBoard.GetLastMove()) {
			
			Board newBoard(stateBoard);
			
			Vertex* swapVert = newBoard.GetPosition(neighbors[i]->GetValue());
			Vertex* oldBlankVert = newBoard.GetBlankSpace(blankX, blankY);

			newBoard.Swap(swapVert, oldBlankVert); // Swap neighbor and blank space
			newBoard.AddToPath(oldBlankVert); // Add neighbor to path
			newBoard.SetLastMove(swapVert->GetValue()); // Store the last move
			children.push_back(newBoard); // Add the board to children vector
		}
	}
	return children;
}

/*
	* Solves the puzzle using Hill Climbing
*/
void Puzzle::SolveHill()
{

}


