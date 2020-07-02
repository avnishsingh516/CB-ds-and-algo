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

//reverse the linked list using iterative approach
node* reverseRec(node*&head) {
	//base case
	if (head->next == NULL || head == NULL) {
		return head;
	}

	//rec case
	node*smallHead = reverseRec(head->next);
	node*curr = head;
	curr->next->next = curr;
	curr->next = NULL;

	return smallHead;
}

//reverse the linked list using iterative approach
void reverse(node*&head) {

	node*curr = head;
	node*prev = NULL;
	node*n;

	while (curr != NULL) {
		//save the next node
		n = curr->next;
		//make the current node point to prev
		curr->next = prev;
		//just update prev and current
		prev = curr;
		curr = n;
	}

	head = prev;

	return;

}

//building a linked list
void buildList(node*&head) {

	int data;
	cin >> data;

	while (data != -1) {
		insertAtTail(head, data);
		cin >> data;
	}

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

// *****NOTE******:- we use istream& and ostream& before the operator so we can use cascading (multiplte cin and cout in single line) , otherwise we use void
//operator overloading of >> for input the linkedlist
istream& operator>>(istream &is , node*&head) {
	buildList(head);
	return is;
}

//operator overloading of << for onput the linkedlist
ostream& operator<<(ostream &os , node*&head) {
	print(head);
	return os;
}

int main(int argc, char const *argv[])
{
	node*head = NULL;
	cin >> head;

	print(head);

	reverse(head);

	print(head);

	head = reverseRec(head);

	print(head);



	return 0;
}