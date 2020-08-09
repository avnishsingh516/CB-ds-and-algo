// time:- O(n+k) , where k<<<n therefore, => O(n)

#include <iostream>
using namespace std;

int ladders_optimised(int n, int k) {
	int dp[100] = {0};

	dp[0] = dp[1] = 1; //start case

	//when i-k<=0 or i<=k , initial window
	for (int i = 2 ; i <= k ; i++) {
		dp[i] = 2 * dp[i - 1];
	}

	//all cases , i>k
	for (int i = k + 1 ; i <= n ; i++) {
		dp[i] = 2 * dp[i - 1] - dp[i - 1 - k];
	}

	return dp[n];
}

int main(int argc, char const *argv[])
{
	int n = 4, k = 3;
	// cin>>n>>k;

	cout << ladders_optimised(n, k) << endl;

	return 0;
}