#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{

	int t;
	int w, h, n;
	cin >> t;
	// w and h are grid size
	// n is the no of towers

	int x[1000], y[1000];
	//x and y are the coordinates of the towers

	while (t--) {

		cin >> w >> h >> n;

		for (int i = 0 ; i < n ; i++) {
			cin >> x[i] >> y[i];
		}

		//sorting
		sort(x, x + n);
		sort(y, y + n);

		//delta x and delta y for maximum area
		int dx = x[0] - 1;
		int dy = y[0] - 1;

		for (int i = 1 ; i < n ; i++) {
			dx = max(dx, (x[i] - x[i - 1] - 1));
			dy = max(dy, (y[i] - y[i - 1] - 1));
		}

		//corner case (last tower to grid end)
		dx = max(dx, w - x[n - 1]);
		dy = max(dy, h - y[n - 1]);

		//area
		int area = dx * dy;
		cout << area << endl;

	}

	return 0;
}