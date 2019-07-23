#pragma once
#include <iostream>
#include <vector>
#include <time.h>       /* time */


class Board
{


public:
	Board();

	~Board();

	void initializeSize(int size);
	void fill(double fillGoal);

	void displayMines();
	void display();

	bool clear(int row, int col);
	bool check(int row, int col);

private:

	//Variables
	int size_;
	std::vector<std::vector<bool> > mine_locations_;
	std::vector<std::vector<bool> > checked_locations_;
	std::vector<std::vector<int> > display_board_;

	void resetMineLocations(int size);
	void resetCheckedLocations(int size);
	void resetDisplayBoard(int size);

	void displayHeader(int size);		//helper function
	bool inRange(int start, int end);	//helper funcion
};

