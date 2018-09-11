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

		/*cout << "Press [M] to Move, [S] to Shuffle and [F] to have the puzzle solved." << endl;

		char charInput;
		cin >> charInput;*/

		cout << "Which number would you like to move?" << endl;

		Vertex* blankSpace = puzzle->GetBlankSpace();
		vector<Vertex*> neighbors = puzzle->GetNeighbors(blankSpace);

		int numInput;
		cin >> numInput;

		Vertex* correctVector = nullptr;

		// Loop through the given neighbors to make sure a valid move was made
		for (const auto& v : neighbors) {
			if (v->GetValue() == numInput) {
				correctVector = v;
			}
		}

		if (correctVector != nullptr) {
			puzzle->Swap(blankSpace->GetX(), blankSpace->GetY(), correctVector->GetX(), correctVector->GetY());
		}
		else {
			cout << "That was an invalid move!" << endl;
			cin.get();
		}
	}

	cout << "Congratulations! You solved the puzzle!" << endl;
	cin.get();

	// Clean up our pointers
	delete puzzle;

    return 0;
}

