// MinesweeperPractice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>      // std::setprecision
#include <vector>
#include <time.h>       /* time */
#include "Board.h"

bool inRange(int val, int start, int end);



int main()
{
	//---Program Outline---//

	// Data Structures

	// Program Loop

	// Input Board Size

	// Input Fill Percent

	// Generate Board

	// Game Loop

		// Display Board
		// Get Input 
		// Process Input

	//----------------------//

	//Vars and Data Structures
	int board_size = 0;
	double input_fill = 0.0;
	bool playing = true;
	Board board;

	// Program Loop

	// Input Board Size
	std::cout << "Enter Board Size" << std::endl;
	std::cin >> board_size;

	//Initialize Board
	board.initializeSize(board_size);

	// Input Fill Percent
	std::cout << "Enter fill percent (0.0 to 1)" << std::endl;
	std::cin >> input_fill;

	// Fill Board
	board.fill(input_fill);

	// Test Output 
	//std::cout << "board_size = " << board_size << std::endl;
	//std::cout << "input_fill = " << input_fill << std::endl;
	//board.displayMines();
	//board.display();
	//system("pause");

	// Game Loop
	int row = 0;
	int col = 0;
	while (playing)
	{
		system("cls");

		// Display Board
		board.displayMines();
		std::cout << std::endl;

		board.display();

		// Get Input // TODO

		// Place Flag? Y/N?

			//Select Row and Col 
			//Go back to loop start

		//Enter Row and Col of Space to Check

		bool gettingRow = true;
		while (gettingRow)
		{
			std::cout << "Enter the row" << std::endl;
			std::cin >> row;
			if (inRange(row, 0, board_size))
			{
				gettingRow = false;
			}
		}

		bool gettingCol = true;
		while (gettingCol)
		{
			std::cout << "Enter the column" << std::endl;
			std::cin >> col;

			if (inRange(col, 0, board_size))
			{
				gettingCol = false;
			}
		}

		//Extra Line for spacing
		std::cout << std::endl;


		// Process Input // Check for Valid Range

		//DEBUG
		//display_board[row][col] = 1;


		//If theres a mine at (row, col)
		if (board.check(row, col) )
		{
			//DEBUG 
			std::cout << "Mine Exploded!! :(" << std::endl;
			//Try Again? y/n
			//Yes	-> return to start
			//No	-> Close Program
		}
		else
		{
			// DEBUG 
			// std::cout << "Empty Space" << std::endl;
			board.clearArea(row, col);
		}

		//DEBUG
		system("pause");
	}

    return 0;
}

bool inRange(int val, int start, int end)
{
	//check x and y boundaries // < 0 or > board.size
	if (val < start || val >= end)
	{
		return false;
	}
	return true;
}