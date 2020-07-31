// Bottom Up DP Fibonacci Implementation
// time and space :- O(n)

#include <iostream>
using namespace std;

int fib(int n) {

	int dp[1000] = {0};
	dp[1] = 1;

	for (int i = 2 ; i <= n ; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];

}

//bottom up Space Optimisation method :- iterative one
// space:- O(1) and time:- O(n)

int fibSpaceOpt( int n) {

	int a = 0 , b = 1, c;
	for (int i = 2 ; i <= n ; i++) {
		c = a + b;
		a = b;
		b = c;
	}

	return c;

}

int main(int argc, char const *argv[])
{
	int n ;
	cin >> n;

	cout << fibSpaceOpt(n) << endl;

	return 0;
}