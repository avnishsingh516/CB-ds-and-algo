#include<iostream>
using namespace  std;

//no to spelling
//ex:- 2048 ----->  two zero four eight

// character array wich gives the spelling
char words[][10] = {"zero" , "one" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" , "nine" };

void printSpelling(int n) {

	//base case
	if (n == 0) {
		//if n reduced to 0
		return;
	}

	//rec case => first print the spellings of (204)
	printSpelling(n / 10);

	//last digit
	int digit = n % 10;

	//print word
	cout << words[digit] << " ";
	return;
}

int main(int argc, char const *argv[])
{
	int n ;
	cin >> n;
	printSpelling(n);
	cout << endl;
	return 0;
}