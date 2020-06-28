// Normal Backtracking Code

#include <iostream>
using namespace std;

// placing a queen is safe or not
bool isSafe(int board[][10] , int i, int j , int n) {

	//check col
	for (int row = 0 ; row < i ; row++) {
		if (board[row][j] == 1) {
			//queen is already places at that place
			return false;
		}
	}

	//check for top left diagonal
	int x = i;
	int y = j;

	while (x >= 0 and y < n) {
		if (board[x][y] == 1) {
			return false;
		}
		x--;
		y++;
	}

	//check for top right diagonal
	x = i;
	y = j;

	while (x >= 0 and y >= 0) {
		if (board[x][y] == 1) {
			return false;
		}
		x--;
		y--;
	}

	//the pos is now safe , on col and diagonals
	return true;

}

// function
bool solveNQueen(int board[][10] , int i , int n) {
	// i is current row

	//base case
	if (i == n) {
		//you have successfully place queens in n rows (0....n-1)

		//print board
		for (int i = 0 ; i < n ; i++) {
			for (int j = 0 ; j < n ; j++) {
				if (board[i][j] == 1) {
					cout << " Q ";
				}
				else {
					cout << " - ";
				}
			}
			cout << endl;
		}

		cout << endl << endl; //use this at the time of multiple solution


		// only for 1 solution we return true
		return true;

		// if we want all the solution, we have to return false rather than return true
		// return false;
	}

	//rec case
	//try to place the queen in the current row and call on the remaining part , which can be solved by the use of reursuion
	for (int j = 0 ; j < n ; j++) {
		//I have to check if i,j th position is safe to place the queen or not.

		if (isSafe(board, i, j, n)) {
			//place the queen - Assuming i,j is the right position
			board[i][j] = 1;

			// can we able to place the next queen
			bool nextQueenRakhPaye = solveNQueen(board, i + 1, n);

			if (nextQueenRakhPaye) {
				return true;
			}

			//nextQueenRakhPaye is false , it means i,j is not the right position -> Assumption is wrong
			board[i][j] = 0; //backtracing
			// we correct or backtrack the value of board which we assume is true , but it is false
		}
	}
	//we tried for all position in the current row but couldn't place a queen
	return false;
}

int main(int argc, char const *argv[])
{
	int n = 4; //no of rows
	// cin>>n;

	int board[10][10] = {0};

	solveNQueen(board, 0, n);
	return 0;
}