#include <bits/stdc++.h>
using namespace std;

// set the i th bit to the 1
int setbit(int n , int i) {

	int mask = 1 << i ; // if i=2 , 1<<2 = 100 ... if i=5 , 1<<5 = 100000

	//n | mask set the ith bit to 1
	// | this is OR bitwise operator
	int ans = n | mask ;
	//if the ith bit is already 1 then it donot change the value
	//if its not 1 and its is 0 the the ith bit of 0 is replaced by 1 and the no is changed

	return ans;
}

int main(int argc, char const *argv[])
{
	int n , i;
	cin >> n;
	cin >> i ; //ith bit
	n = setbit(n, i);
	cout << n << endl;
	return 0;
}