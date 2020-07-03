// implementation of stack using vector

#include <iostream>
#include <vector>
using namespace std;

template<typename T>

class stack {

	vector<T> v;

public:

	void push(T data) {
		v.push_back(data);
	}

	bool empty() {
		return v.size() == 0;
	}

	void pop() {

		if (!empty()) {
			v.pop_back();
		}
	}

	T top() {
		return v[v.size() - 1];
	}

};

int main(int argc, char const *argv[])
{
	stack<char> s;

	for (int i = 65 ; i <= 70; i++) {
		s.push(i);
	}

	//try to print the content of the stack by poping each element
	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}

	return 0;
}