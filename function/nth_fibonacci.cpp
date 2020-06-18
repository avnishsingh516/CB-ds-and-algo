
#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
	int a = 0 , b = 1 , c;
	for (int i = 2; i <= n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}

	return c;
}

int main() {

	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	cout << fib(n);

	return 0;
}