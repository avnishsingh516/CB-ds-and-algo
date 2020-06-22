#include<bits/stdc++.h>
using namespace std;

bool comp(string a, string b) {
	return a + b > b + a;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string a[n];

		for (int i = 0 ; i < n; i++)
			cin >> a[i];

		sort(a, a + n, comp);

		for (int i = 0 ; i < n; i++)
			cout << a[i];

		cout << endl;
	}
	return 0;
}