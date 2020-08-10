// bottom up dp approach
// time:- O(n^2)
// https://youtu.be/vL8QpCpNNiY

#include <iostream>
using namespace std;

int lis(int arr[100], int n) {
	int dp[100];

	//base case
	for (int i = 0; i < n; i++) dp[i] = 1;

	int best = -1;

	for (int i = 1 ; i < n ; i++) {
		for (int j = 0 ; j < i ; j++) {

			if (arr[j] <= arr[i]) {
				// jth element can be absorbed by ith element
				int currLen = 1 + dp[j];
				dp[i] = max(currLen, dp[i]);
			}
		}

		best = max(best, dp[i]);
	}

	return best;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int arr[100];

	for (int i = 0 ; i < n ; i++)
		cin >> arr[i];

	cout << lis(arr, n) << endl;

	return 0;
}
/*
IP:-
10
10 22 9 33 21 50 41 60 80 6

OP:-
6
*/


// refer gfg also for better complexity