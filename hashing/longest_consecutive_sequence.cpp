// Longest Consecutive Subsequence
// time and space:- O(n)

// https://www.geeksforgeeks.org/longest-consecutive-subsequence/
#include<iostream>
#include <unordered_set>
using namespace std;

int lonSeq(int arr[] , int n) {
	unordered_set<int> s;

	//insert the element in the set
	for (int i = 0 ; i < n ; i++) {
		s.insert(arr[i]);
	}

	int ans = 0;

	for (int i = 0 ; i < n ; i++) {
		//s.find() returns the address of that value if it was found .
		// otherwise , it returns the s.end() iterator

		// if the keys previous value is found it means its already counted
		//else we count its streak length
		if (s.find(arr[i] - 1) != s.end()) {
			//its prev present
			continue;
		}
		//its prev not found
		else {
			int count = 0;
			int x = arr[i]; //left bound

			//count the lenght of its streak
			while (s.find(x) != s.end()) {
				count++;
				x++;
			}

			ans = max(ans, count);
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	int arr[n];

	for (int i = 0 ; i < n ; i++) {
		cin >> arr[i];
	}

	int ans = lonSeq(arr, n);
	cout << ans << endl;


	return 0;
}
/*
6
10 3 20 1 2 4
4
*/