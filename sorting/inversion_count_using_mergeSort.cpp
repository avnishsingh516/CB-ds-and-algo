#include<iostream>
using namespace std;

// a[i] > a[j]

int merge(int *a , int s, int e) {

	int mid = (s + e) / 2;

	int i = s;
	int j = mid + 1;
	int k = s;

	int temp[100];

	int cnt = 0; //cross inversion

	while (i <= mid and j <= e) {
		if (a[i] <= a[j]) {
			temp[k] = a[i];
			k++;
			i++;
		}
		else {
			temp[k] = a[j];
			k++;
			j++;
			cnt += mid - i + 1;
		}
	}

	//fill the array if some elements are left in one of the arrays
	while (i <= mid) {
		temp[k++] = a[i++];
	}

	while (j <= e) {
		temp[k++] = a[j++];
	}

	//copy all elements back to the array a
	for (int i = s ; i <= e ; i++) {
		a[i] = temp[i];
	}


	return cnt;

}

int inversion_count(int *a , int s , int e) {

	//base case
	if (s >= e) {
		return 0;
	}

	//merge sort
	int mid = (s + e) / 2;

	int x = inversion_count(a, s, mid); //left array inversion
	int y = inversion_count(a, mid + 1, e); //right array inversion
	int z = merge(a, s, e); //cross inversion

	return x + y + z;
}

int main(int argc, char const *argv[])
{
	int n , arr[100];
	cin >> n;

	for (int i = 0 ; i < n ; i++) {
		cin >> arr[i];
	}

	cout << inversion_count(arr, 0, n - 1) << endl;

	return 0;
}