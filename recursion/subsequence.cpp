#include <iostream>
using namespace std;

int count = 0;
void generate_subsequence(char *in , char *out , int i , int j) {

	//base case
	if (in[i] == '\0') {
		//reach the last pos of input string
		out[j] = '\0'; //add null to the last index
		cout << out << endl;
		count++;
		return;
	}

	//rec case
	// 1. include the current character
	out[j] = in[i]; //copy the curr character in the output
	generate_subsequence(in, out, i + 1, j + 1);

	// 2. exclude the current character
	generate_subsequence(in, out, i + 1, j);

}

int main(int argc, char const *argv[])
{
	char input[10];
	cin >> input;
	char output[10];
	generate_subsequence(input, output, 0, 0);
	cout << endl << count;
	return 0;
}

//------------------for printing the subsequence in reverse order------------

// replace the rec case by this:-

/*
//rec case

	// 2. exclude the current character
	generate_subsequence(in, out, i + 1, j);

	// 1. include the current character
	out[j] = in[i]; //copy the curr character in the output
	generate_subsequence(in, out, i + 1, j + 1);

*/