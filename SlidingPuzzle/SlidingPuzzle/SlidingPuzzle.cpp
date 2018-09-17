// SlidingPuzzle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Puzzle.h"
#include "Board.h"
#include <Windows.h>

#undef max()

int main()
{

	// Ask the user for input on dimension size
	int dimension = 4;
	cout << "Welcome to Russ' Sliding Puzzle!" << endl;
	cout << "What size dimension would you like to play on? (Minimum number is 2)" << endl;
	cin >> dimension;

	// Make sure the input is an int and is at least 2
	while (cin.fail() || dimension < 2) {
		cout << "That was invalid input! Please try again!" << endl;
		system("PAUSE");
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> dimension;
	}

	// Ask the user if they want a random shuffle number, or specific one
	int shuffleNum = 0;
	cout << "How many times would you like the board shuffled? Enter 0 for a random number of shuffles." << endl;
	cin >> shuffleNum;

	// Make sure the input is an int and is at least 2
	while (cin.fail() || dimension < 0) {
		cout << "That was invalid input! Please try again!" << endl;
		system("PAUSE");
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> shuffleNum;
	}

	int blankSpaceValue = dimension * dimension; // Our blank space will be whatever the bottom right value would be

	Board* board = new Board(dimension, shuffleNum);
	Puzzle* puzzle = new Puzzle();

	// How long we will sleep for when solving
	int sleepTime = 500;

	// Clear the screen and draw the board to start
	system("CLS");
	board->Print();

	// Game loop
	while (!board->CheckSolved()) {

		// 0 - Choose a solving algorithim, Other - Attempt to move that piece
		cout << "Enter the number you'd like to move or 0 to choose a solution algorithm" << endl;

		int intInput = 0;
		cin >> intInput;


		// If the input was not an int, tell them it was an invalid move and skip the rest of the loop
		if (cin.fail()) {
			cout << "That was invalid input!" << endl;
			system("PAUSE");
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		if (intInput == 0) {

			// Prompt user to choose a solving algorithm 
			cout << "Would you like to solve using [A]* or [H]ill Climbing?" << endl;
			char solveInput = 'H';
			cin >> solveInput;

			if (toupper(solveInput) == 'A') {
				// ASTAR SOLUTION
				vector<int> path = puzzle->SolveA(*board);

				while (static_cast<int>(path.size()) > 0) {

					// Get the next move in the path and make it
					int x1 = 0;
					int y1 = 0;
					int move = path.front();
					board->GetPosition(move, x1, y1);
					path.erase(path.begin());
					board->Swap(move, blankSpaceValue);

					Sleep(sleepTime);
					system("CLS");
					cout << "SOLVING USING A*" << endl;
					board->Print();
				}
			}
			else if(toupper(solveInput) == 'H'){

				// Prompt the user for the depth they'd like to use
				int depth = 5;
				cout << "What depth would you like to use for Hill Climbing?" << endl;
				cin >> depth;

				// Make sure that the input is an int and is positive
				while (cin.fail() || depth < 1) {
					cout << "That was invalid input! Please try again!" << endl;
					system("PAUSE");
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cin >> depth;
				}

				while (!board->CheckSolved()) {
					// HILL CLIMBING SOLUTION
					puzzle->SolveHill(board, depth);

					Sleep(sleepTime);
					system("CLS");
					cout << "SOLVING USING HILL CLIMBING WITH DEPTH " << depth << endl;
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
			int correctNumber = -1;

			// Loop through the given neighbors to make sure a valid move was made
			for (const auto& v : neighbors) {
				if (v == numInput) {
					correctNumber = v;
				}
			}

			if (correctNumber != -1) {
				board->Swap(blankSpaceValue, correctNumber);

				// Redraw the puzzle with the new changes
				system("CLS");
				board->Print();
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

	// Check for memory leaks
	_CrtDumpMemoryLeaks();

    return 0;
}

