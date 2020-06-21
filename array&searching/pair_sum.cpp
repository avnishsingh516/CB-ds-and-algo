// best approach to find the pair sum ny using "TWO POINTER APPROACH"
// complexity:- O(N)

// only works for sorted array

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	int a[n];

	for (int i = 0 ; i < n ; i++)
		cin >> a[i];

	int s;
	cin >> s;

	int i = 0, j = n - 1;

	while (i < j) {

		int currentsum = a[i] + a[j];

		if (currentsum > s) {
			j--;
		}
		else if (currentsum < s) {
			i++;
		}
		else {
			cout << a[i] << " and " << a[j] << endl;
			i++;
			j--;
		}
	}

	return 0;
}