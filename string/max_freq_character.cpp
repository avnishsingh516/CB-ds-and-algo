// time complexity :- O(N)
// space:- O(N)

#include<bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;

	int len = str.length() - 1;
	int freq[256] = {0};

	for (int i = 0 ; i <= len ; i++) {
		freq[str[i]]++;
	}
	int ans = 0;
	char ch;
	for (int i = 0 ; i < 256 ; i++) {
		if (freq[i] > ans) {
			ans = freq[i];
			ch = char(i);
		}
	}
	cout << ch << endl;
	return 0;
}