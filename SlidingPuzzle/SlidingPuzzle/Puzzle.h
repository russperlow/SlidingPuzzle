#pragma once
#include "stdafx.h"
#include "State.h"
#include "Board.h"

class Puzzle
{
public:
	Puzzle();
	~Puzzle();
	
	vector<int> SolveA(Board);
	vector<Board> VisitState(State*);

	void SolveHill(Board*, int);
	int HillMoves(Board, int, int);
private:
	int dimension;
	Board myBoard;
	vector<State*> states;
	vector<State*> removedStates;
};

