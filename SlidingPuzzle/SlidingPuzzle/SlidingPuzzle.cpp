// SlidingPuzzle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Puzzle.h"
#include "Vertex.h"
#include "Board.h"
#include <Windows.h>

#undef max()

int main()
{
	Board* board = new Board(4);

	int sleepTime = 500;
	int intInput;
	char solveInput;

	while (!board->CheckSolved()) {
		system("CLS"); // clear the screen before we draw the puzzle

		board->Print();

		cout << "Enter the number you'd like to move or 0 to choose a solution algorithm" << endl;

		cin >> intInput;

		if (cin.fail()) {
			cout << "That was invalid input!" << endl;
			system("PAUSE");
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		if (intInput == 0) {

			cout << "Would you like to solve using [A]Star or [H]ill Climbing?" << endl;
			cin >> solveInput;

			if (toupper(solveInput) == 'A') {
				// ASTAR SOLUTION
				Puzzle puzzle = Puzzle();
				vector<Vertex*> path = puzzle.SolveA(*board);

				while (static_cast<int>(path.size()) > 0) {
					Vertex* vert = board->GetPosition(path.front()->GetValue());
					path.erase(path.begin());

					int x = 0;
					int y = 0;
					board->Swap(vert, board->GetBlankSpace(x, y));

					//system("PAUSE");
					Sleep(sleepTime);
					system("CLS");
					board->Print();
				}
			}
			else if(toupper(solveInput) == 'H'){

				while (!board->CheckSolved()) {
					// HILL CLIMBING SOLUTION
					Puzzle puzzle = Puzzle();
					puzzle.SolveHill(board, 20);

					Sleep(sleepTime);
					system("CLS");
					board->Print();
				}
			}
		}
		else {
			// MANUAL SOLUTION
			int blankX;
			int blankY;

			Vertex* blankSpace = board->GetBlankSpace(blankX, blankY);
			vector<Vertex*> neighbors = board->GetNeighbors(blankX, blankY);

			int numInput = intInput;
			//cin >> numInput;

			Vertex* correctVector = nullptr;

			// Loop through the given neighbors to make sure a valid move was made
			for (const auto& v : neighbors) {
				if (v->GetValue() == numInput) {
					correctVector = v;
				}
			}

			if (correctVector != nullptr) {
				board->Swap(blankSpace, correctVector);
			}
			else {
				cout << "That was an invalid move!" << endl;
				system("PAUSE");
			}
		}
	}

	cout << "Congratulations! You solved the puzzle!" << endl;
	system("PAUSE");

	// Clean up our pointers
	delete board;

    return 0;
}

