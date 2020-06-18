#include<bits/stdc++.h>
using namespace std;

void selection_sort(int a[] , int n) {

	for (int i = 0 ; i < n - 1 ; i++) {
		//find out the smallest element idx in the unsorted part
		int min_idx = i;
		for (int j = i ; j <= n - 1 ; j++) {
			if (a[j] < a[min_idx])
				min_idx = j;
		}
		// after this loop we can do swaping
		swap(a[i] , a[min_idx]);
	}
}

int main(int argc, char const *argv[])
{
	int n  ;
	cin >> n;
	int a[n];

	for ( int i = 0 ; i < n ; i++)
		cin >> a[i];

	selection_sort(a, n);

	for ( int i = 0 ; i < n ; i++)
		cout << a[i] << " ";

	return 0;
}