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

	//rehash function
	void rehash() {
		// oldTable stores the address of the old table
		node<T>** oldTable = table;
		int oldTableSize = table_size;

		table_size = table_size * 2  ; //always try to make table size a prime no.

		//make the new table
		table = new node<T>*[table_size];

		for (int i = 0 ; i < table_size ; i++) {
			table[i] = NULL;
		}
		current_size = 0;

		// shift the elements from old table to new table
		for (int i = 0 ; i < oldTableSize ; i++) {

			node<T>*temp = oldTable[i];

			while (temp != NULL) {
				//insert in the new table
				//since the table and table size is changed , so,it insert into the new table
				insert(temp->key , temp->value);
				temp = temp->next;
			}

			//delete the linked list from the row of the old table
			if (oldTable[i] != NULL) {
				//the ll is present at that row
				delete oldTable[i];
			}

		}

		//delete the old table
		delete [] oldTable;

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
		float load_factor = current_size / float(table_size);

		if (load_factor > 0.7) {
			rehash();
		}


	}

	// //searching
	T* search(string key) {
		// find index of that key to iterate
		int idx = hashFn(key);
		//iterate over the ll of that index
		node<T>*temp = table[idx];
		while (temp != NULL) {
			if (temp->key == key) {
				//found
				return &(temp->value); //return the address of the value
			}
			temp = temp->next;
		}

		//not found
		return NULL; //for this we make search return type of the pointer type
	}

	// //deletion
	void erase(string key) {
		int idx = hashFn(key);
		node<T>* temp = table[idx];
		if (search(key) == NULL) {
			return;
		}
		//found at the head
		if (temp->key == key) {
			node<T>* tobeDeleted = temp;
			table[idx] = temp->next;
			tobeDeleted->next = NULL; //so the recursive destructor not called
			delete tobeDeleted;
			return;
		}
		//found at the middle or tail
		while (temp->next->key != key) {
			temp = temp->next;
		}
		node<T>* tobeDeleted = temp->next;
		temp->next = temp->next->next;
		tobeDeleted->next = NULL;
		delete tobeDeleted;
		return;
	}

	//oveloading
	T& operator[](string key) {
		T* add = NULL;
		if (search(key) != NULL) {
			add =  search(key);
		}
		else {
			T val;
			insert(key, val);
			add = search(key);
		}
		return *add;
	}

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