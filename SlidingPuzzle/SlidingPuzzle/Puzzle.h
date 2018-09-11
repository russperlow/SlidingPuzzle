#pragma once
#include "stdafx.h"
#include "Vertex.h"
#include "State.h"

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
	bool CheckSolved(vector<vector<Vertex*>>);
	void SolveA();
	void VisitState(State);
	void SolveHill();
	int getDimension();
	vector<Vertex*> GetNeighbors(int, int);
private:
	int dimension;
	int blankSpace;
	vector<vector<Vertex*>> board;
};

