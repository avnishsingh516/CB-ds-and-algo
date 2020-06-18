#include<bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << endl << "subarrays:- \n";

	for (int i = 0 ; i < n ; i++) {
		// i gives the initial index of the subarray
		for (int j = i ; j < n ; j++) {
			// j gives the subarray from i-th index to the last index of array
			for (int k = i ; k <= j ; k++) {
				// k is used to print the subarray from ith to jth index
				cout << a[k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}