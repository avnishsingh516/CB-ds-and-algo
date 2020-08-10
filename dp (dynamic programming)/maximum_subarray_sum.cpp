// Maximum Subarray Sum

#include <iostream>
#include <climits>
using namespace std;

//bottom up DP approach
// time and space:- O(n)

int maxSumBU(int a[] , int n) {

	int dp[100] = {0};

	// if first element is -ve add 0 to dp[0]. otherwise, a[0] to the dp[0]
	dp[0] = a[0] > 0 ? a[0] : 0;

	int max_so_far = dp[0];

	for (int i = 1 ; i < n ; i++) {
		dp[i] = dp[i - 1] + a[i];

		//if sum become -ve, then add 0 to dp[i]
		if (dp[i] < 0) {
			dp[i] = 0;
		}

		//find maximum sum
		max_so_far = max(max_so_far, dp[i]);
	}

	return max_so_far;

}

//space optimsed approach , space:- O(1)
//kadane's algo

int kadane(int a[], int n) {

	int currSum = 0;
	int max_so_far = 0;

	for (int i = 0 ; i < n ; i++) {
		currSum += a[i];

		if (currSum < 0) {
			currSum = 0;
		}

		max_so_far = max(max_so_far, currSum);
	}

	//SPECIAL CASE
	if (max_so_far == 0) {
		max_so_far = INT_MIN;

		for (int i = 0 ; i < n ; i++) {
			max_so_far = max(max_so_far, a[i]);
		}
	}

	return max_so_far;
}

//SPECIAL CASE:- if array contains all -ve elements
//the output is the smallest -ve element





int main(int argc, char const *argv[])
{
	int a[] = { -2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(a) / sizeof(int);

	cout << kadane(a, n) << endl;

	return 0;
}