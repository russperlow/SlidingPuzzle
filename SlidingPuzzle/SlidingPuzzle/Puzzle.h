#pragma once
#include "stdafx.h"
#include "Vertex.h"

class Puzzle
{
public:
	Puzzle(int);
	~Puzzle();
	Vertex* GetBlankSpace(int&, int&);
	void Swap(Vertex*, Vertex*);
	void Print();
	void Shuffle();
	bool CheckSolved();
	void SolveA();
	void SolveHill();
	int getDimension();
	vector<Vertex*> GetNeighbors(int, int);
private:
	int dimension;
	int blankSpace;
	vector<vector<Vertex*>> board;
};

