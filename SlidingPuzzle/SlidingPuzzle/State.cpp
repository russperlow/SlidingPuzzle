#include "stdafx.h"
#include "State.h"


State::State(Board _board, int _distance)
{
	board = _board;
	distance = _distance;
}

State::~State()
{
}

Board State::GetBoard()
{
	return board;
}

int State::GetF()
{
	return distance;
}
