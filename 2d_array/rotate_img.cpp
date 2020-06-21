#include <bits/stdc++.h>
using namespace std;

// 90 deg anti clockwise rotation
// inplace method without using extra space

void rotate(int a[][10] , int n) {

	// reverse each rows
	for (int i = 0 ; i < n ; i++) {
		int start_col = 0;
		int end_col = n - 1;

		while (start_col < end_col) {
			swap(a[i][start_col] , a[i][end_col]);
			start_col++;
			end_col--;
		}
	}

	//to take transponse
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < n ; j++) {
			if (i < j) {
				swap(a[i][j] , a[j][i]);
			}
		}
	}
}

// same function but by using reverse stl function
void rotate_stl(int a[][10] , int n) {

	//same thing using reverse(start_containter , end_container)
	for (int i = 0 ; i < n ; i++) {
		reverse(a[i] , a[i] + n); // here a[i] is the pointer of the each row and "a" is work as pointer of the 2d array
	}

	//to take transponse
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < n ; j++) {
			if (i < j) {
				swap(a[i][j] , a[j][i]);
			}
		}
	}

}


int main(int argc, char const *argv[])
{
	int n;
	cin >> n; //no of rows and col are same

	int a[10][10];

	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < n ; j++) {
			cin >> a[i][j];
		}
	}

	cout << endl << "  (90 deg) rotated matrix :- " << endl;

	// rotate(a , n);
	rotate_stl(a, n);

	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < n ; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}