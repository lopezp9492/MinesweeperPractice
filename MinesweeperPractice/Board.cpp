#include "stdafx.h"
#include "Board.h"


Board::Board()
{
}


Board::~Board()
{
}

void Board::initializeSize(int size)
{
	size_ = size;
	resetMineLocations(size_);
	resetCheckedLocations(size_);
	resetDisplayBoard(size_);
}

void Board::fill(double fillGoal)
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
		x = rand() % size_;
		y = rand() % size_;

		// if location x, y does not have a mine
		if (mine_locations_[y][x] == false)
		{
			// put a mine
			mine_locations_[y][x] = true;

			// increase counter
			mine_count = mine_count + 1;

			// update fill //Remember to add the "double" qualifier 
			fill = (double)mine_count / (size_*size_);

			//Debug
			//printf("Fill: %2.2f , %2.2f \n", fill, fillGoal);

		}

	}
}

void Board::displayMines()
{
	//Header
	std::cout << "Mine Locations " << std::endl;
	displayHeader(size_);


	// Print out the elements
	for (int i = 0; i< size_; i++) {

		//Print Row number
		std::cout << i << "|";

		//Print Row
		for (int j = 0; j< size_ ; j++)
			std::cout << mine_locations_[i][j] << " ";
		std::cout << std::endl;
	}
}

void Board::display()
{
	//Header
	std::cout << "  Board " << std::endl;
	displayHeader(size_);


	// Print out the elements
	for (int i = 0; i < size_ ; i++) 
	{

		//Print Row number
		std::cout << i << "|";

		//Print  Row
		for (int j = 0; j < size_; j++)
			std::cout << display_board_[i][j] << " ";
		std::cout << std::endl;
	}

}
void Board::clearArea(int row, int col)
{
	clear(row, col);
	resetCheckedLocations(size_);
}


// The clear function reveals the number of adjacent mines.
// It is a recursive function, uses "checked_locations_" to prevent infinite recursion.
// If we had an area much larger to check it would be beneficial to change the data structure
// to a hash

// Note:
// Recursion happens in 4 cardinal directions
// Mine count happens in 8 directions


bool Board::clear(int row, int col)
{
	//DEBUG
	std::cout << "[row, col]" << "[" << row << ", " << col << "]" << std::endl;

	//Check Range
	if (!inRange(row, col))
	{
		return false;
	}

	//Check for mine at this location
	if (check(row, col))
	{
		return false;
	}
	//else, there is no mine at this location.

	//Check if this has been recursed before
	if (checked_locations_[row][col])
	{
		return false;
	}

	//Log it
	checked_locations_[row][col] = true;

	//Count in 8 directions
	int count = mineCount(row, col);

	// Recursion in four directions
	clear(row-1, col  ); // top
	clear(row  , col+1); // right
	clear(row+1, col  ); // botttom
	clear(row  , col-1); // left

	//DEBUG
	std::cout << "count: " << count << std::endl;

	//Update the value at this location
	display_board_[row][col] = count;

	return true;
}

// returns the total number of mines surrounding this space
// Counts 8 directions
int Board::mineCount(int row, int col)
{
	//Count the mines around this location.
	int count = 0;

	// count mines in 8 directions

	// top
	if (inRange(row - 1, col) && mine_locations_[row - 1][col])
	{
		count = count + 1;
	}

	// right
	if (inRange(row, col + 1) && mine_locations_[row][col + 1])
	{
		count = count + 1;
	}

	// bottom
	if (inRange(row + 1, col) && mine_locations_[row + 1][col])

	{
		count = count + 1;
	}

	// left
	if (inRange(row, col - 1) && mine_locations_[row][col - 1])
	{
		count = count + 1;
	}

	//top-right
	if (inRange(row - 1, col + 1) && mine_locations_[row - 1][col + 1])
	{
		count = count + 1;
	}

	//top-left
	if (inRange(row - 1, col - 1) && mine_locations_[row - 1][col - 1])
	{
		count = count + 1;
	}

	//bottom-right
	if (inRange(row + 1, col + 1) && mine_locations_[row + 1][col + 1])
	{
		count = count + 1;
	}

	//bottom-left
	if (inRange(row + 1, col - 1) && mine_locations_[row + 1][col - 1])
	{
		count = count + 1;
	}

	return count;
}

bool Board::inRange(int row, int col)
{
	//check x and y boundaries // < 0 or > board.size
	if (row < 0 || col < 0)
	{
		return false;
	}
	if (row >= size_ || col >= size_)
	{
		return false;
	}
	return true;
}

bool Board::check(int row, int col)
{
	return mine_locations_[row][col];
}

void Board::resetMineLocations(int size)
{
	mine_locations_.clear();

	//Row Contents
	std::vector<bool> row(size, false);

	//Each row is a copy of the first
	for (int i = 0; i < size; i++)
	{
		mine_locations_.push_back(row);
	}
}

void Board::resetCheckedLocations(int size)
{
	checked_locations_.clear();

	//Row Contents
	std::vector<bool> row(size, false);

	//Each row is a copy of the first
	for (int i = 0; i < size; i++)
	{
		checked_locations_.push_back(row);
	}
}


void Board::resetDisplayBoard(int size)
{
	display_board_.clear();

	//Row Contents
	std::vector<int> row(size, 0);

	//Each row is a copy of the first
	for (int i = 0; i < size; i++)
	{
		display_board_.push_back(row);
	}
}

void Board::displayHeader(int size)
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
