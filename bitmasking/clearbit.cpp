#include <bits/stdc++.h>
using namespace std;

// clear the i th bit whether it is 0 or 1 to 0
void clearbit(int &n , int i) {

	int mask = ~(1 << i) ; // if i=2 , 1<<2 = 011 ... if i=5 , 1<<5 = 011111

	//n & mask clear the ith bit to 0
	n = n & mask;
}

int main(int argc, char const *argv[])
{
	int n , i;
	cin >> n;
	cin >> i ; //ith bit
	clearbit(n, i);
	cout << n << endl;
	return 0;
}