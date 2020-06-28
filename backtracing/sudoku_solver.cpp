//solve the sudoku of 9X9

#include <iostream>
#include <cmath>

using namespace std;

//check we can place the number or not
bool canPlace(int mat[9][9] , int i , int j , int n , int number) {

	for (int x = 0 ; x < n ; x++) {
		//row and col check
		if (mat[x][j] == number || mat[i][x] == number) {
			return false;
		}
	}

	int rn = sqrt(n);
	int sx = (i / rn) * rn; //gives starting row of the cell
	int sy = (j / rn) * rn; //gives starting col of the cell

	for (int x = sx ; x < sx + rn ; x++) {
		for (int y = sy ; y < sy + rn ; y++) {
			if (mat[x][y] == number) {
				//number is already present in cell
				return false;
			}
		}
	}
	// number is not found in the cell , so we can place the number here
	return true;
}

bool solveSudoku(int mat[9][9] , int i , int j , int n) {
	//base case
	if (i == n) {
		//print matrix
		for (int i = 0 ; i < n; i++) {
			for (int j = 0 ; j < n ; j++) {
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}

		return true;
	}

	//case row end
	if (j == n) {
		return solveSudoku(mat, i + 1, 0, n);
	}

	//skip the pre-filled cells
	if (mat[i][j] != 0) {
		return solveSudoku(mat, i, j + 1, n);
	}

	//rec case

	//fill the current cell with possible options
	for (int number = 1 ; number <= n ; number++) {
		if (canPlace(mat, i, j, n, number)) {

			//assume we can solve the sudoku by this number
			mat[i][j] = number;

			// could we able to solve the sudoku
			bool couldWeSolve = solveSudoku(mat, i, j + 1, n);

			if (couldWeSolve == true) {
				//we able to silve the sudoku
				return true;
			}
		}
	}

	//backtracking

	//we could not able to solve the sudoku
	mat[i][j] = 0;

	return false;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int mat[9][9];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mat[i][j];
		}
	}
	cout << endl << " soln:- " << endl;
	bool solved = solveSudoku(mat , 0 , 0 , n);

	if (solved != true) {
		cout << "sudoku can't solved" << endl;
	}

	return 0;
}