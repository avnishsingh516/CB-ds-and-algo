#include <iostream>
using namespace std;


//also called Eratosthenes sieve

//sieve Approach - Generate a array containing prime Numbers
void prime_sieve(int *p , int n) { // in terms of array :- *p = p[]

	//first make all odd no prime , because even no are no prime after no 3
	for (int i = 3 ; i <= n ; i += 2) {
		p[i] = 1;
	}

	//sieve
	for (int i = 3 ; i <= n ; i += 2) {
		//if the current no is not marked (it is prime)
		if (p[i] == 1) {
			//mark all rhe multiples of i as not prime
			for (int j = i * i ; j <= n ; j = j + i) {
				p[j] = 0;
			}
		}
	}

	//special cases
	p[0] = p[1] = 0;
	p[2] = 1;
}

int main(int argc, char const *argv[])
{
	int n , count = 0; //upto which no
	cin >> n;

	int p[n] = {0};
	prime_sieve(p, n);

	for (int i = 0 ; i <= n ; i++) {
		if (p[i] == 1) {
			cout << i << " ";
			count++;
		}
	}
	cout << endl << "no of prime nos :- " << count << endl;
	return 0;
}