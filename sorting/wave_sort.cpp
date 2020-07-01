#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n , a[100];
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	//wave sort
	for (int i = 0; i < n; i += 2)
	{
		//prev element
		if ( i != 0 and a[i] < a[i - 1]) {
			swap(a[i], a[i - 1]);
		}

		//next element
		if (i != n - 1 and a[i] < a[i + 1]) {
			swap(a[i], a[i + 1]);
		}
	}

	for (int i = 0 ; i < n ; i++) {
		cout << a[i] << " ";
	}

	cout << endl;

	return 0;
}

// input:-
// 6
// 1 3 4 2 7 8

// output:-
// 3 1 4 2 8 7
