
// complexity:- O(N^2)

// only works for sorted array

#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];

	for ( int i = 0 ; i < n ; i++) {
		cin >> a[i];
	}

	int key;
	cin >> key;

	sort(a, a + n);

	//in for loop first value is fixed
	for (int first = 0 ; first < n - 2 ; first++) {

		//after fixing the first value we proceed for second and third
		// same procedure as sum pair
		int second = first + 1;
		int third = n - 1;

		while (second < third) {

			int sum = a[first] + a[second] + a[third];

			if (sum == key) {
				cout << a[first] << ", " << a[second] << " and " << a[third] << endl;
				second++;
				third--;
			}
			else if (sum > key) {
				third--;
			}
			else {
				second++;
			}
		}
	}

	return 0;
}