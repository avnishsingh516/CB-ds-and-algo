// all the elements occuring twice except 2 no

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int no;

	int cnt[64] = {0}; //max we have 64 bits

	for (int i = 0 ; i < n ; i++) {
		cin >> no;
		//update the cnt array by extracting bits
		int j = 0;
		while (no > 0) {
			int last_bit = no & 1;
			cnt[j] += last_bit;
			j++;
			no = no >> 1;
		}
	}

	//iterate over the array and form the ans by converting 0s and 1s(binary) into a no (decimal)
	int pow = 1;
	int ans = 0;
	for (int i = 0 ; i < 64 ; i++) {
		cnt[i] %= 3; //gives the binary representation of unique no
		ans += cnt[i] * pow;
		pow = pow * 2; //or p<<1  	//p left shift 1
	}

	cout << ans << endl;

	return 0;
}
