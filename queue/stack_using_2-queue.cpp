#include <iostream>
#include <queue>
using namespace std;

template<typename T>

class Stack {

	queue<T> q1, q2;

public:

	void push(T x) {
		q1.push(x);
	}

	void pop() {
		//remove the last added element from q1
		//we have to move first n-1 elements in q2
		//interchange the names of q1 and q2

		if (q1.empty()) {
			return;
		}

		while (q1.size() > 1) {
			T element = q1.front();
			q2.push(element);
			q1.pop();
		}

		//remove the last element
		q1.pop();

		//swap the names of q1 and q2
		swap(q1, q2);

	}

	T top() {
		while (q1.size() > 1) {
			T element = q1.front();
			q2.push(element);
			q1.pop();
		}

		//1 element in q1 , which is top element
		T element = q1.front();
		q2.push(element);
		q1.pop();

		swap(q1, q2);

		return element;

	}

	int size() {
		return q1.size() + q2.size();
	}

	bool empty() {
		return (size() == 0);
	}

};

int main(int argc, char const *argv[])
{
	Stack<int> s;
	s.push(10);
	s.push(16);
	s.push(18);
	s.push(11);
	s.push(100);

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}

	return 0;
}