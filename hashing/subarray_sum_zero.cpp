// Check Subarray With Sum Zero
// time complexity:- O(n)
// https://www.geeksforgeeks.org/find-if-there-is-a-subarray-with-0-sum/
#include <iostream>
#include <unordered_set>
using namespace std;

bool checkIfSubarrayWithSumZero(int *arr , int n) {
	unordered_set<int> s;

	int pre = 0;

	// Traverse through array and store prefix sums
	for (int i = 0 ; i < n ; i++) {
		pre += arr[i];

		// If prefix sum is 0 or it is already present
		if (pre == 0 or s.find(pre) != s.end()) {
			return true;
		}
		s.insert(pre);
	}

	return false;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	int *arr = new int[n];

	for (int i = 0 ; i < n ; i++) {
		cin >> arr[i];
	}

	bool b = checkIfSubarrayWithSumZero(arr , n);

	b == 0 ? cout << "NO\n" : cout << "Yes\n";

	return 0;
}

/*
5
6 -1 2 1 -1
Yes

5
-3 2 3 1 6
NO
*/