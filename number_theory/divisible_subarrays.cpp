#include <bits/stdc++.h>
using namespace std;

#define ll long

ll a[1000005] , pre[1000005]; //pre is for frequency array

int main(int argc, char const *argv[])
{
	int t; //no of test case
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		memset(pre, 0, sizeof(pre)); //initalize whole pre array with zero ,we can also use pre[100005]={0}

		pre[0] = 1;

		//read the input
		int sum = 0;
		for (int i = 0 ; i < n ; i++) {
			cin >> a[i];
			sum += a[i]; //cummalative sum
			sum %= n;
			sum = (sum + n) % n; //if the sum is -ve ,so make it positive we add n to it and mod by n which makes the result +ve but donot change the result
			pre[sum]++; //increase the freq of the sum index by 1

		}

		ll ans = 0;
		for (int i = 0; i < n ; i++) {
			ll m = pre[i];
			ans += ((m) * (m - 1)) / 2; //mC2

		}

		cout << ans << endl;


	}
	return 0;
}