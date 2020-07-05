#include<iostream>
#include <stack>
using namespace std;

template<typename T>

class Queue {

	stack<T> s1, s2;

public:

	void push(T data) {
		s1.push(data);
	}

	void pop() {
		if (s1.empty()) {
			return;
		}

		while (s1.size() > 1) {
			T element = s1.top();
			s2.push(element);
			s1.pop();
		}

		//remove the last element
		s1.pop();

		//swap the s1 and s2
		while (!s2.empty()) {
			T element = s2.top();
			s1.push(element);
			s2.pop();
		}

	}

	T front() {

		while (s1.size() > 1) {
			T element = s1.top();
			s2.push(element);
			s1.pop();
		}

		T element = s1.top();
		s2.push(element);
		s1.pop();

		while (!s2.empty()) {

			s1.push(s2.top());
			s2.pop();
		}

		return element;

	}

	int size() {
		return s1.size() + s2.size();
	}

	bool empty() {
		return size() == 0;
	}

};

int main(int argc, char const *argv[])
{

	Queue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);


	while (!q.empty()) {
		cout << q.front() << " <- ";
		q.pop();
	}

	return 0;
}