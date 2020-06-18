#include <bits/stdc++.h>
using namespace std;

int fact(int n) {
	int ans = 1 ;
	for (int i = 1 ; i <= n ; i++) {
		ans *= i;
	}

	return ans;
}

int ncr(int n , int r) {
	return (fact(n) / (fact(n - r) * fact(r)));
}

int main() {

	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n ;
	cin >> n;

	// cout << fact(n);
	int r;
	cin >> r;

	cout << ncr(n , r);

	return 0;
}