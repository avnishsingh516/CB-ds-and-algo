#include <iostream>
using namespace std;

int laddersBU(int n, int k) {
	int dp[1000] = {0};
	dp[0] = 1; //start case

	for (int i = 1 ; i <= n ; i++) {
		// k steps
		for (int j = 1 ; j <= k ; j++) {
			//for non -ve
			if (i - j >= 0) {
				dp[i] += dp[i - j];
			}
		}
	}

	return dp[n];
}

int main(int argc, char const *argv[])
{
	int n = 4, k = 3;
	// cin >> n >> k;

	cout << "bottom up ways:- " << laddersBU(n, k) << endl;

	return 0;
}