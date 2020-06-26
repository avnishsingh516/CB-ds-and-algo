#include<iostream>
using namespace std;

int decimalToBinary(int n) {

	int ans = 0;
	int p = 1;

	while (n > 0) {
		int last_bit = n & 1; //gives the last bit each time
		ans += p * last_bit;

		p *= 10;
		n = n >> 1; //traversing each bit form right to left
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	//given a number N, find no of set bits in binary rep. of it

	int n ;
	cin >> n;
	cout << decimalToBinary(n) << endl;

	return 0;
}