// SlidingPuzzle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Puzzle.h"

int main()
{
	Puzzle* puzzle = new Puzzle(3);

	puzzle->Print();

	cin.get();

	// Clean up our pointers
	delete puzzle;

    return 0;
}

