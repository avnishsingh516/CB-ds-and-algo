#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool compare(pair<int, int> p1 , pair<int, int> p2) {
	return p1.first > p2.first;
}

int main(int argc, char const *argv[])
{
	int n, t, d, f, D, F, prev;
	cin >> t; //test case

	while (t--) {

		int flag = 0 , ans = 0;

		vector<pair<int, int> > v; //store the location of all fuel station
		priority_queue<int> pq; //keep the track of the location of fuel station which we passed

		cin >> n; //no of fuel station

		for (int i = 0 ; i < n; i++) {
			//input the distance and the capacity of the fuel station from town
			cin >> d >> f;

			v.push_back(make_pair(d, f));
		}

		//logic

		//sort the cities according to their location
		sort(v.begin(), v.end(), compare);

		//input the initial distance and capacity of the fuel
		cin >> D >> F;

		//update the distance of the fuel station from the truck
		for (int i = 0 ; i < n ; i++) {
			//the distance is given fromthe town
			//so, we have to convert it according to the truck distance
			v[i].first = D - v[i].first;
		}

		//prev denotes the previous city we have visited
		prev = 0;
		int x = 0; //current city

		while (x < n) {
			//if we have enough fuel to go to next city
			if (F >= (v[x].first - prev)) {
				//reduce the fuel by the distance travelled by the truck . 1 unit of distance consume 1 unit of fuel
				F = F - (v[x].first - prev);
				pq.push(v[x].second);
				prev = v[x].first;
			}
			//if we donot have enough fuel
			//so, check if you have some fueling station visited in the priority queue
			else {

				if (pq.empty()) {
					//no fueling station is present on the way . this is impossible to travel
					flag = 1;
					break;
				}

				//otherwise refuel the truck with fuel stations with higher capacity
				F += pq.top();
				//remove the fuel station from priority queue
				pq.pop();
				ans++;
				continue;

			}

			x++;

		}

		//actually travelled through n fuel stations
		//what is left you have reach the town from the last fuel station
		if (flag == 1) {
			cout << "-1" << endl;
			continue; //jump to next test case
		}
		//otherwise
		D = D - v[n - 1].first;

		if (F >= D) {
			cout << ans << endl;
			continue; //jump to next test case
		}

		//otherwise
		while (F < D) {
			if (pq.empty()) {
				//cant reach
				flag = 1;
				break;
			}

			F += pq.top();
			pq.pop();
			ans++;
		}

		if (flag == 1) {
			cout << "-1" << endl;
			continue; //jump to next test case
		}

		cout << ans << endl;
	}

	return 0;
}
/*

IP:-
1
4
4 4
5 2
11 5
15 10
25 10

OP:-
2

*/