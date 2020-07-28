// Coin Change Top Down
// time:- O(TN) , where T:- types of coins , N:- cost

#include<iostream>
#include<climits>
using namespace std;

int minCoins(int n, int coins[], int T, int dp[]) {
	//base case
	if (n == 0) {
		return 0;
	}

	//dp look up case
	if (dp[n] != 0) {
		return dp[n];
	}

	//rec case
	int ans = INT_MAX;

	for (int i = 0 ; i < T ; i++) {
		//dont pick the coin which is greater than n itself
		if (n - coins[i] >= 0) {
			int curr_ans = minCoins(n - coins[i], coins, T, dp) + 1;
			ans = min(ans, curr_ans);
		}
	}

	return dp[n] = ans;
}

int main(int argc, char const *argv[])
{
	int n = 15;
	// cin>>n;

	int coins[] = {1, 7, 3};
	int t = sizeof(coins) / sizeof(int);

	int dp[100] = {0};

	cout << minCoins(n, coins, t, dp) << endl;

	return 0;
}

