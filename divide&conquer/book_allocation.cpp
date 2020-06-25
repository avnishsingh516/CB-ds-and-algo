#include<iostream>
#include <climits>
#include<algorithm>
using namespace std;

bool isPossible(int arr[] , int n , int m, int curr_min) {

	int studentUsed = 1;
	int pagesreading = 0;

	for (int i = 0; i < n; i++)
	{

		if (pagesreading + arr[i] > curr_min) {
			studentUsed++;

			pagesreading = arr[i];

			if (studentUsed > m) {
				return false;
			}
		}
		else {
			pagesreading += arr[i];
		}
	}

	return true;
}

int findPages(int arr[] , int n , int m) {

	int sum = 0;

	// if N<M
	if ( n < m )
	{
		return -1;
	}

	//count the no of pages
	for (int i = 0 ; i < n ; i++) {
		sum += arr[i];
	}

	int s = arr[n - 1];
	int e = sum;
	int ans = INT_MAX;

	while (s <= e) {
		int mid = (s + e) / 2;

		if (isPossible(arr, n, m, mid)) {
			ans = min(ans, mid);
			e = mid - 1;
		}
		else {
			//it is not possible to divide at x pages
			//increa se the no of pages
			s = mid + 1;
		}
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	int n; //no of books
	int m; //no of students
	cin >> n >> m;

	int arr[1000];

	//no of pages in each book in sorted way
	for (int i = 0 ; i < n ; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	cout << findPages(arr, n, m) << endl;
	return 0;
}