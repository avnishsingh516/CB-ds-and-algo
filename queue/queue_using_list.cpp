#include <iostream>
#include <list> //list refers to doubly linked list
using namespace std;

class Queue {

	int cs; //cs :- current size
	list<int> l;

public:
	Queue() {
		cs = 0;
	}

	bool isEmpty() {
		return cs == 0;
	}

	void push(int data) {
		l.push_back(data);
		cs++;
	}

	void pop() {
		if (!isEmpty()) {
			cs--;
			l.pop_front();
		}
	}

	int front() {
		return l.front();
	}

};

int main(int argc, char const *argv[])
{
	Queue q;

	for (int i = 6 ; i <= 10 ; i++) {
		q.push(i);
	}

	while (!q.isEmpty()) {
		cout << q.front() << " <- ";
		q.pop();
	}

	return 0;
}