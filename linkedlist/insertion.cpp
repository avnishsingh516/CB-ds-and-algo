#include<iostream>
using namespace std;

class node {
public:
	int data;
	node* next;

	//constructor
	node(int d) {
		data = d;
		next = NULL;
	}

};

//create linked list using class
/*
class Linkedlist{

	node*head;
	node*tail;

public:
	Linkedlist(){
	head=NULL;
	tail=NULL;
	}

	void insert(){

	}
};
*/

//but we use function approach

//insert at head
//passing a pointer variable by reference , so changes are reflected back in main memory (which is creating a node)
void insertAtHead(node*&head, int data) {

	//creating new node
	node *n = new node(data);
	n->next = head;
	head = n;
}

//insert at tail
void insertAtTail(node*&head, int data) {

	if (head == NULL) {
		insertAtHead(head, data);
		return;
	}

	node*tail = head;

	while (tail->next != NULL) {
		tail = tail->next;
	}
	node *n = new node(data);
	tail->next = n;
}

//find the length of the linked list
int len(node*head) {

	int length = 0;
	while (head != NULL) {
		head = head->next;
		length++;
	}

	return length;
}

//insert in middle
void insertInMiddle(node*&head , int data , int position) {

	if (head == NULL || position == 0) {
		insertAtHead(head, data);
	}
	else if (position > len(head)) {
		insertAtTail(head, data);
	}
	else {
		// insert in the middle
		//take position-1 jumps
		int jumps = 1;
		node*temp = head;
		while (jumps <= position - 1) {
			temp = temp->next;
			jumps++;
		}

		node*n = new node(data);
		n->next = temp->next;
		temp->next = n;
	}
}

//delete the node at the head
void deleteAtHead(node*&head) {

	if (head == NULL) {
		return;
	}

	node*temp = head;
	head = head->next;
	delete temp;

}

//delete the node at the tail
void deleteAtTail(node*&head) {
	node*prev = NULL;
	node*temp = head;

	while (temp->next != NULL) {
		prev = temp;
		temp = temp->next;
	}

	delete temp;
	prev->next = NULL;
}

//delete the node in the middle
void deleteInMiddle(node*&head , int position) {
	node*prev = NULL;
	node*temp = head;

	while (position) {
		prev = temp;
		temp = temp->next;
		position--;
	}

	prev->next = temp->next;
	delete temp;
}

//searching using recursive APPROACH
bool searchRecursive(node*head , int key) {
	//base case
	if (head == NULL) {
		cout << "not present";
		return false;
	}

	//rec case
	if (head->data == key) {
		cout << "element present";
		return true;
	}
	else {
		return searchRecursive(head->next, key);
	}
}

//searching using iterative approach
bool searchIterative(node*head, int key) {

	while (head != NULL) {

		if (head->data == key) {
			cout << "element present";
			return true;
		}
		else {
			head = head->next;
		}
	}
	cout << "not present";
	return false;
}


//print the all data present in the linked list
//here we passing pointer variable by value , we dont want to change our linked list
void print(node*temp) {

	// node*temp = head;
	while (temp != NULL) {
		//print the data
		cout << temp->data << "-->";
		temp = temp->next;
	}
	cout << endl;

}

int main() {
	//head points the NUll in starting
	node*head = NULL;

	//insert elements at head
	insertAtHead(head, 5);
	insertAtHead(head, 3);
	insertAtHead(head, 6);
	insertAtHead(head, 8);
	insertAtHead(head, 10);
	insertAtHead(head, 17);

	print(head);

	insertInMiddle(head, 2, 3);

	print(head);

	insertAtTail(head, 99);

	print(head);

	deleteAtHead(head);
	deleteAtTail(head);

	print(head);

	deleteInMiddle(head, 2);

	print(head);

	cout << "recursive approach :- " << searchRecursive(head, 10) << endl;
	cout << "iterative approach:- " << searchIterative(head, 10) << endl;

	return 0;
}