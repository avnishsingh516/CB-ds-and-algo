#include <iostream>
using namespace std;

int fact(int n) {

	//base case
	if (n == 1) {
		// fact of 1 => 1
		return 1;
	}
	// recursive case
	// fact of n => n*fact(n-1)
	return (n * fact(n - 1));
}

int main(int argc, char const *argv[])
{
	int n ;
	cin >> n;

	cout << fact(n) << endl;
	return 0;
}