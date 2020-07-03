// reverse the stack using 1 extra stack only
// more efficient than using 2 stack
#include<iostream>
#include <stack>
using namespace std;

//tranfer the values of stack from one stack to another stack
void transfer(stack<int>&s1 , stack<int>&s2 , int n) {
	// n -> gives the no of element we have to tranfer

	for (int i = 0 ; i < n ; i++) {
		s2.push(s1.top());
		s1.pop();
	}
}


//reverse the stack
void reverseStack(stack<int> &s1) {

	stack<int> s2; //only extra stack
	int n = s1.size(); //gives the size of the stack

	for (int i = 0 ; i < n ; i++) {

		int x = s1.top();
		s1.pop();

		transfer(s1, s2, n - i - 1); //here (n-i-1) refers to the no of element we have to tranfer from s1 to s2
		s1.push(x);
		transfer(s2, s1, n - i - 1);
	}
	return;
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
	// while (!s.empty()) {
	// 	cout << s.top() << " ";
	// 	s.pop();
	// }

	// cout << endl;

	reverseStack(s);

	//print after reversing the stack
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	cout << endl;

	return 0;
}