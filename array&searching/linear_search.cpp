#include<bits/stdc++.h>
using namespace std;

int main() {
	int n , k ;
	cin >> n;
	int a[n];
	for ( int i = 0 ; i < n ; i++)
		cin >> a[i];
	cin >> k;

	int i;
	for ( i = 0 ; i < n ; i++) {
		if (a[i] == k) {
			cout << "found at index " << i << endl;
			break;
		}
	}

	if (i == n)
		cout << "not found";


	return 0;
}