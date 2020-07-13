// find the length of longest subarray with sum 0
// time and space :- O(n)

#include <iostream>
#include <unordered_map>
using namespace std;

// Returns Length of the required subarray
int maxLen(int arr[], int n )
{
    // Map to store the previous sums
    unordered_map<int, int> presum;

    int sum = 0; // Initialize the sum of elements
    int max_len = 0; // Initialize result

    // Traverse through the given array
    for (int i = 0; i < n; i++) {
        // Add current element to sum
        sum += arr[i];

        if (arr[i] == 0 && max_len == 0)
            max_len = 1;

        // when subarray starts from index '0'
        if (sum == 0)
            max_len = i + 1;

        // Look for this sum in Hash table
        if (presum.find(sum) != presum.end()) {
            // If this sum is seen before, then update max_len
            max_len = max(max_len, i - presum[sum]);
        }
        else {
            // Else insert this sum with index in hash table
            presum[sum] = i;
        }
    }

    return max_len;
}


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }


    cout << maxLen(arr, n) << endl;

    return 0;
}

/*
8
15 -2 2 -8 1 7 10 23
5
*/