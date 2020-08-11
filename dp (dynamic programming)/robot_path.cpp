#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[1001][1001];

int ways(int row, int col) {

	//base case
	//check the initial and last cell
	if (dp[0][0] == -1 or dp[row - 1][col - 1] == -1) {
		return 0;
	}

	//compute the no of ways of first row
	for (int j = 0 ; j < col ; j++) {

		if (dp[0][j] == -1) {
			break;
		}

		dp[0][j] = 1;
	}

	//compute the no of ways of first col
	for (int j = 0 ; j < row ; j++) {

		if (dp[j][0] == -1) {
			break;
		}

		dp[j][0] = 1;
	}

	//rest of the dp :- bottom up approach
	for (int i = 1 ; i < row ; i++) {
		for (int j = 1 ; j < col ; j++) {

			//if cell is blocked, then leave it
			if (dp[i][j] == -1) {
				continue;
			}

			//init curr cell as 0 and then compute it
			dp[i][j] = 0;

			if (dp[i][j - 1] != -1) {
				dp[i][j] = dp[i][j - 1] % MOD;
			}

			if (dp[i - 1][j] != -1) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
			}
		}
	}

	return dp[row - 1][col - 1];

}

int main(int argc, char const *argv[])
{
	memset(dp, 0, sizeof dp);

	int M, N, P; //M:-rows , N:-col , P:- no of blocked cell
	cin >> M >> N >> P;

	for (int i = 0 ; i < P; i++) {
		int x, y; //rows and col of blocked cell
		cin >> x >> y;
		dp[x - 1][y - 1] = -1; //mark all the blocked cell as -1
	}

	cout << ways(M, N) << endl;

	return 0;
}

// 4 3 2
// 3 3
// 3 1

// 2
