// Rod Cutting to maximize profit
// https://youtu.be/ItGgZ5oMBn0

#include <iostream>
using namespace std;

//memonization
int memo[100];
//top down DP Approach
int maxProfit(int arr[] , int totalLen) {

	//base case
	if (totalLen == 0) {
		return 0;
	}

	//dp lookup case
	if (memo[totalLen] != -1) {
		return memo[totalLen];
	}

	//rec case
	int best = 0; //best profit

	//first cut the rod into parts 1,2,...upto totalLen ans rest will find by recursion
	for (int len = 1; len <= totalLen; len++) {
		int netProfit = arr[len] + maxProfit(arr, totalLen - len);
		best = max(best, netProfit);
	}

	return memo[totalLen] = best;
}


//bottom up DP approach
int maxProfitBU(int arr[] , int totalLen) {

	int dp[100] = {0};
	dp[0] = 0; //start case

	//length of rope
	for (int len = 1 ; len <= totalLen; len++) {
		int best = 0;
		// make cut the rope and for remaining length we call the dp[len-cut] and find the max profit
		for (int cut = 1; cut <= len; cut++) {
			best = arr[cut] + dp[len - cut];
			dp[len] = max(best, dp[len]);
		}
	}

	return dp[totalLen];
}

int main(int argc, char const *argv[])
{

	int priceOfEachLen[100];
	int totalLen;
	cin >> totalLen;

	// input the price the of length of the rod from 1...totalLen
	for (int eachPiece = 1; eachPiece <= totalLen; eachPiece++ ) {
		cin >> priceOfEachLen[eachPiece];
	}

	//reset memopad
	for (int i = 0 ; i <= totalLen; i++) {
		memo[i] = -1;
	}

	int ans = maxProfit(priceOfEachLen, totalLen);
	cout << ans << endl;

	//bottom up
	// cout << maxProfitBU(priceOfEachLen, totalLen) << endl;

	return 0;
}

/*
I/P:-
4
2 3 2 5

O/P:-
8
*/

/*
I/P:-
4
1 3 2 5

O/P:-
6
*/