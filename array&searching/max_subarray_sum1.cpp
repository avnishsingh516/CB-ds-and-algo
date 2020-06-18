

// approach 1 by using 3 loops O(N^3)

#include<bits/stdc++.h>
using namespace std;

int main() {

	int n , max = 0;
	cin >> n;

	int a[n];

	// left and right are used to give the indexes of subarray whose sum is maximum
	int left = -1 , right = -1;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// cout << "\n\n  sum :- \n";

	for (int i = 0 ; i < n ; i++) {
		// i gives the initial index of the subarray
		for (int j = i ; j < n ; j++) {
			// j gives the subarray from i-th index to the last index of array
			int sum = 0;
			// sum gives the current sum of subarray
			for (int k = i ; k <= j ; k++) {
				// k is used to print the subarray from ith to jth index

				sum += a[k];

			}

			// cout << sum << endl;
			// it is used to see the sum of every subarray

			// updating maximum subarray
			if (sum > max) {
				max = sum;
				// updating the max sum subarray indexes
				left = i;
				right = j;
			}

		}

	}

	cout << "\n max :- " << max << endl;
	cout << "subarray whose sum is max :- " << endl;

	for (int k = left ; k <= right ; k++) {
		cout << a[k] << " ";
	}
	cout << endl;

	return 0;

}