#pragma once

class Board
{
public:
	Board();
	Board(const Board&);
	Board(int, int);
	~Board();

	void GetBlankSpace(int&, int&);
	void Swap(int, int);
	void SwapWithBlank(int);
	void Print();
	void Shuffle(int);
	bool CheckSolved();
	int GetDimension();
	vector<int> GetPath();
	void AddToPath(int);
	vector<int> GetNeighbors(int, int);
	int GetManhattanDistance();
	void GetPosition(int, int&, int&);

	void SetLastMove(int);
	int GetLastMove();
private:
	int dimension;
	int blankSpace;
	int lastMovedValue;
	vector<vector<int>> myBoard;
	vector<int> path;
};