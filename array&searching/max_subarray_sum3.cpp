

// approach 3 by using 1 loops O(N)
// using kadane's algo

#include<bits/stdc++.h>
using namespace std;

int main() {

	int n ;
	cin >> n;

	int a[n] ;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int cs = 0; //current sum
	int ms = 0; //max subarray sum


	// kadane's algo

	for (int i = 0 ; i < n ; i++) {
		cs = cs + a[i];

		if (cs < 0) {
			cs = 0;
		}

		ms = max(ms, cs);
	}

	cout << "\n max :- " << ms << endl;

	return 0;
}