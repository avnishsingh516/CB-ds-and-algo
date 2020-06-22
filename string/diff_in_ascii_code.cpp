#include<bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;

	int len = str.length() - 1 ;
	for (int i = 0 ; i < len ; i++) {
		int diff = str[i + 1] - str[i];
		cout << str[i] << diff;
	}
	cout << str[len] << endl;
	return 0;
}