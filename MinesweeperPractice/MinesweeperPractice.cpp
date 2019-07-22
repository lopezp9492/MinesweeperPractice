// MinesweeperPractice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>      // std::setprecision
#include <vector>
#include <time.h>       /* time */




void initializeBoard(int boardSize, std::vector<std::vector<bool> > &board);
void initializeDisplayBoard(int board_size, std::vector<std::vector<int> > &display_board);

void fillBoard(int board_size, double fillPercent, std::vector<std::vector<bool> > &board);

void displayMines(std::vector<std::vector<bool> > &board);
void displayBoard(std::vector<std::vector<int> > &board);

void displayHeader(int size);




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
	std::vector<std::vector<bool> > board;			// Board containing the locations of the mines
	std::vector<std::vector<int> > display_board;	// Board shown to the Players
	bool playing = true;

	// Program Loop

	// Input Board Size
	std::cout << "Enter Board Size" << std::endl;
	std::cin >> board_size;

	//Initialize Board
	initializeBoard(board_size, board);
	initializeDisplayBoard(board_size, display_board);

	// Input Fill Percent
	std::cout << "Enter fill percent (0.0 to 1)" << std::endl;
	std::cin >> input_fill;

	// Fill Board
	fillBoard(board_size, input_fill, board);

	//Test Output 
	std::cout << "board_size = " << board_size << std::endl;
	std::cout << "input_fill = " << input_fill << std::endl;
	displayMines(board);
	displayBoard(display_board);


	
	// Game Loop
	int row = 0;
	int col = 0;
	while (playing)
	{
		system("cls");

		// Display Board
		displayBoard(display_board);

		// Get Input 
		std::cout << "Enter the row" << std::endl;
		std::cin >> row;

		std::cout << "Enter the column" << std::endl;
		std::cin >> row;

		std::cout << std::endl;


		// Process Input
	}

		

    return 0;
}

// Creates a 2d Vector of booleans filled with false 
void initializeBoard(int boardSize, std::vector<std::vector<bool> > &board)
{
	//Row Contents
	std::vector<bool> row(boardSize, false);

	//Each row is a copy of the first
	for (int i = 0; i < boardSize; i++)
	{
		board.push_back(row);
	}
}

// Creates a 2d Vector of ints filled with "O" 
// The character "O" indicates un touched space.
void initializeDisplayBoard(int boardSize, std::vector<std::vector<int> > &displayBoard)
{
	//Row Contents
	std::vector<int> row(boardSize, false);

	//Each row is a copy of the first
	for (int i = 0; i < boardSize; i++)
	{
		displayBoard.push_back(row);
	}
}



// Fills up the board with mines
void fillBoard(int board_size, double fillGoal, std::vector<std::vector<bool> > &board)
{
	/* initialize random seed: */
	srand(time(NULL));

	int mine_count = 0;
	double fill = 0.0;
	int x = 0;
	int y = 0;


	while (fill < fillGoal)
	{
		//Generate Rand x, y
		x = rand() % board_size;
		y = rand() % board_size;

		// if location x, y does not have a mine
		if (board[y][x] == false)
		{
			// put a mine
			board[y][x] = true;

			// increase counter
			mine_count = mine_count + 1;

			// update fill //Remember to add the "double" qualifier 
			fill = (double) mine_count / (board_size*board_size);

			//Debug
			//printf("Fill: %2.2f , %2.2f \n", fill, fillGoal);

		}
				
	}
}

// Prints the boards contents to console // For Gameplay
void displayBoard(std::vector<std::vector<int> > &board)
{
	//Header
	std::cout << "  Board " << std::endl;
	displayHeader(board.size());


	// Print out the elements
	for (int i = 0; i<board.size(); i++) {

		//Print Row number
		std::cout << i << "|";

		//Print Row
		for (int j = 0; j<board[i].size(); j++)
			std::cout << board[i][j] << " ";
		std::cout << std::endl;
	}

}

// Prints the mines locations to console // For debuging
void displayMines(std::vector<std::vector<bool> > &board)
{
	//Header
	std::cout << "Mine Locations " << std::endl;
	displayHeader(board.size() );


	// Print out the elements
	for (int i = 0; i<board.size(); i++) {
		for (int j = 0; j<board[i].size(); j++)
			std::cout << board[i][j] << " ";
		std::cout << std::endl;
	}

}

void displayHeader(int size )
{
	//First Print Extra Spaces for alignment
	std::cout << "  ";

	for (int i = 0; i < size; i++)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;


	//First Print Extra Spaces for alignment
	std::cout << "  ";
	for (int i = 0; i < size; i++)
	{
		std::cout << "--";
	}

	std::cout << std::endl;
}

