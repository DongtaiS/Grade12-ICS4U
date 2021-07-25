#pragma once
#include <iostream>
#include <vector>
using namespace std;
void drawBoard(std::vector<std::vector<char>> draw)
{
	std::cout << "-------------\n";
	for (int i = 0; i < draw.size(); i++)
	{
		for (int j = 0; j < draw[i].size(); j++)
		{
			std::cout << "| " << draw[i][j] << " ";
		}
		std::cout << "|";
		std::cout << '\n';
		std::cout << "-------------\n";
	}
}

void setupBoard(int row, int col, std::vector<std::vector<char> >& draw)
{
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			draw[r][c] = '0' + r * 3 + c + 1;
		}
	}
}

bool tryPlaceAt(int r, int c, bool player1Turn, vector<vector<char>>& board)
{
	char& charToReplace = board[r][c];
	if (charToReplace == 'X' || charToReplace == 'O')
	{
		return false;
	}
	else
	{
		if (player1Turn)
		{
			charToReplace = 'X';
		}
		else
		{
			charToReplace = 'O';
		}
		return true;
	}
}
int getCoordinateInput()
{
	int input;
	cout << "Where would you like to place your piece? \n";
	cout << "Enter a number corresponding to the desired grid square \n";
	cin >> input;
	while (!cin.good() || input < 1 || input > 9)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a number from 1-9 corresponding to the desired grid square \n";
		cin >> input;
	}
	return input - 1;
}
// check the outcome of the board. 1 - 'X' wins, 2 - 'O' wins, 3 - tie, 0 - no win
int checkOutcome(vector<vector<char>> board)
{
	// check rows 
	for (int i = 0; i < 3; i++)
	{
		vector<char> row = board[i];
		if (row[0] == row[1] && row[1] == row[2])
		{
			if (row[0] == 'X')
			{
				return 1;
			}
			else if (row[0] == 'O')
			{
				return 2;
			}
		}
	}
	// check columns 
	for (int i = 0; i < 3; i++)
	{
		vector<char> col;
		for (int j = 0; j < 3; j++)
		{
			col.push_back(board[j][i]);
		}

		if (col[0] == col[1] && col[1] == col[2])
		{
			if (col[0] == 'X')
			{
				return 1;
			}
			else if (col[0] == 'O')
			{
				return 2;
			}
		}
	}
	// check diagonals
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		if (board[0][0] == 'X')
		{
			return 1;
		}
		else if (board[0][0] == 'O')
		{
			return 2;
		}
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		if (board[0][2] == 'X')
		{
			return 1;
		}
		else if (board[0][2] == 'O')
		{
			return 2;
		}
	}
	// check for tie 
	bool spotOpen = false;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] != 'X' && board[i][j] != 'O')
			{
				spotOpen = true;
			}
		}
	}
	if (!spotOpen)
	{
		return 3;
	}
	return 0;
}
bool playAgain()
{
	char input;
	cout << "Would you like to play again? (y/n) \n";
	cin >> input;
	while (input != 'Y' && input != 'y' && input != 'N' && input != 'n')
	{
		cout << "Please enter 'y' or 'n' \n";
		cin >> input;
	}
	return input == 'Y' || input == 'y';
}