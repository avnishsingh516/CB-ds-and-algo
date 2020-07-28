// Coin Change Top Down
// time:- O(TN) , where T:- types of coins , N:- cost


#include <iostream>
#include <climits>
using namespace std;

int minCoinsBU(int N, int coins[], int t) {

	int dp[1000] = {0};

	//iterate over all states 1....N
	for (int n = 1 ; n <= N ; n++) {
		//initialize the curr ans as INT_MAX
		dp[n] = INT_MAX;

		for (int i = 0 ; i < t ; i++) {

			if (n - coins[i] >= 0) {
				int curr_ans = dp[n - coins[i]] + 1;
				dp[n] = min(dp[n ], curr_ans);
			}
		}

	}

	return dp[N];
}

int main(int argc, char const *argv[])
{
	int N = 15;
	// cin>>N;

	int coins[] = {1, 7, 3};
	int t = sizeof(coins) / sizeof(int);


	cout << minCoinsBU(N, coins, t) << endl;


	return 0;
}