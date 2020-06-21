// complexity :- O(N)

// Approach :- at the end the of the code




#include<bits/stdc++.h>
using namespace std;
// Standard Kadane's algorithm to find maximum subarray sum
int kadane(int a[], int n);

// The function returns maximum circular contiguous sum in a[]
int maxCircularSum(int a[], int n)
{
// Case 1: get the maximum sum using standard kadane's algorithm
	int max_kadane = kadane(a, n);

// Case 2: Now find the maximum sum that includes
// corner elements.
	int max_wrap = 0, i;
	for (i = 0; i < n; i++)
	{
		max_wrap += a[i];     // Calculate array-sum
		a[i] = -a[i];       // invert the array (change sign)
	}

// max sum with corner elements will be:
// array-sum - (-max subarray sum of inverted array)
	max_wrap = max_wrap + kadane(a, n);

// The maximum circular sum will be maximum of two sums
	return (max_wrap > max_kadane) ? max_wrap : max_kadane;
}

// Standard Kadane's algorithm to find maximum subarray sum
int kadane(int a[], int n)
{
	int max_so_far = 0, max_ending_here = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		max_ending_here = max_ending_here + a[i];
		if (max_ending_here < 0)
			max_ending_here = 0;
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;
	}
	return max_so_far;
}

/* Driver program to test maxCircularSum() */
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		int a[n];
		for (int j = 0; j < n; j++)
		{
			cin >> a[j];
		}
		cout << maxCircularSum(a, n) << endl;
	}
	return 0;
}






// Approach :-

// For finding the Maximum Contiguous sum we are using the kadane's algorithm.
// But in the question the array is circular that means the maximum sum can be of elements which are a part of the wrapping or not.
// So, There can be two cases for the maximum sum:

// Case 1:- The elements that contribute to the maximum sum are arranged such that no wrapping is there.
// Examples: {-10, 2, -1, 5}, {-2, 4, -1, 4, -1}. In this case, Kadane’s algorithm will produce the result.

// Case 2:- The elements which contribute to the maximum sum are arranged such that wrapping is there.
// Examples: {10, -12, 11}, {12, -5, 4, -8, 11}. In this case, we change wrapping to non-wrapping.
// Let us see how. Wrapping of contributing elements implies non wrapping of non contributing elements,
// so find out the sum of non contributing elements and subtract this sum from the total sum.
// To find out the sum of non contributing, invert sign of each element and then run Kadane’s algorithm.
// Our array is like a ring and we have to eliminate the maximum continuous negative that implies maximum continuous positive in the inverted arrays.

// video link:- https://www.youtube.com/watch?v=Q1TYVUEr-wY