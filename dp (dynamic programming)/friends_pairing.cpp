// refer gfg :- https://youtu.be/jRKbOe88UYo

#include <bits/stdc++.h>
using namespace std;

int dp[1000]; //dp array common to all function

// 1. top down dp approach
// time and space :- O(n)

// Returns count of ways n people
// can remain single or paired up.
int countFriendsPairings(int n)
{
	if (dp[n] != -1)
		return dp[n];

	if (n > 2)
		return dp[n] = countFriendsPairings(n - 1) + (n - 1) * countFriendsPairings(n - 2);
	else
		return dp[n] = n;
}


// 2. bootom up dp approach
// time and space :- O(n)
int countFriendsPairingsBU(int n)
{
	int dp[n + 1];

	// Filling dp[] in bottom-up manner using
	// recursive formula explained above.
	for (int i = 0; i <= n; i++) {
		if (i <= 2)
			dp[i] = i;
		else
			dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
	}

	return dp[n];
}


// 3. space optimised approach simillar to fibonnaci
// time:- O(n) and space:- O(1)
int countFriendsPairingsOP(int n)
{
	int a = 1, b = 2, c = 0;
	if (n <= 2) {
		return n;
	}
	for (int i = 3; i <= n; i++) {
		c = b + (i - 1) * a;
		a = b;
		b = c;
	}
	return c;
}



int main()
{
	memset(dp, -1, sizeof(dp));
	int n = 4;
	cout << countFriendsPairings(n) << endl;
	return 0;
}