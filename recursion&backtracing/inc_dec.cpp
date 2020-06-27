#include <iostream>
using namespace std;

//print no in dec order
void dec(int n) {

	//base case
	if (n == 0) {
		return;
	}

	//rec case
	cout << n << " ";
	dec(n - 1);
}

//print no in inc order
void inc(int n) {

	//base case
	if (n == 0) {
		return;
	}

	//rec case
	inc(n - 1);
	cout << n << " ";

}
int main() {
	int n = 5;
	dec(n);
	cout << endl;
	inc(n);
	return 0;
}
