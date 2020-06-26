#include<bits/stdc++.h>
using namespace std;

/*
finding subsequence/subsets of given a string
input - "abc"
output - " ",a,ab,abc,ac,b,bc,c
*/
void filterchars(int n, char a[]) {

	int j = 0;

	while (n > 0) {
		int last_bit = n & 1;
		if (last_bit) {
			cout << a[j];
		}
		j++;
		n = n >> 1;
	}
	cout << endl;
}

void printSubsets(char a[]) {

	int n = strlen(a);

	for (int i = 0 ; i < (1 << n); i++) {
		//no of subsets in a string of 'abc' is 7 , using n=3 which is no of character in string and no of subsets = 7 using formula 2^n - 1 => 1<<n
		filterchars(i, a);
	}
	return;
}

int main(int argc, char const *argv[])
{
	char a[100];
	cin >> a;
	cout << "subsets :-" << endl;
	printSubsets(a);
	return 0;
}