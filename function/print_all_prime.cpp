
// print_all_prime no upto nth no.
#include <bits/stdc++.h>
using namespace std;

bool isprime(int n) {
	for (int i = 2 ; i < n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

void printprimes(int n) {

	for (int i = 2 ; i <= n ; i++) {
		if (isprime(i))
			cout << i << " ";
	}
}


int main() {

	ios_base::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	printprimes(n);

	return 0;
}