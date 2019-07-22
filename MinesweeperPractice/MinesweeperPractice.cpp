// MinesweeperPractice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>


void initializeBoard(int boardSize, std::vector<std::vector<bool> > &board);
void initializeDisplayBoard(int board_size, std::vector<std::vector<int> > &display_board);

void fillBoard(double fillPercent, std::vector<std::vector<bool> > &board);

void displayMines(std::vector<std::vector<bool> > &board);
void displayBoard(std::vector<std::vector<int> > &board);



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
	fillBoard(input_fill, board);

	//Test Output 
	std::cout << "board_size = " << board_size << std::endl;
	std::cout << "input_fill = " << input_fill << std::endl;
	displayMines(board);
	displayBoard(display_board);


	// Game Loop

		// Display Board
		// Get Input 
		// Process Input
		

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
void fillBoard(double fillPercent, std::vector<std::vector<bool> > &board)
{


}

// Prints the boards contents to console // For Gameplay
void displayBoard(std::vector<std::vector<int> > &board)
{
	//Header
	std::cout << "Board " << std::endl;

	// Print out the elements
	for (int i = 0; i<board.size(); i++) {
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

	// Print out the elements
	for (int i = 0; i<board.size(); i++) {
		for (int j = 0; j<board[i].size(); j++)
			std::cout << board[i][j] << " ";
		std::cout << std::endl;
	}

}
