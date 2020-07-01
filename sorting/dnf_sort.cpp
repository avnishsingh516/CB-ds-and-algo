#include <iostream>
using namespace std;

void dnf_sort(int a[] , int n) {

	//sort array of 0s , 1s and 2s
	int low = 0 ;
	int high = n - 1;
	int mid = 0;

	while (mid <= high) {

		if (a[mid] == 0) {
			swap(a[mid], a[low]);
			mid++;
			low++;
		}
		if (a[mid] == 1) {
			mid++;
		}
		if (a[mid] == 2) {
			//a[mid]==2
			swap(a[mid], a[high]);
			high--;
		}
	}

	return;
}

int main(int argc, char const *argv[])
{
	int n , a[100];
	cin >> n;

	for (int i = 0 ; i < n ; i++) {
		cin >> a[i];
	}

	dnf_sort(a, n);

	for (int i = 0 ; i < n ; i++) {
		cout << a[i] << " ";
	}

	return 0;
}