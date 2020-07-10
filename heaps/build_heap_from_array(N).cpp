// Build Heap from Array in O(N) time

#include <iostream>
#include <vector>
using namespace std;



//compare the values for max heap
bool compare(int a, int b) {

	return a > b;

	//for min heap
	return a < b;

}


//makes the heap structure proper again after the poping
void heapify(vector<int> &v, int idx) {
	// find the left and right child of the parent node which is present at idx index
	int left = 2 * idx;
	int right = 2 * idx + 1; //or left+1;

	int min_idx = idx;
	int last_idx = v.size() - 1;

	//check the parent have child or not
	//for present of the child , the child index must be lesser or equal to the last index of heap
	if (left <= last_idx and compare(v[left], v[idx])) {
		min_idx = left;
	}
	if (right <= last_idx and compare(v[right], v[min_idx])) {
		min_idx = right;
	}

	// now , min_idx point to the smallest and swap it with the idx
	if (min_idx != idx) {
		// it is also act as a base case for stoping the heapify recursive call
		swap(v[idx], v[min_idx]);
		//call heapify for smaller part
		heapify(v, min_idx);
	}

}


//build heap from array
void buildHeapOptimised(vector<int> &v) {

	// start the loop from 1st non leaf node from the bottom to the root using bottom up approach

	for (int i = (v.size() - 1) / 2 ; i >= 1 ; i--) {
		heapify(v, i);
	}
}

//print the vector
void print(vector<int> v) {
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	vector<int> v{ -1 , 10, 20, 5, 6, 1, 8, 9, 4}; //heap

	print(v);

	buildHeapOptimised(v);

	print(v);


	return 0;
}