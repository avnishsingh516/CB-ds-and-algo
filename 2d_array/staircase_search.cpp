#include <bits/stdc++.h>
using namespace std;

// time complexity O(N)

void staircase(int a[][10] , int n, int key) {

	// defines the pointer at top right corner
	int row = 0;
	int col = n - 1;

	int t = 0 ; //no of steps taken

	while ( row<n and col >= 0) {

		if (a[row][col] == key) {
			cout << "found at " << row << " , " << col << "index" << endl;
			cout << "no of steps taken :- " << t << endl;

			return;
		}
		else if (a[row][col] > key) {
			col--;
		}
		else if (a[row][col] < key) {
			row++;
		}

		t++;
	}

	cout << "not found" << endl;

}

//only for sorted 2d array
int main(int argc, char const *argv[])
{
	int n , key;
	cin >> n; // no of rows and col are same
	cin >> key; //key which have to find
	int a[10][10];

	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < n ; j++) {
			cin >> a[i][j];
		}
	}

	staircase(a, n, key);

	return 0;
}