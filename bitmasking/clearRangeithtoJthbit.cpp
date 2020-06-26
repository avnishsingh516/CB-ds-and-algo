#include <bits/stdc++.h>
using namespace std;

// clear the ith to jth bit
void clearRangeItoJbit(int &n , int i , int j) {

	int ones = ~0; //or -1 => 1111...
	int a = ones << (j + 1); // gives 0 from 0th to jth bit ,therefore i used j+1
	int b = (1 << i) - 1; //2^i-1 => gives 1 from 0th index to ith
	int mask = a | b;
	n = n & mask;

}

int main(int argc, char const *argv[])
{
	int n  , i , j ;
	cin >> n;
	cin >> i >> j; //i+1th and jth bit
	clearRangeItoJbit(n, i , j);
	cout << n << endl;
	return 0;
}