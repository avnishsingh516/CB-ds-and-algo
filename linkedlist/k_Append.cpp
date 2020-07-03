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

//kth node form the end of the linked list
node* last_kth_index(node*head , int k) {

	node*fast = head;
	node*slow = head;

	//first make the jumps of fast of kth index
	while (k) {
		fast = fast->next;
		k--;
	}

	//after that move the slow and fast simuntaneously until fast reaches at null .
	//so slow makes n-k steps which gives kth node from the last
	while (fast != NULL) {
		fast = fast->next;
		slow = slow->next;
	}

	return slow;

}

//kth append
void k_Append(node*&head , int k) {

	node*kth = last_kth_index(head, k); //gives kth node from last
	node*last = head;

	while (last->next != NULL) {
		last = last->next;
	}

	node*prev = head; //gives prev node of the kth node

	while (prev->next != kth) {
		prev = prev->next;
	}

	last->next = head;
	prev->next = NULL;
	head = kth;

	return;

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

	int idx;
	cin >> idx;

	idx = idx % len; //if kth > len

	if (idx == 0) {
		print(head);
	}
	else {
		k_Append(head, idx);
		print(head);
	}

	return 0;
}