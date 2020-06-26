#include<iostream>
using namespace std;

// Replace Bits in N by M

/*
You are given two 32-bit no , N and M , and two bit postions , i and j.
Write a method to set all bits between i and j in N equal
to M (e.g., M becomes a substring of N located at i and starting at j).

example in bits :-
input: N = 10000000000
M = 10101 ,i =2 , j = 6
output: N = 10001010100
*/

// clear the ith to jth bit
int clearRangeItoJbit(int n , int i , int j) {

	int ones = ~0; //or -1 => 1111...
	int a = ones << (j + 1); // gives 0 from 0th to jth bit ,therefore we used j+1
	int b = (1 << i) - 1; //2^i-1 => gives 1 from 0th index to ith
	int mask = a | b;
	int ans = n & mask;
	return ans;

}

int replaceBits(int n , int m, int i, int j) {
	int n_ = clearRangeItoJbit(n, i, j); //get clear bits from i to j bits
	int ans = n_ | (m << i); //gives zero upto ith bit and after that m bits => (m<<i)
	return ans;
}

int main(int argc, char const *argv[])
{
	int n = 15;
	int i = 1, j = 3;
	int m = 2;

	cout << replaceBits(n, m, i, j) << endl;

	return 0;
}