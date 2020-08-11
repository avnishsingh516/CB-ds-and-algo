// Minimum Steps Bottom Up [Code]
// time ans space :- O(n)


#include <iostream>
#include <climits>
using namespace std;

int minStepsBU(int n) {

	int dp[1000] = {0};

	dp[1] = {0};

	for (int i = 2 ; i <= n ; i++) {

		int op1 , op2 , op3;
		op1 = op2 = op3 = INT_MAX;

		if (i % 3 == 0) {
			op1 = dp[i / 3];
		}
		if (n % 2 == 0) {
			op2 = dp[i / 2];
		}

		op3 = dp[i - 1];

		dp[i] = min(op1, min(op2, op3)) + 1;
	}

	return dp[n];

}

int main(int argc, char const *argv[])
{
	int n = 6;
	// cin >> n;

	cout << minStepsBU(n) << endl;

	return 0;
}