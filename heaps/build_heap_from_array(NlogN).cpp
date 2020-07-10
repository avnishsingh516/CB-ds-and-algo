// Build Heap from Array in O(NLogN)

#include <iostream>
#include <vector>
using namespace std;

//build heap from array
void buildHeap(vector<int> &v) {
	// root is present at index 1 , so start loop from 2
	for (int i = 2 ; i < v.size(); i++) {
		int idx = i;
		int parent = i / 2;

		while (idx > 1 and v[idx] > v[parent]) {
			// we are making max heap
			//for making min heap just change the sign v[idx]<v[parent]
			swap(v[idx], v[parent]);
			idx = parent;
			parent = parent / 2;
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
	vector<int> v{ -1 , 10, 20, 5, 6, 1, 8, 9, 4}; //heap

	print(v);

	buildHeap(v);

	print(v);


	return 0;
}