// Top Down DP Fibonacci Implementation
// time and space :- O(n)

#include <iostream>
using namespace std;

int fib(int n , int dp[]) {

	//base case
	if (n == 0 or n == 1) {
		return n;
	}
	//rec case

	//dp look up
	if (dp[n] != 0) {
		return dp[n];
	}

	int ans = fib(n - 1, dp) + fib(n - 2, dp);

	return dp[n] = ans;

}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	int dp[1000] = {0};

	cout << fib(n, dp) << endl;

	return 0;
}