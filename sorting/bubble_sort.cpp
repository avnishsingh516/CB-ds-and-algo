#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int a[] , int n) {

	for (int i = 1 ; i <= n - 1 ; i++) {
		//n-1 large elements to the end

		for (int j = 0 ; j <= (n - i - 1) ; j++) {
			// pairwise sorting in the unsorted array

			if (a[j] > a[j + 1])
				swap(a[j] , a[j + 1]);
		}

	}
}

int main(int argc, char const *argv[])
{
	int n  ;
	cin >> n;
	int a[n];

	for ( int i = 0 ; i < n ; i++)
		cin >> a[i];

	bubble_sort(a, n);

	for ( int i = 0 ; i < n ; i++)
		cout << a[i] << " ";

	return 0;
}