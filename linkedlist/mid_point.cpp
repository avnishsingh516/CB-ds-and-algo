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

	node*mid = midPoint(head);

	cout << "mid point is :- " << mid->data << endl;

	node*kth_last = last_kth_index(head, 3);

	cout << "kth element from the last is :- " << kth_last->data << endl;


	return 0;
}