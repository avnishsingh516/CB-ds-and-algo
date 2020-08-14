#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100005
int reset[MAX_N];

void KMPpreprocess(string pat) {
	int i = 0, j = -1;
	reset[0] = -1;

	while (i < pat.size()) {
		//check for resetting
		while (j >= 0 and pat[i] != pat[j]) {
			j = reset[j];
		}

		i++;
		j++;
		reset[i] = j;
	}
}

void KMPsearch(string str, string pat) {
	// make or fill the reset array
	KMPpreprocess(pat);

	int i = 0 , j = 0;
	while (i < str.size()) {
		while (j >= 0 and str[i] != pat[j]) {
			j = reset[j];
		}

		i++;
		j++;

		if (j == pat.size()) {
			cout << "Pattern is found at " << i - j << endl;
			j = reset[j];
		}
	}
}

int main(int argc, char const *argv[])
{
	memset(reset, -1, sizeof(reset));
	string str, pat;
	str = "abbabababbbabacdbaba";
	pat = "aba";
	KMPsearch(str, pat);
	return 0;
}