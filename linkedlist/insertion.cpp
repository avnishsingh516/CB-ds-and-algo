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

//print the all data present in the linked list
//here we passing pointer variable by value , we dont want to change our linked list
void print(node*temp) {

	// node*temp = head;
	while (temp != NULL) {
		//print the data
		cout << temp->data << "-->";
		temp = temp->next;
	}
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
	cout << endl;
	print(head);

	return 0;
}