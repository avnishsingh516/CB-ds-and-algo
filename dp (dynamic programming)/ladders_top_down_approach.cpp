// Ladders Top Down
// time:- O(nk) and space:- O(n)

#include<iostream>
using namespace std;

int ladders(int n, int k, int dp[]) {

	//base case
	if (n == 0) {
		return 1;
	}

	//dp lookup case
	if (dp[n] != 0) {
		return dp[n];
	}

	//rec case
	int ways = 0;
	for (int i = 1 ; i <= k ; i++) {
		//dont count the -ve
		if (n - i >= 0) {
			ways += ladders(n - i, k, dp);
		}
	}

	return dp[n] = ways;
}


int main(int argc, char const *argv[])
{
	int n = 4, k = 3;
	// cin>>n>>k;
	int dp[1000] = {0};

	cout << "ways:- " << ladders(n, k, dp) << endl;

	return 0;
}