#include<iostream>
using namespace std;

bool canPlacecow(int stalls[] , int n, int cows , int min_sep) {

	int last_cow = stalls[0];
	//place the first cow in the first stall

	int cnt = 1;

	for (int i = 1; i < n; i++) {
		if (stalls[i] - last_cow >= min_sep) {
			//then we place the cow in that stall
			last_cow = stalls[i]; //last cow get updated
			cnt++;
			if (cnt == cows) {
				return true;
			}
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int stalls[] = {1, 2, 4, 8, 9} ;//after sorting
	int n = 5;

	int cows = 3;

	//binary search algo
	int s = 0;
	int e = stalls[n - 1] - stalls[0]; //it gives the max separation b/w the stalls

	int ans = 0;
	while (s <= e) {

		int mid = (s + e) / 2;

		bool cowRakhPaye = canPlacecow(stalls, n, cows, mid);

		if (cowRakhPaye) {
			ans = mid;
			s = mid + 1; //for finding large vlaue of min_step
		}
		else {
			e = mid - 1;
		}
	}

	cout << ans << endl;
	return 0;
}