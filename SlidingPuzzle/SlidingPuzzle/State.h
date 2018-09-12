#pragma once
#include "stdafx.h"
#include "Vertex.h"
#include "Board.h"

class State
{
public:
	State(Board, int);
	~State();
	Board GetBoard();
	int GetF();
private:
	Board board;
	int distance;
};

