#include<bits/stdc++.h>
using namespace std;

class Student {
public:
	int marks;
	string name;
};

//Bucket sort to sort an array of students

void bucket_sort(Student s[] , int n) {

	//assuming marks ar ein range 0-100
	vector<Student> v[101];

	//O(N) time
	for (int i = 0 ; i < n ; i++) {
		int m = s[i].marks;

		v[m].push_back(s[i]);
	}

	//iterate over the vector and print the students
	//we want toppers , we print vector in reverse order
	for (int i = 100 ; i >= 0 ; i--) {

		for (vector<Student>::iterator it = v[i].begin() ; it != v[i].end() ; it++) {
			cout << (*it).marks << " " << (*it).name << endl;
		}
	}
}

int main(int argc, char const *argv[])
{
	Student s[10000];
	int n;
	cin >> n;

	for (int i = 0 ; i < n ; i++) {
		cin >> s[i].name >> s[i].marks;
	}

	bucket_sort(s, n);
	return 0;
}
/*
input:-
5
A 10
B 40
C 10
D 43
Ram 60
*/
