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
//midpoint in linked list
node* midPoint(node*head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	//if fast take 2 steps forward ,then slow will take 1 steps
	node*slow = head;
	node*fast = head->next;

	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
}

//merge two sorted linked list
node* merge(node*a , node*b) {
	//base case
	if (a == NULL) {
		return b;
	}
	else if (b == NULL) {
		return a;
	}

	//rec case
	node*c;

	//compare a and b for smaller element
	if (a->data < b->data) {
		c = a;
		c->next = merge(a->next, b);
	}
	else {
		//a->data > b->data
		c = b;
		c->next = merge(a, b->next);
	}

	return c;

}

//merge sort the linked list recursively
node* mergeSort(node*head) {
	//base case
	if (head == NULL || head->next == NULL) {
		return head;
	}

	//rec case
	// 1. mid point
	node*mid = midPoint(head);

	node*a = head; //a is start from head
	node*b = mid->next; // b is start from mid+1 of the linked list

	//now make the mid->next to NULL
	mid->next = NULL;

	// 2. recursively sort
	a = mergeSort(a);
	b = mergeSort(b);

	//3. merge a and b
	node*c = merge(a, b);

	return c;

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
	// node*head1 = NULL;
	// node*head2 = NULL;

	// cin >> head1 >> head2;

	// print(head1);
	// print(head2);

	// node*combine = merge(head1, head2);

	// print(combine);

	node*head3 = NULL;
	cin >> head3;

	cout << head3;

	cout << "sorted linkedlist :- " << endl;

	head3 = mergeSort(head3);

	cout << head3;




	return 0;
}