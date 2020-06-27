#include<iostream>
using namespace std;

// fib no :- 0 1 1 2 3 5 8 13 21 34
//input no:- 0 1 2 3 4 5 6 7  8  9

int fib(int n) {
	//base case
	if (n == 0 or n == 1) {
		return n;
	}

	//rec case
	int f1 = fib(n - 1);
	int f2 = fib(n - 2);

	return f1 + f2;
}

int main(int argc, char const *argv[])
{
	int n ;
	cin >> n;

	cout << fib(n) << endl;
	return 0;
}