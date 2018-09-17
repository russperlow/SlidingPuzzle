// SlidingPuzzle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Puzzle.h"
#include "Board.h"
#include <Windows.h>

#undef max()

int main()
{
	int dimension = 4;
	int blankSpaceValue = dimension * dimension;
	Board* board = new Board(dimension);
	Puzzle* puzzle = new Puzzle();
	int sleepTime = 500;

	while (!board->CheckSolved()) {
		system("CLS"); // clear the screen before we draw the puzzle

		board->Print();

		cout << "Enter the number you'd like to move or 0 to choose a solution algorithm" << endl;

		int intInput = 0;
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
			char solveInput = 'H';
			cin >> solveInput;

			if (toupper(solveInput) == 'A') {
				// ASTAR SOLUTION
				vector<int> path = puzzle->SolveA(*board);

				while (static_cast<int>(path.size()) > 0) {
					int x1 = 0;
					int y1 = 0;
					int move = path.front();
					board->GetPosition(move, x1, y1);
					path.erase(path.begin());

					int x = 0;
					int y = 0;
					board->Swap(move, blankSpaceValue);

					//system("PAUSE");
					Sleep(sleepTime);
					system("CLS");
					board->Print();
				}
			}
			else if(toupper(solveInput) == 'H'){

				while (!board->CheckSolved()) {
					// HILL CLIMBING SOLUTION
					puzzle->SolveHill(board, 20);

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

			board->GetBlankSpace(blankX, blankY);
			vector<int> neighbors = board->GetNeighbors(blankX, blankY);

			int numInput = intInput;
			//cin >> numInput;

			int correctNumber = -1;

			// Loop through the given neighbors to make sure a valid move was made
			for (const auto& v : neighbors) {
				if (v == numInput) {
					correctNumber = v;
				}
			}

			if (correctNumber != -1) {
				board->Swap(blankSpaceValue, correctNumber);
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
	delete puzzle;

	_CrtDumpMemoryLeaks();

    return 0;
}

