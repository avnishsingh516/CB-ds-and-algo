//reverse the stack using recursion

#include<iostream>
#include <stack>
using namespace std;

//insert the element x at the bottom of the stack
void insertAtBottom(stack<int>&s , int x) {
	//base case
	if (s.empty()) {
		s.push(x);
		return;
	}

	// rec case
	int y = s.top();
	s.pop();
	insertAtBottom(s, x);
	s.push(y);
}

//reverse stack
void reverseStackRec(stack<int>&s) {
	//base case
	if (s.empty()) {
		return;
	}

	//rec case
	int x = s.top();
	s.pop();
	reverseStackRec(s);
	insertAtBottom(s, x);
}

int main(int argc, char const *argv[])
{
	stack<int> s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	//print to see the element before reverse

	/*while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	cout << endl;
	*/

	reverseStackRec(s);

	//print after reversing the stack
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	cout << endl;
	return 0;
}

