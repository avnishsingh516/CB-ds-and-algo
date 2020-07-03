// reverse the stack using 2 extra stack only
// less efficient than using 1 stack
#include<iostream>
#include <stack>
using namespace std;

//tranfer the values of stack from one stack to another stack
void transfer(stack<int>&s1 , stack<int>&s2) {

	while (!s1.empty()) {
		s2.push(s1.top());
		s1.pop();
	}
}


//reverse the stack
void reverseStack(stack<int>&s1) {

	stack<int> s2; //1st extra stack
	stack<int> s3; //2nd extra stack

	transfer(s1, s2);
	transfer(s2, s3);
	transfer(s3, s1);

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

	/*while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	cout << endl;
	*/

	reverseStack(s);

	//print after reversing the stack
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	cout << endl;

	return 0;
}