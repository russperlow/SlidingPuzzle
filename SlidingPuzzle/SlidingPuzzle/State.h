#pragma once
#include "stdafx.h"
#include "Vertex.h"

class State
{
public:
	State(vector<vector<Vertex*>>, int);
	~State();
	vector<vector<Vertex*>> GetBoard();
private:
	vector<vector<Vertex*>> board;
	int distance;
};

