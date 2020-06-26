// all the elements occuring twice except 2 no
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n , no , res = 0;
	cin >> n;

	int a[n];

	for (int i = 0 ; i < n ; i++) {
		cin >> no;
		a[i] = no; //stores value in array
		res = res ^ no;
	}
	// res = a^b

	int temp = res;
	int pos = 0;

	while ((temp & 1) != 1) {
		//untill we got first set bit or 1-bit
		pos++;
		temp = temp >> 1; //finding the each bit using right shift
	}
	//the first bit in res is at position 'pos'

	int mask = 1 << pos;

	//find those no which contain set bit at position 'pos'
	int x = 0; //first unique no
	int y = 0 ;//second unique no

	for (int i = 0; i < n; i++)
	{
		if ((a[i]&mask) > 0) {
			x = x ^ a[i];
		}
	}

	y = res ^ x; //gives second no

	//print smallest no first
	cout << min(x, y) << " " << max(x, y) << endl;

	return 0;
}