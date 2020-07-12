// implement heap operation using array
// we use vector in place of array because we do not worry about the size
//time :- O(logN)
#include<iostream>
#include <vector>
using namespace std;

class Heap {

	vector<int> v;

	//if the user want min heap than bool minHeap is become true , otherwise for max heap it become false
	bool minHeap;

	//compare the values for min or max heap
	bool compare(int a, int b) {
		if (minHeap) {
			return a < b;
		}
		else {
			//for max heap
			return a > b;
		}
	}

	//makes the heap structure proper again after the poping
	void heapify(int idx) {
		// find the left and right child of the parent node which is present at idx index
		int left = 2 * idx + 1;
		int right = 2 * idx + 2; //or left+1;

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
			heapify(min_idx);
		}

	}

public:
	// by default the heap is min heap and its size is 10
	Heap(int default_size = 10 , bool type = true) {
		v.reserve(default_size);

		minHeap = type;
	}

	//push --> insertion
	void push(int data) {

		// index starts from 1st
		v.push_back(data);

		//find index
		int idx = v.size() - 1;

		//find its parent index
		int parent = (idx - 1) / 2;

		// keep pusing to the top till you reach node or stop midway because current element is already greater than parent for min heap and lesser for max heap
		//we use compare function so it can be use for both the cases min heap and max heap
		while (idx > 0 and compare(v[idx], v[parent] )) {
			//swap the child with parent
			swap(v[idx], v[parent]);

			// now, child become parent
			idx = parent;
			parent = (parent - 1) / 2;
		}

	}

	//top --> returns the top most element
	int top() {
		return v[0];
	}

	//pop --> deletion
	void pop() {

		//swap the first and the last element
		int last_idx = v.size() - 1;
		swap(v[0], v[last_idx]);
		//now root node comes to the last
		//so delete it
		v.pop_back();
		// start the heapify the heap at the top of the heap
		heapify(0);
	}

	//returns the heap is empty or not
	bool empty() {
		return v.size() == 0;
	}


};

int main(int argc, char const *argv[])
{
	// by default the heap is min heap

	//for min heap
	// Heap h;

	//for max heap
	Heap h(6, false);

	// give some initial size
	int n;
	cin >> n;

	for (int i = 0 ; i < n; i++) {
		int no;
		cin >> no;
		h.push(no);
	}

	while (!h.empty()) {
		cout << h.top() << " ";
		h.pop();
	}

	cout << endl;

	return 0;
}

/*
I/P:-
6
10 20 15 14 11 90

O/P:-
min heap :- 10 11 14 15 20 90
max heap :- 90 20 15 14 11 10

*/