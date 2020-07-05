#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
	queue<char> q;
	int freq[27] = {0};

	//running a stream until a '.'
	char ch;
	cin >> ch;

	while (ch != '.') {
		// insert in the queue and freq table
		q.push(ch);
		freq[ch - 'a']++;

		//query
		while (!q.empty()) {
			//idx of the element at the front
			int idx = q.front() - 'a';

			if (freq[idx] > 1) {
				q.pop();
			}
			else {
				cout << q.front() << endl;
				break;
			}
		}
		//queue is empty
		if (q.empty()) {
			cout << "-1" << endl;
		}

		cin >> ch;
	}

	return 0;
}