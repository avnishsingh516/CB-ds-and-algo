#include<iostream>
using namespace std;

// approach is based on binary search

int find(int a[] , int n, int key) {
	int s = 0;
	int e = n - 1;

	while (s <= e) {
		int mid = (s + e) / 2;

		if (a[mid] == key) {
			return mid;
		}
		else if (a[s] <= a[mid]) {
			//2 cases -> element lies on the left or the right of the mid

			if (key >= a[s] and key <= a[mid]) {
				e = mid - 1;
			}
			else {
				s = mid + 1;
			}
		}
		else {
			if (key >= a[mid] and key <= a[e]) {
				s = mid + 1;
			}
			else {
				e = mid - 1;
			}
		}
	}

	return -1;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0 ; i < n ; i++) {
		cin >> arr[i];
	}
	int key;
	cin >> key;

	cout << find(arr , n , key) << " index " << endl;
	return 0;
}