#include<iostream>
using namespace std;

//sorted array only
int binarySearch(int *arr , int fi , int li , int key) {

	if (fi <= li) {
		int mid = (fi + li) / 2;

		if (arr[mid] == key) {
			//element found at mid
			return mid;
		}

		// If element is smaller than mid, then it can only be present
		// in left subarray
		if (arr[mid] > key) {
			return binarySearch(arr, fi, mid - 1, key);
		}
		else {
			// Else the element can only be present in right subarray
			return binarySearch(arr, mid + 1, li, key);
		}
	}
	//search is over and element not found
	return -1;
}

int main(int argc, char const *argv[])
{
	int n;  //sie of array
	cin >> n;

	int key; //finding element
	cin >> key;

	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int fi = 0; //first index
	int li = n - 1; //last index

	cout << binarySearch(arr, fi, li, key) << endl;

	return 0;
}