#include "stdafx.h"
#include "State.h"


State::State(vector<vector<Vertex*>> _board, int _distance)
{
	int dimension = static_cast<int>(_board.size());
	board.resize(dimension);

	for (int i = 0; i < dimension; i++) {
		board[i].resize(dimension);
		for (int j = 0; j < dimension; j++) {
			*_board[i][j] = *board[i][j]; // Copy vertex by value
		}
	}

	distance = _distance;
}


State::~State()
{
}

vector<vector<Vertex*>> State::GetBoard()
{
	return board;
}
