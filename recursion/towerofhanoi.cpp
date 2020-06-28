#include <iostream>
using namespace std;

void towerofhanoi(int n , char src , char dest , char helper) {
	//base case
	if (n == 0) {
		return;
	}

	//rec case
	//first step N-1 disks move from src to helper
	towerofhanoi(n - 1, src, helper, dest);

	cout << "Move " << n << " disk from " << src << " to " << dest << endl;

	towerofhanoi(n - 1, helper, dest, src);


}

int main(int argc, char const *argv[])
{
	int n ; //no of disks
	cin >> n;
	towerofhanoi(n, 'A', 'C', 'B');
	return 0;
}