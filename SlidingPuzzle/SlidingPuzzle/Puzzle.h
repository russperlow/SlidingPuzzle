#pragma once
#include "stdafx.h"
#include "Vertex.h"
#include "State.h"
#include "Board.h"

class Puzzle
{
public:
	Puzzle();
	~Puzzle();
	
	vector<Vertex*> SolveA(Board);
	vector<Board*> VisitState(State*);

	void SolveHill(Board*, int);
	int HillMoves(Board, int, int);
private:
	int dimension;
	int blankSpace;
	Board myBoard;
};

