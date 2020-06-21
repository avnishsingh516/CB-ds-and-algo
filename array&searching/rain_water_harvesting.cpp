#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];

	for (int i = 0 ; i < n ; i++) {
		cin >> a[i];
	}

	int left[n]; // find the left adjacent largest building from the left side at each index
	int l = a[0];

	for (int i = 0 ; i < n ; i++) {
		if (a[i] > l) {
			l = a[i];
		}

		left[i] = l;
	}

	int right[n]; // find the right adjacent largest building from the right side at each index
	int r = a[n - 1];

	for (int i = n - 1 ; i >= 0 ; i--) {
		if (a[i] > r) {
			r = a[i];
		}

		right[i] = r;
	}

	//the water trapping at any index is depends on the min height of the adjacent buildings
	// basically , is the min height of the adjacent buildings - height of the building at that index
	int trap_water = 0 ;

	for (int i = 0 ; i < n ; i++) {
		trap_water += min(right[i] , left[i]) - a[i];
	}

	cout << trap_water << endl;
	return 0;
}