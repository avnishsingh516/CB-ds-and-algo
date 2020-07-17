#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int arr[9000];
	int n , i , val , diff;

	while (1) {
		//take input current test case
		int max_load = 0, load = 0 ;
		cin >> n;

		//stop taking input if n = -1
		if (n == -1)
			break;

		for (int i = 0 ; i < n; i++) {
			cin >> arr[i];
			load += arr[i];
		}
		//if the load is not divided equally , then -1 is ans
		if (load % n != 0) {
			cout << "-1" << endl;
			continue;
		}

		//find the load that is to be divided equally
		load = load / n;

		diff = 0;
		//greedy step
		for (int i = 0 ; i < n ; i++) {

			//find the difference btw final load to be assigned anad current load
			diff += (arr[i] - load);
			int ans = abs(diff);

			max_load = max(max_load, ans);

		}

		cout << max_load << endl;

	}



	return 0;
}

/*
1.

IP:-
10
0 0 100 0 0 0 0 0 0 0

OP:- 70



2.

IP:-
3
0 99 3
OP:-34

-1

*/