// counting no of 1 bit in a no

#include<bits/stdc++.h>
using namespace std;
// first method
// time:- O(LogN)+1
int countbits(int n) {
	int ans = 0;
	while (n > 0) {
		ans += (n & 1); // gives the last bit every time and add to ans
		n = n >> 1; //by right shift 1 ,we get next times the next bit of the no towards right
	}

	return ans;
}
//second method - optimised method
// time:- O(no of set bit)
int countbitsfast(int n) {
	int ans = 0 ;
	while (n > 0) {
		//it do and bitwise operation with the no and the prev no
		// in results , last set bit or 1 bit get remove each time
		// and the no of times while loop runs gives the ans
		n = n & (n - 1);
		ans++;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	//Given a no N , find no of set bits in binary rep. of it
	// N=13 , Binary = 1101 , Output = 3

	int n ; //13
	cin >> n;
	cout << countbits(n) << endl; //3
	cout << countbitsfast(n) << endl;
	cout << __builtin_popcount(n) << endl; //it is a builtin func in gcc compiler , to count the no of set bits or no of 1 bit

	return 0;
}