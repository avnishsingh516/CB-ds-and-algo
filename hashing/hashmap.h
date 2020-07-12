//implement a hashmap
//seperate chaining technoique
#include <iostream>
using namespace std;

template<typename T>
class node {
public:

	string key;
	T value;
	node<T>*next;

	node(string key , T val) {

		this->key = key;
		value = val;
		next = NULL;

	}

	~node() {
		if (next != NULL) {
			delete next;
		}
	}

};


template<typename T>
class Hashtable {

	node<T>** table; //pointer to an array od pointer
	int current_size;
	int table_size;

	//hash function
	int hashFn(string key) {
		int idx = 0; //index at which the value will insert
		int p = 1 ; //power

		for (int j = 0 ; j < key.length() ; j++) {
			idx = idx + (key[j] * p) % table_size;
			idx = idx % table_size; //mod reduced the big no. into smaller . so,the array dont overflow
			p = (p * 27) % table_size; //update the power
		}

		return idx;
	}


public:

	Hashtable(int ts = 7) {
		table_size = ts;
		table = new node<T>*[table_size];
		current_size = 0;

		//initializing the pointers of array with NULL
		for (int i = 0 ; i < table_size; i++) {
			table[i] = NULL;
		}

	}


	//insertion
	void insert(string key , T value) {
		//index
		int idx = hashFn(key);

		//create the new node
		node<T>*n = new node<T>(key , value);

		//insert at head of the linked list with id = index
		n->next = table[idx];
		table[idx] = n;
		current_size++;

		// rehashing


	}

	// //searching
	// T search(string key){

	// }

	// //deletion
	// void erase(string key){

	// }

	//print
	void print() {

		for (int i = 0 ; i < table_size; i++) {
			cout << "bucket " << i << " :- ";

			//traverse over the ll of ith index of the array
			node<T>*temp = table[i];

			while (temp != NULL) {
				cout << temp->key << " --> ";
				temp = temp->next;
			}

			cout << endl;

		}

		cout << endl;
	}

};