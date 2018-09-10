// SlidingPuzzle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Puzzle.h"
#include "Vertex.h"

int main()
{
	Puzzle* puzzle = new Puzzle(3);


	while (!puzzle->CheckSolved()) {
		system("CLS"); // clear the screen before we draw the puzzle

		puzzle->Print();

		cout << "Which number would you like to move?" << endl;

		Vertex* blankSpace = puzzle->GetBlankSpace();
		vector<Vertex*> neighbors = puzzle->GetNeighbors(blankSpace);

		int input;
		cin >> input;

		Vertex* correctVector = nullptr;

		for (const auto& v : neighbors) {
			if (v->GetValue() == input) {
				correctVector = v;
			}
		}

		puzzle->Swap(blankSpace->GetX(), blankSpace->GetY(), correctVector->GetX(), correctVector->GetY());
	}


	cin.get();

	// Clean up our pointers
	delete puzzle;

    return 0;
}

