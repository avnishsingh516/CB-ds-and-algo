//binary search in monotonic search spaces
//time :- O(logN + p)
// p refers precision , where p is vey small no

#include<iostream>
using namespace std;

float sqr_root(int n , int prec) {

	int s = 0;
	int e = n;

	float ans = -1;

	while (s <= e) {
		int mid = (s + e) / 2; //or we can use right sift 1 (s+e)>>1

		if (mid * mid == n) {
			return mid;
		}
		else if (mid * mid < n) {
			ans = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}

	//floating part
	//brute force

	float inc = 0.1;
	//prec is ffor precision
	for (int times = 1 ; times <= prec ; times++) {

		while (ans * ans <= n) {
			ans = ans + inc;
		}
		//overshot the val
		ans = ans - inc;
		inc /= 10;
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	cout << sqr_root(n , 3) << endl;
	//prec = 3 means upto 3 decimal point
	return 0;
}