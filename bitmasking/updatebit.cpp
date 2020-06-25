#include <bits/stdc++.h>
using namespace std;

void updatebit(int &n , int i , int v) {
	//clear bit
	int mask = ~(1 << i);
	int cleared_n = n & mask;

	//update bit
	n = cleared_n | (v << i); //if v=0,i=1 then v<<i , 00 and if v=1,i=2 then v<<i , 100

}

int main(int argc, char const *argv[])
{
	int n , i , v;
	cin >> n;
	cin >> i ; //ith bit
	cin >> v; // changing bit
	updatebit(n, i , v);
	updatebit(n, i , v);
	cout << n << endl;
	return 0;
}