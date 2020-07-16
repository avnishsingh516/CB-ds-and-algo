#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

//compare based upon the finishing time of the activity
bool compare(pair<int, int> p1 , pair<int, int> p2) {
	return p1.second < p2.second;
}

int main(int argc, char const *argv[])
{

	int t, n , s , e;
	cin >> t;

	vector<pair<int, int> > v;

	while (t--) {
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> s >> e;
			v.push_back(make_pair(s, e));
		}

		//activity selection algorithm

		// 1. sort
		sort(v.begin(), v.end(), compare);

		//2. start picking the activity
		int result = 1;
		int fin = v[0].second; //finshing time

		//iterate over remaining activities
		for (int i = 1 ; i < n ; i++) {
			// the starting time of the activity is more than the previous activity finshing time
			//then pick that activity
			if (v[i].first >= fin) {
				fin = v[i].second;
				result++;
			}
		}
		cout << result << endl;
		v.clear();

	}

	return 0;
}

/*

I/P:-
1
6
7 9
0 10
4 5
8 9
4 10
5 7

O/P:-
3

*/