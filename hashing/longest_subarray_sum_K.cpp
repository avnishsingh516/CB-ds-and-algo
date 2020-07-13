// find the length of longest subarray with sum k
// time and space :- O(n)

#include <iostream>
#include <unordered_map>
using namespace std;

// Returns Length of the required subarray
int maxLen(int arr[], int n , int k)
{
    // Map to store the previous sums
    unordered_map<int, int> presum;

    int sum = 0; // Initialize the sum of elements
    int max_len = 0; // Initialize result

    // Traverse through the given array
    for (int i = 0; i < n; i++) {
        // Add current element to sum
        sum += arr[i];

        // when subarray starts from index '0'
        if (sum == k)
            max_len = i + 1;

        // Look for this sum in Hash table
        if (presum.find(sum - k) != presum.end()) {
            // If this sum is seen before, then update max_len
            max_len = max(max_len, i - presum[sum - k]);
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

    int k;
    cin >> k;

    cout << maxLen(arr, n , k) << endl;

    return 0;
}

/*
5
1 -1 5 -2 3
3
4
*/