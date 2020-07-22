// https://www.youtube.com/watch?v=XHjjIJxnAJY
//based on matrix chain multiplication

#include <bits/stdc++.h>
using namespace std;

int dp[100][100];
int arr[100];

//cumulative sum
int sum(int s, int e) {
	int ans = 0;

	for (int i = s ; i <= e ; i++) {
		ans += arr[i];
		ans %= 100;
	}
	return ans;
}

int solveMixtures(int i, int j) {
	//base case
	if (i >= j) {
		return 0;
	}

	//dp look up
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	//rec case

	//we break our expression at every possible k
	dp[i][j] = INT_MAX;

	for (int k = i; k <= j ; k++) {
		dp[i][j] = min(dp[i][j], solveMixtures(i, k) + solveMixtures(k + 1, j) + sum(i, k) * sum(k + 1, j));
	}

	return dp[i][j];

}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	for (int i = 0 ; i < n ; i++) {
		cin >> arr[i];
	}

	// dp
	//init dp with -1;
	for (int i = 0 ; i <= n ; i++) {
		for (int j = 0 ; j <= n ; j++) {
			dp[i][j] = -1;
		}
	}

	cout << solveMixtures(0, n - 1) << endl;

	return 0;
}

// 3
// 40 60 20
// 2400

// 2
// 18 19
// 342
