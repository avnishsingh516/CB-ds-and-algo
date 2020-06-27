#include <iostream>
using namespace std;

int linear(int *a , int n , int key) {

	//base case
	if (n == 0) {
		//if size of array become 0 , it means array is not found
		return -1;
	}

	//rec case
	if (a[0] == key) {
		//if the element is found , it found at index 0 , return 0
		return 0;
	}

	int i = linear(a + 1, n - 1, key);

	if (i == -1) {
		//element not found
		return -1;
	}

	return i + 1; //prev index + 1;
}

//different style of writing same function
//inefficient way
int linearSearch(int *a , int i, int n, int key) {
	//base case
	if (i == n) {
		//if ith index is = n , element not found
		return -1;
	}

	//rec case
	if (a[i] == key) {
		//return index
		return i;
	}
	//inc the index by 1
	//its like a recursive for loop
	return linearSearch(a, i + 1, n, key);
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

	cout << linear(arr, n, key) << endl; //efficient way
	cout << linearSearch(arr, 0, n, key) << endl; //inefficient way

	return 0;
}