#include <bits/stdc++.h>
using namespace std;

void isevenORodd(int n) {

	if (n & 1) {
		//n&1 = 1 , then it is odd because it give last bit = 1 and other bits =0
		cout << "odd" << endl;
	}
	else {
		//n&1 = 0 , then it is even because it give all bits = 0
		cout << "even" << endl;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	isevenORodd(n);
	return 0;
}