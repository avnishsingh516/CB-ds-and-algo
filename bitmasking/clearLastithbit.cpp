#include <bits/stdc++.h>
using namespace std;

// clear the  0 to ith bit
void clearLastIbit(int &n , int i) {

	int mask = (-1 << i) ; // if i=2 , -1<<2 = 100 ... if i=5 , 1<<5 = 100000
	// -1 = ~0 = 111111...

	//n & mask clear the 0 to ith bit
	n =  n & mask;


}

int main(int argc, char const *argv[])
{
	int n  , i ;
	cin >> n;
	cin >> i ; //ith bit
	clearLastIbit(n, i);
	cout << n << endl;
	return 0;
}