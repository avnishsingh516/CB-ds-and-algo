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

void insertAtHead(node*&head, int data) {

	//creating new node
	node *n = new node(data);
	n->next = head;
	head = n;
}

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

	return;
}

//even after odd
node* evenOdd (node*head) {
	node*even = NULL; //gives the even ll
	node*odd = NULL; //gives odd ll

	while (head != NULL) {

		//even
		if ((head->data) % 2 == 0) {
			insertAtTail(even, head->data);
		}
		else {
			insertAtTail(odd, head->data);
		}

		head = head->next;
	}
	// if there is no odd no. in ll
	if (odd == NULL) {
		odd = even;
	}
	else {
		// add the even at the end of the odd ll
		node*temp = odd;
		while (temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = even;
	}

	return odd;

}

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
	//lenght of linked list
	int len , element;
	cin >> len;

	node*head = NULL;

	for (int i = 0 ; i < len ; i++) {
		cin >> element;
		insertAtTail(head, element);
	}

	head = evenOdd(head);

	print(head);

	return 0;
}