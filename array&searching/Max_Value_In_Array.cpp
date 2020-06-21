#include<bits/stdc++.h>
using namespace std;

int main() {
	long long int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int m = INT_MIN;
	for (int i = 0 ; i < n; i++) {
		m = max(a[i], m);
	}
	cout << m;
	return 0;
}