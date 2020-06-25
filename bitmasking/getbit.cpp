#include <bits/stdc++.h>
using namespace std;

// gives the i th bit whether it is 0 or 1
int getbit(int n , int i) {

	int mask = 1 << i ; // if i=2 , 1<<2 = 100 ... if i=5 , 1<<5 = 100000

	//n & mask gives the ith bit is 1 or 0
	int bit = (n & mask) > 0 ? 1 : 0;

	return bit;
}

int main(int argc, char const *argv[])
{
	int n , i;
	cin >> n;
	cin >> i ; //ith bit
	cout << getbit(n , i) << endl;
	return 0;
}