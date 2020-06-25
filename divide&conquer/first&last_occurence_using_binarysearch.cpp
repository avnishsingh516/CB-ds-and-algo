#include <iostream>
using namespace std;

int first_occurence(int a[] , int n , int key) {

	int s = 0;
	int e = n - 1;

	int ans = -1;

	//update in a direction that ans values gets lower and lower
	while (s <= e) {
		int mid = (s + e) / 2;

		if (a[mid] == key) {
			//Do two things,
			ans = mid;
			e = mid - 1; //dont stop but explore the left part of the array
		}
		else if (a[mid] > key) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}

	return ans;
}

int last_occurence(int a[] , int n , int key) {

	int s = 0;
	int e = n - 1;

	int ans = -1;

	//update in a direction that ans values gets higher and higher
	while (s <= e) {
		int mid = (s + e) / 2;

		if (a[mid] == key) {
			//Do two things,
			ans = mid;
			s = mid + 1; //dont stop but explore the right part of the array
		}
		else if (a[mid] > key) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	int arr[] = {1, 2, 5, 8, 8, 8, 8, 8, 10, 12, 15, 20};
	int n = sizeof(arr) / sizeof(int);

	int key;
	cin >> key;

	//First and last occurence of a key in sorted array
	cout << first_occurence(arr, n, key) << endl;
	cout << last_occurence(arr, n, key) << endl;

	return 0;
}