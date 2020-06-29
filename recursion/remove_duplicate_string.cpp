#include<iostream>
#include<string>
using namespace std;

string removeStirng(string str) {
	//base case
	if (str.size() <= 1) {
		return str;
	}


	//rec case
	string ros = removeStirng(str.substr(1));

	//donot add the curr character because its already present in prev string
	if (str[0] == ros[0]) {
		return ros;
	}
	// add the curr character in prev string
	return str[0] + ros;
}

int main() {
	string str;
	cin >> str;

	cout << removeStirng(str);
	return 0;
}