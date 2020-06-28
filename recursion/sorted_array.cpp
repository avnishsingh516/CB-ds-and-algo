// check whether array is sorted or not

#include <iostream>
using namespace std;

bool isSorted(int a[] , int n) {
	//base case
	if ( n == 1) {
		//when only 1 element is left in the array
		return true;
	}

	//rec case
	if (a[0] < a[1] and isSorted(a + 1, n - 1)) {
		return true;
	}

	return false;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0 ; i < n ; i++) {
		cin >> arr[i];
	}

	cout << isSorted(arr, n) << endl;
	return 0;
}