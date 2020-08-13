// wines problem top down approach
//time :- O(n^2)

#include<iostream>
using namespace std;

// i:- start and j:- end indexes
// y:- current year
int profit(int wines[] , int i, int j , int y , int dp[][1000]) {
	//base case
	if (i > j) {
		return 0;
	}

	//dp look up
	if (dp[i][j] != 0) {
		return dp[i][j];
	}

	//rec case

	//sell first or i th bottle
	int op1 = wines[i] * y + profit(wines, i + 1, j, y + 1, dp);

	//sell the last or jth bottle
	int op2 = wines[j] * y + profit(wines, i, j - 1, y + 1, dp);

	//max profit
	int ans = max(op1, op2);

	return dp[i][j] = ans;

}

int main(int argc, char const *argv[])
{

	int wines[] = {2, 3, 5, 1, 4};
	int n = sizeof(wines) / sizeof(int);
	int y = 1;

	int dp[1000][1000] = {0};

	cout << profit(wines, 0, n - 1, y , dp) << endl;

	return 0;
}