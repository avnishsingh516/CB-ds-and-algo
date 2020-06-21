#include <bits/stdc++.h>
using namespace std;

void park(char a[][100] , int n , int m , int k , int s) {

	// "." energy is reduced by 2
	// "*" energy is increased by 5
	// "#" blocked path
	// every step taken forward reduced the energy by 1
	// except at the time of changing the row or en dof the row


	// piyush can get out of the mark
	bool success = true;

	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < m ; j++) {

			char ch = a[i][j];

			// check is energy sufficient to cross the park
			if (s < k) {
				// success = false;
				cout << "No" << endl;  //or break;
				return;
			}
			if (ch == '*') {
				s += 5;
			}
			else if (ch == '.') {
				s -= 2;
			}
			else {
				// for '#'
				break;
			}

			//we also loose 1 point when we move right except for the last col
			if (j != n - 1) {
				s--;
			}
		}
	}

	if (success) {
		cout << "Yes" << endl;
		cout << s << endl;
	}
	// else {
	// 	cout << "No" << endl;
	// }

}

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	int k ;//min enery req to cross the park (threshold energy)
	int s ; //initial energy given to piyush (energy)

	cin >> k >> s;

	char a[100][100];

	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < m ; j++) {
			cin >> a[i][j];
		}
	}

	park(a , n , m , k , s );
	return 0;
}