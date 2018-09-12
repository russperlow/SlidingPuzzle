// SlidingPuzzle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Puzzle.h"
#include "Vertex.h"
#include "Board.h"

int main()
{
	Board* board = new Board(3);


	while (!board->CheckSolved()) {
		system("CLS"); // clear the screen before we draw the puzzle

		board->Print();

		/*cout << "Press [M] to Move, [S] to Shuffle and [F] to have the puzzle solved." << endl;

		char charInput;
		cin >> charInput;*/

		Puzzle puzzle = Puzzle();
		vector<Vertex*> path = puzzle.SolveA(*board);

		while (static_cast<int>(path.size()) > 0) {
			Vertex* vert = path.front();
			path.erase(path.begin());

			int x = 0;
			int y = 0;
			board->Swap(vert, board->GetBlankSpace(x, y));

			int numInput;
			cin >> numInput;
		}


		//cout << "Which number would you like to move?" << endl;

		//int blankX;
		//int blankY;

		//Vertex* blankSpace = board->GetBlankSpace(blankX, blankY);
		//vector<Vertex*> neighbors = board->GetNeighbors(blankX, blankY);

		//int numInput;
		//cin >> numInput;

		//Vertex* correctVector = nullptr;

		//// Loop through the given neighbors to make sure a valid move was made
		//for (const auto& v : neighbors) {
		//	if (v->GetValue() == numInput) {
		//		correctVector = v;
		//	}
		//}

		//if (correctVector != nullptr) {
		//	board->Swap(blankSpace, correctVector);
		//}
		//else {
		//	cout << "That was an invalid move!" << endl;
		//	cin.get();
		//}
	}

	cout << "Congratulations! You solved the puzzle!" << endl;
	cin.get();

	// Clean up our pointers
	delete board;

    return 0;
}

