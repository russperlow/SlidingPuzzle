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
	void Swap(Vertex*, Vertex*);
	void Print();
	void Shuffle();
	bool CheckSolved();
	void SolveA();
	void SolveHill();
	int getDimension();
	vector<Vertex*> GetNeighbors(Vertex*);
	vector<Vertex*> GetNeighbors(int, int);
private:
	int dimension;
	int blankSpace;
	vector<vector<Vertex*>> board;
};

