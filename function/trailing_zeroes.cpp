
// Count trailing zeroes in factorial of a number

#include <bits/stdc++.h>
using namespace std;

int tz(int n) {
	int ans = 0;
	for (int d = 5 ; n / d >= 1 ; d *= 5)
		ans += n / d;

	return ans;
}

int main() {

	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	cout << tz(n);

	return 0;
}