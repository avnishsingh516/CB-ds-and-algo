
// only works for sorted array

#include<bits/stdc++.h>
using namespace std;

int binary_search(int a[] , int n, int k) {

	int s = 0 , e = n - 1 , mid;

	while (s <= e) {
		mid = (s + e) / 2;
		if (a[mid] == k) {
			return mid;
			break;
		}
		else if (a[mid] > k)
			e = mid - 1;
		else
			s = mid + 1;

	}
	return -1;
}

int main() {
	int n , k ;
	cin >> n;
	int a[n];
	for ( int i = 0 ; i < n ; i++)
		cin >> a[i];

	cin >> k;

	cout << binary_search(a , n , k) << endl;
	// int ans = binary_search(a , n , k) ;
	// if (ans == -1) {
	// 	cout << "not found" << endl;
	// }
	// else
	// 	cout << "found at " << ans << endl;


	return 0;
}