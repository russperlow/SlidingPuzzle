#pragma once
#include "Vertex.h"

class Board
{
public:
	Board();
	Board(const Board&);
	Board(int);
	~Board();

	Vertex* GetBlankSpace(int&, int&);
	void Swap(Vertex*, Vertex*);
	void Print();
	void Shuffle();
	bool CheckSolved();
	int GetDimension();
	vector<Vertex*> GetPath();
	void AddToPath(Vertex*);
	vector<Vertex*> GetNeighbors(int, int);
	int GetManhattanDistance();
	Vertex* GetPosition(int);

	void SetLastMove(int);
	int GetLastMove();
private:
	int dimension;
	int blankSpace;
	int lastMovedValue;
	vector<vector<Vertex*>> myBoard;
	vector<Vertex*> path;
};