#include "Util.h"
using namespace std;

int main()
{
    do
    {
        vector<vector<char>> board { {'1', '2', '3'}, { '4', '5', '6' }, { '7', '8', '9' } };
        bool player1Turn = true; //Bool representing which player’s turn it is
        do
        {
			if (player1Turn)
			{
				cout << "\nIt's player 1's turn! (X's) \n";
			}
			else
			{
				cout << "\nIt's player 2's turn! (O's) \n";
			}
            drawBoard(board); //Drawing the board 
			int coord = getCoordinateInput();
            while (!tryPlaceAt(coord / 3, coord % 3, player1Turn, board))
            {
                cout << "Not a valid position! Try again." << endl;
                coord = getCoordinateInput();
            }
			player1Turn = !player1Turn;
        } while (checkOutcome(board) == 0); //continue while loop if there is no outcome yet
		drawBoard(board); // display the board after game is over
        if (checkOutcome(board) == 1)
        {
			cout << "Player 1 (X's) wins! \n";
        }
        else if (checkOutcome(board) == 2)
        {
			cout << "Player 2 (O's) wins! \n";
        }
        else if (checkOutcome(board) == 3)
        {
			cout << "It's a tie! \n";
        }
    } while (playAgain()); // outerloop while condition
}