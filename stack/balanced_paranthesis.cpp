#include<iostream>
#include <stack>
using namespace std;

bool balanced(string str) {

	stack<char> s;

	for (int i = 0 ; str[i] != '\0' ; i++) {
		if (str[i] == '(') {
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			if (s.empty() or s.top() != '(') {
				return false;
			}
			s.pop();
		}
	}

	return s.empty();
}

int main(int argc, char const *argv[])
{
	string str;
	cin >> str;

	cout << balanced(str) << endl;
	return 0;
}