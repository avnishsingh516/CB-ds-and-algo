#include <iostream>
using namespace std;

//bottom up
int solveCellProblem(int n, int x, int y, int z) {
	int dp[100];
	//start case
	dp[0] = dp[1] = 0;

	for (int i = 2 ; i <= n ; i++) {

		// for even i , the dp[i+1] is odd, it always give the more cost because it always from d[i/2] and then extra cost
		if (i % 2 == 0) {
			dp[i] = min(dp[i / 2] + x , dp[i - 1] + y);
		}
		else {
			dp[i] = min(dp[i - 1] + y , dp[(i + 1) / 2] + x + z);
		}
	}
	return dp[n];
}

int main(int argc, char const *argv[])
{
	int n;
	int x, y, z; //cost
	cin >> n >> x >> y >> z;

	cout << solveCellProblem(n, x, y, z) << endl;

	return 0;
}
/*
5
2 1 3
4
*/
