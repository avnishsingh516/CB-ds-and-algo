// Median in a running stream of integer

#include <iostream>
#include<queue>
using namespace std;

int main(int argc, char const *argv[])
{

	priority_queue<int> leftHeap; //max heap
	priority_queue<int , vector<int> , greater<int> > rightHeap; //min heap

	int data;
	cin >> data; //1st element input

	leftHeap.push(data); //initial state of the heap

	float med = data ; //initialize median with first data
	cout << "median " << med << endl;

	cin >> data; //2nd element input

	// start taking all input elements
	while (data != -1) {
		//logic

		//the size of left heap > right heap
		if (leftHeap.size() > rightHeap.size() ) {

			//if data < current median , it will push in left heap
			if (data < med) {
				//for balacing the heaps we push the previous element which is lesser than median in the right heap
				//the lesser element is present at the top of the left heap
				rightHeap.push( leftHeap.top() );
				//remove that element from the left heap
				leftHeap.pop();
				//then push the new data in left heap
				leftHeap.push(data);
			}
			else {
				// otherwise , the data > current median , it will push in right heap
				//and the heaps balance automatically
				rightHeap.push(data);
			}

			//now the heaps are balanced
			//median is average of the top of the both heaps
			med = (leftHeap.top() + rightHeap.top()) / 2.0;
		}

		//if both the heaps are balanced , then push the data directly to the heap
		else if (leftHeap.size() == rightHeap.size()) {
			//if data < current median , it will push in left heap
			if (data < med) {
				leftHeap.push(data);
				//and the median is equal to top of the left heap
				med = leftHeap.top();
			}
			// otherwise , the data > current median , it will push in right heap
			else {
				rightHeap.push(data);
				//and the median is equal to top of the right heap
				med = rightHeap.top();
			}
		}

		//the size of left heap < right heap
		//now , its the same condition as first condition but the heap is just different
		//so , the heaps will change and the condition remains same
		else {

			if (data > med) {
				leftHeap.push(rightHeap.top());
				rightHeap.pop();
				rightHeap.push(data);
			}
			else {
				leftHeap.push(data);
			}

			med = (leftHeap.top() + rightHeap.top()) / 2.0;

		}

		cout << "median " << med << endl;

		cin >> data; //3rd element and so on ....

	}
	cout << endl;

	return 0;
}

/*

1
median 1
1
median 1
5
median 1
4
median 2.5
3
median 3
0
median 2
0
median 1
-1

*/

// same input but differernt way
/*

1 1 5 4 3 0 0 -1
median 1
median 1
median 1
median 2.5
median 3
median 2
median 1

*/