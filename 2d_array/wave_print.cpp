#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int row , col;
	cin >> row >> col;

	int a[row][col];

	for ( int i = 0 ; i < row ; i++) {
		for (int j = 0 ; j < col ; j++)
			cin >> a[i][j];
	}
	cout << endl << "wave print :- " << endl;
	for (int j = 0 ; j < col ; j++) {

		if (j % 2 == 0) {
			// even col - top down dir
			for (int i = 0 ; i < row ; i++)
				cout << a[i][j] << " ";
		}
		else {
			//bottom up dir
			for (int i = row - 1 ; i >= 0 ; i--)
				cout << a[i][j] << " ";
		}

	}
	return 0;
}