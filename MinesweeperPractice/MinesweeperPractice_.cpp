// MinesweeperPractice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>      // std::setprecision
#include <vector>
#include <time.h>       /* time */
#include "Board.h"

bool inRange(int val, int start, int end);
int getInteger(const char * prompt, int start, int  end);

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

	//---Implementation-------------------//

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
		system("cls"); //clear console

		// Display Board
		//board.displayMines(); //Testing
		std::cout << std::endl;

		board.display();

		// Get Input

		// --- Prompt: Place Flag? [y/n]? --------------------------//
		//y -> Select Row and Col 
		//n -> Continue
		char input1;
		do
		{
			std::cout << "Place Flag ? [y/n]" << std::endl;
			std::cin >> input1;
		} while (!std::cin.fail() && input1 != 'y' && input1 != 'n');

		if (input1 == 'y')
		{
			//Enter Row and Col of Space to place a Flag
			std::cout << "Select space to clear. " << std::endl;

			row = getInteger("Enter the row", 0, board_size);
			col = getInteger("Enter the column", 0, board_size);

			//Extra Line for spacing
			std::cout << std::endl;


			// --- Process Input ------------------------------//

			board.flag(row, col);
		}

		// --- Prompt: Clear space? [y/n] ------------------------------//

		//y -> Select Row and Col 
		//n -> Continue
		char input2;
		do
		{
			std::cout << "Clear space? [y/n]" << std::endl;
			std::cin >> input2;
		} while (!std::cin.fail() && input2 != 'y' && input2 != 'n');

		if (input2 == 'y')
		{
			//Enter Row and Col of Space to Clear
			std::cout << "Select space to clear. " << std::endl;

			row = getInteger("Enter the row" , 0, board_size);
			col = getInteger("Enter the column", 0, board_size);

			//Extra Line for spacing
			std::cout << std::endl;


			// --- Process Input ------------------------------//

			//If theres a mine at (row, col)
			if (board.check(row, col))
			{
				//DEBUG 
				std::cout << "Mine Exploded!! :(" << std::endl;
				std::cout << "GAME OVER!" << std::endl;

				//Try Again? y/n
				//Yes	-> return to start
				//No	-> Close Program
				playing = false;
			}
			else
			{
				// DEBUG 
				// std::cout << "Empty Space" << std::endl;
				board.clearArea(row, col);
			}
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

int getInteger(const char * prompt, int start, int  end)
{
	int value = 0;
	bool gettingRow = true;
	while (gettingRow)
	{
		std::cout << prompt << std::endl;
		std::cin >> value;
		if (inRange(value, start, end))
		{
			gettingRow = false;
		}
	}
	return value;
}
