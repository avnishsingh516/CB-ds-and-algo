// Build Heap from Array in O(NLogN)

#include <iostream>
#include <vector>
using namespace std;

//build heap from array
void buildHeap(vector<int> &v) {
	// root is present at index 0 , so start loop from 1
	for (int i = 1 ; i < v.size(); i++) {
		int idx = i;
		int parent = (i - 1) / 2;

		while (idx > 0 and v[idx] > v[parent]) {
			// we are making max heap
			//for making min heap just change the sign v[idx]<v[parent]
			swap(v[idx], v[parent]);
			idx = parent;
			parent = (parent - 1) / 2;
		}
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
	vector<int> v{ 10, 20, 5, 6, 1, 8, 9, 4}; //heap

	print(v);

	buildHeap(v);

	print(v);


	return 0;
}