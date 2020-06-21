#include <bits/stdc++.h>
using namespace std;

// clockwise spiralprint
//for edgecases refer bottom of the code
void spiralprint( int a[][10] , int m, int n  ) {

	int startrow = 0;
	int startcol = 0;
	int endrow = m - 1;
	int endcol = n - 1;

	while (startrow <= endrow and startcol <= endcol) {
		// first row

		for (int i = startcol; i <= endcol ; i++) {
			cout << a[startrow][i] << " ";
		}

		startrow++;

		//last col
		for (int i = startrow; i <= endrow ; i++) {
			cout << a[i][endcol] << " ";
		}

		endcol--;

		// last row
		if (endrow > startrow) {	//if statement is used to over come the edge case

			for (int i = endcol; i >= startcol ; i--) {
				cout << a[endrow][i] << " ";
			}

			endrow--;

		}


		// start col
		if (endcol > startcol) { //if statement is used to over come the edge case

			for (int i = endrow; i >= startrow ; i--) {
				cout << a[i][startcol] << " ";
			}

			startcol++;

		}

	}

	cout << endl;
}

int main(int argc, char const *argv[])
{
	int row , col;
	cin >> row >> col;

	int a[10][10] = {0};

	for ( int i = 0 ; i < row ; i++) {
		for (int j = 0 ; j < col ; j++)
			cin >> a[i][j];
	}
	cout << endl << "spiral print :- " << endl;

	spiralprint(a, row, col);

	return 0;
}

// edge cases:-

// we use if statement for last printing the "last row and start col"
// as u can see in the function

// it is because during the spiral print the even no of rows and columns it works fine
// but for odd no of rows and columns it print a row or col twice which gives wrong output
// so, it is fixed by using the if statement