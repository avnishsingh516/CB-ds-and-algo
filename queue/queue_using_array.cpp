#include<iostream>
using namespace std;

class Queue {

	int *arr;
	int front , rear , curr_size , max_size;

public:
	//constructor with default size of the queue is 5
	Queue(int default_size = 5) {
		arr = new int[default_size];
		curr_size = 0;
		max_size = default_size;
		front = 0;
		rear = max_size - 1;
	}

	// it returns whether the queue is full or not
	bool full() {
		return curr_size == max_size;
	}
	// it returns whether the queue is empty or not
	bool empty() {
		return curr_size == 0;
	}

	// push the data in the queue at the rear end
	void push(int data) {
		if (!full()) {
			rear = (rear + 1) % max_size;
			arr[rear] = data;
			curr_size++;
		}
	}
	// pop the data from the queue at the front
	void pop() {
		if (!empty()) {
			front = (front + 1) % max_size;
			curr_size--;
		}
	}
	// returns th data in the queue at the front
	int check_front() {
		return arr[front];
	}

	//destructor
	~Queue() {
		if (arr != NULL) {
			delete [] arr;
			arr = NULL;
		}
	}

};

int main(int argc, char const *argv[])
{
	Queue q(10);

	for (int i = 1; i <= 6; i++) {
		q.push(i);
	}

	q.pop();
	q.pop();

	q.push(7);

	while (!q.empty()) {
		cout << q.check_front() << endl;
		q.pop();
	}


	return 0;
}