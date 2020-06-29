#include<iostream>
using namespace std;

//inefficient method

void removeDuplicate(char *input , char *output , int i , int j) {

	//base case
	if (input[i] == '\0') {
		//print output
		cout << output;
		return;
	}

	//rec case

	//if the curr and prev element are same
	//add '*' between curr and prev element
	if (input[i] == output[j - 1]) {
		output[j] = '*';
		output[j + 1] = input[i];
		removeDuplicate(input, output, i + 1, j + 2);
	}
	//else copy the same element
	else {
		output[j] = input[i];
		removeDuplicate(input, output, i + 1, j + 1);
	}

	return;
}

int main() {
	char ch[10000];
	cin >> ch;

	char output[10000];

	removeDuplicate(ch, output, 0, 0);

	return 0;
}