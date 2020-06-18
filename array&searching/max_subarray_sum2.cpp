

// approach 2 by using 2 loops O(N^2)
// using cummulative sum

#include<bits/stdc++.h>
using namespace std;

int main() {

	int n , max = 0;
	cin >> n;

	int a[n] ;
	int csum[n] = {0};
	//csum is cummulative sum

	cin >> a[0];
	csum[0] = a[0];

	// left and right are used to give the indexes of subarray whose sum is maximum
	int left = -1 , right = -1;

	for (int i = 1; i < n; i++) {
		cin >> a[i];
		csum[i] = csum[i - 1] + a[i];
		// stores the csum of every index of array
	}

	// cout << "\n\n  sum :- \n";

	for (int i = 0 ; i < n ; i++) {
		// i gives the initial index of the subarray
		for (int j = i ; j < n ; j++) {
			// j gives the subarray from i-th index to the last index of array
			int sum = 0;
			// sum gives the current sum of subarray
			sum = csum[j] - csum[i - 1];
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