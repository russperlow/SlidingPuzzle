#pragma once
#include "stdafx.h"
#include "Vertex.h"

class Puzzle
{
public:
	Puzzle(int);
	~Puzzle();
	Vertex* GetBlankSpace();
	void Swap();
	void Print();
private:
	int dimension;
	vector<vector<Vertex*>> board;
};

