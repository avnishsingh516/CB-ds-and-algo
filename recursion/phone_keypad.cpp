#include<iostream>
using namespace std;

//keypad
char keypad[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void generate_names(char *in , char *out, int i, int j) {

	//base case
	if (in[i] == '\0') {
		//reach the last pos of input string
		out[j] = '\0'; //add null to the last index
		cout << out << endl;
		return;
	}

	//rec case

	//extract digit to iterate in keypad
	int digit = in[i] - '0';

	//special case :- if digit is 1 or 0 it doesnt give the output
	//by using special case , if the digit is 1 or 0 then we just skip this part by not adding the 0 or 1 character which is null in the output string
	if (digit == 1 or digit == 0) {
		generate_names(in, out, i + 1, j);
	}

	//it give me each char of the digit
	for (int k = 0 ; keypad[digit][k] != '\0'; k++) {

		out[j] = keypad[digit][k]; //add the curr char in the output

		//fill the remaining part
		generate_names(in, out, i + 1, j + 1);

	}

	return;
}

int main(int argc, char const *argv[])
{
	char input[100] = "231";
	// cin >> input;

	char output[100];

	generate_names(input, output, 0, 0);

	return 0;
}