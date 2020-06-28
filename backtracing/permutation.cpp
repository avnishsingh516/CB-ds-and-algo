#include <iostream>
using namespace std;

void permute(char *in , int i) {

	//base case
	if (in[i] == '\0') {
		cout << in << endl;
		return;
	}

	//recursive case
	for (int j = i ; in[j] != '\0' ; j++) {

		//swaping
		swap(in[i], in[j]);

		//rec call
		permute(in, i + 1);

		//backtracing :- to restore the original array
		swap(in[i], in[j]);
	}
}

int main(int argc, char const *argv[])
{
	char input[10] = "abc";
	// cin>>input;

	permute(input, 0);

	return 0;
}