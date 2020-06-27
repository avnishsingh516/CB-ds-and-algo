//count the no of prime nos in a range a to b

#include <iostream>
using namespace std;


//also called Eratosthenes sieve

//sieve Approach - Generate a array containing prime Numbers
void prime_sieve(int *p ) { // in terms of array :- *p = p[]

	//first make all odd no prime , because even no are no prime after no 3
	for (int i = 3 ; i <= 1000 ; i += 2) {
		p[i] = 1;
	}

	//sieve
	for (int i = 3 ; i <= 1000 ; i += 2) {
		//if the current no is not marked (it is prime)
		if (p[i] == 1) {
			//mark all rhe multiples of i as not prime
			for (int j = i * i ; j <= 1000 ; j = j + i) {
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

	int p[1000] = {0} ;
	int csum[1000] = {0};
	prime_sieve(p);

	//precomputation of the primes

	for (int i = 0; i < 1000 ; i++) {
		csum[i] = csum[i - 1] + p[i];
	}

	int q;
	cin >> q;
	while (q--) {
		int a, b ;
		cin >> a >> b;
		cout << csum[b] - csum[a - 1] << endl;
	}



	return 0;
}