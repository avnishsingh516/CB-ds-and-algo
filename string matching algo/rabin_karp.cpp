// https://www.youtube.com/watch?v=ak-RkHvknO0

// best and avg time complexity:- O(n+m)
// worst time complexity:- O(n*m)


#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define prime 119

//ROLLING HASH FUNCTION
//O(m)
ll createHashValue(string str, int n) {
	ll result = 0;
	for (int i = 0; i < n; i++) {
		result += str[i] * pow(prime , i);
	}
	return result;
}

// O(1)
ll reCalHash(string str, int oldIndex, int newIndex, ll oldHash, int patLen) {
	ll newHash = oldHash - str[oldIndex];
	newHash /= prime;
	newHash += str[newIndex] * pow(prime, patLen - 1);
	return newHash;
}
// CHECH THE STRING CHARACTER BY CHARACTER
bool check(string str1, string str2, int start1, int end1, int start2, int end2) {
	if (end1 - start1 != end2 - start2) {
		return false;
	}

	while (start1 <= end1 and start2 <= end2) {
		if (str1[start1] != str2[start2]) {
			return false;
		}
		start1++;
		start2++;
	}

	return true;
}

int main(int argc, char const *argv[])
{
	string str = "ababdcabdab";
	string pat = "abd";

	ll patHash = createHashValue(pat, pat.length());
	ll strHash = createHashValue(str, pat.length());

	for (int i = 0 ; i <= str.length() - pat.length(); i++) {
		if (patHash == strHash and check(str, pat, i, i + pat.length() - 1, 0, pat.length() - 1 )) {
			cout << "pattern found at " << i << endl;

		}
		if (i < str.length() - pat.length()) {
			strHash = reCalHash(str, i, i + pat.length(), strHash, pat.length());
		}
	}

	return 0;
}