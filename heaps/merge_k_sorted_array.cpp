// https://www.geeksforgeeks.org/merge-k-sorted-arrays-set-2-different-sized-arrays/
#include <bits/stdc++.h>
using namespace std;

// A pair of pairs, first element is going to
// store value, second element index of array
// and third element index in the array.
typedef pair<int, pair<int, int> > node;

// This function takes an array of arrays as an
// argument and all arrays are assumed to be
// sorted. It merges them together and prints
// the final sorted output.
vector<int> mergeKArrays(vector<vector<int> > arr)
{
    vector<int> output;

    // Create a min heap with k heap nodes. Every
    // heap node has first element of an array
    priority_queue<node, vector<node>, greater<node> > pq; //min heap

    // insert the 0th element of every array in heap
    for (int i = 0; i < arr.size(); i++)
        pq.push({ arr[i][0], { i, 0 } });

    // Now one by one get the minimum element
    // from min heap and replace it with next
    // element of its array
    while (pq.empty() == false) {
        node curr = pq.top();
        pq.pop();

        // i ==> Array Number
        // j ==> Index in the array number
        int i = curr.second.first;
        int j = curr.second.second;

        // removed element add to the result vector
        //curr.first is the element
        output.push_back(curr.first);

        // The next element belongs to same array as
        // current.
        if (j + 1 < arr[i].size())
            pq.push({ arr[i][j + 1], { i, j + 1 } });
    }

    return output;
}

// Driver program to test above functions
int main()
{
    // Change n at the top to change number
    // of elements in an array
    vector<vector<int> > arr{ { 2, 6, 12 },
        { 1, 9 },
        { 23, 34, 90, 2000 },
        { 1, 3, 8, 14, 20} };

    vector<int> output = mergeKArrays(arr);

    cout << "Merged array is " << endl;
    for (auto x : output)
        cout << x << " ";

    return 0;
}