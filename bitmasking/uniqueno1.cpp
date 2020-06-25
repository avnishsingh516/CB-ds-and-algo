#include <bits/stdc++.h>
using namespace std;
int main() {

	// Problem :- unique no 2N+1
	//given a list of no where every no occurs twice one , find a unique no (which only occurs once)

	int n;
	cin >> n;

	int no;
	int ans = 0;

	//Bitwise XOR operator
	// helped to not any storage

	for (int i = 0 ; i < n ; i++) {
		cin >> no;

		ans = ans ^ no; // ^ this is XOR operator
		//no ^ no =0 and no ^ no ^ 1 = 1 by this we can find the unique no

	}

	cout << ans << endl;



	return 0;
}
