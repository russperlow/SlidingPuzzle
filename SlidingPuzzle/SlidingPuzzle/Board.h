#pragma once
#include "Vertex.h"

class Board
{
public:
	Board();
	Board(const Board&);
	Board(int);
	~Board();

	//Vertex* GetBlankSpace(int&, int&);
	void GetBlankSpace(int&, int&);
	//void Swap(Vertex*, Vertex*);
	void Swap(int, int);
	void Print();
	void Shuffle();
	bool CheckSolved();
	int GetDimension();
	//vector<Vertex*> GetPath();
	vector<int> GetPath();
	void AddToPath(int);
	//vector<Vertex*> GetNeighbors(int, int);
	vector<int> GetNeighbors(int, int);
	int GetManhattanDistance();
	//Vertex* GetPosition(int);
	void GetPosition(int, int&, int&);

	void SetLastMove(int);
	int GetLastMove();
private:
	int dimension;
	int blankSpace;
	int lastMovedValue;
	//vector<vector<Vertex*>> myBoard;
	//vector<Vertex*> path;
	vector<vector<int>> myBoard;
	vector<int> path;
};