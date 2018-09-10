#pragma once
#include "stdafx.h"
#include "Vertex.h"

class Puzzle
{
public:
	Puzzle(int);
	~Puzzle();
	Vertex* GetBlankSpace();
	void Swap(int, int, int, int);
	void Print();
	void Shuffle();
	bool CheckSolved();
	vector<Vertex*> GetNeighbors(Vertex*);
private:
	int dimension;
	int blankSpace;
	vector<vector<Vertex*>> board;
};

