#include<bits/stdc++.h>
using namespace std;

void countingSort(int *a , int n) {
	//largest in the array , assuming no > 0
	int largest = -1;
	for (int i = 0; i < n; i++) {
		largest = max(a[i], largest);
	}

	//create freq array and initalize by 0
	int *freq = new int[largest + 1] {0};

	for (int i = 0; i < n; i++) {
		freq[a[i]]++;
	}

	//put the elements back into the array a by reading freq array
	int j = 0;
	for (int i = 0; i <= largest; i++) {
		while (freq[i] > 0) {
			a[j] = i;
			freq[i]--;
			j++;
		}
	}
}

int main(int argc, char const *argv[])
{
	int n , a[1000];
	cin >> n;

	for (int i = 0 ; i < n ; i++) {
		cin >> a[i];
	}

	countingSort(a, n);

	for (int i = 0 ; i < n ; i++) {
		cout << a[i] << " ";
	}

	cout << endl;

	return 0;
}