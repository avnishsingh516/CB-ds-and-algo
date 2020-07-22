#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	int diff; //max difference the chopsticks have
	cin >> diff;

	int arr[n];

	for (int i = 0 ; i < n ; i++) {
		cin >> arr[i];
	}

	//sorting
	sort(arr, arr + n);

	int pair = 0;
	int i = 1;
	while (i < n) {
		//find the difference btw 2 chopsticks
		int d = abs(arr[i] - arr[i - 1]);

		if (d <= diff) {
			pair++;
			i = i + 2;
		}
		else {
			i++;
		}
	}

	cout << pair << endl;

	return 0;
}
/*
IP:-
5 2
1 3 3 9 4

OP:-
2
*/
