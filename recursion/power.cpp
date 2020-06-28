#include <iostream>
using namespace std;

//compute a^n

//time:- O(n)
int power(int a, int n ) {

	//base case
	if (n == 1) {
		return a;
	}

	//rec case
	return a * power(a, n - 1);
}

// time:- O(logn)
//ex:- 2^8 => power is even . therefore , 2^8 => (2^4)*(2^4) , 2^4 => (2^2)*(2^2) , 2^2 => (2^1)*(2^1) , 2^1 => return a =2
//ex:- 2^9 => power is odd . therefore , find 2^8 and multiply it with 2
int fast_power(int a, int n) {

	//base case
	if (n == 1) {
		return a;
	}

	//rec case
	int smaller_ans = fast_power(a, n / 2);
	smaller_ans *= smaller_ans;

	if (n & 1) {
		// n is odd
		return smaller_ans * a;
	}

	return smaller_ans;
}

int main() {

	int a , n  ;
	cin >> a >> n;
	cout << power(a, n) << endl;
	cout << fast_power(a, n) << endl;

	return 0;
}
