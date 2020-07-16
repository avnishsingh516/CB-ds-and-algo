//using inbuilt sort() function , which uses quick or merge sort having complexity of O(nlogn)
//optimised method has complexity of O(n) , by using the counting sort

#include <iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int arr[10000] = {0};
	int t, n;
	cin >> t;

	while (t--) {
		//reset the array value to 0 , for each test case
		memset(arr, 0, sizeof(arr));

		int n , rank;
		string name;
		cin >> n;

		for (int i = 0 ; i < n ; i++) {
			cin >> name >> rank;

			arr[rank]++; //increase the particular preffered rank index by 1
		}

		//greedy algo :- assign the team nearest rank available;
		int actual_rank = 1; //rank which we gives them
		int sum = 0;

		for (int i = 1 ; i <= n ; i++) {

			//until that arr[rank] is not equal to 0
			while (arr[i]) {
				sum += abs(actual_rank - i);
				arr[i]--;
				actual_rank++;
			}
		}

		cout << sum << endl;

	}
	return 0;
}

/*
I/P:-

1
7
noobz 1
llamas 2
Winn3rz 2
5thwheel 1
NotoricCoders 5
StrangeCase 7
WhoKnows 7

O/P:-
5

*/