// Minimum Steps Top Down [Code]
// time ans space :- O(n)

#include <iostream>
#include <climits>
using namespace std;


//Minimum steps to one
// n-> n / 3, n / 2, n - 1

int minSteps(int n , int dp[]) {
	//base case
	if (n == 1) {
		return 0;
	}
	//rec case

	//dp look up case
	if (dp[n] != 0) {
		return dp[n];
	}

	int op1 , op2, op3;
	op1 = op2 = op3 = INT_MAX;

	if (n % 3 == 0) {
		op1 = minSteps(n / 3, dp);
	}
	if (n % 2 == 0) {
		op2 = minSteps(n / 2, dp);
	}

	op3 = minSteps(n - 1, dp);

	int ans = min(op1 , min(op2 , op3)) + 1;

	return dp[n] = ans;

}

int main(int argc, char const *argv[])
{
	int n = 5  ;
	// cin>>n;

	int dp[1000] = {0};

	cout << minSteps(n, dp) << endl;

	return 0;
}