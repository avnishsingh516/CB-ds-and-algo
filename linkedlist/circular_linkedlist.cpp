#include<iostream>
using namespace std;

class node {
public:
	int data;
	node* next;

	//constructor
	node(int data) {
		this->data = data;
		next = NULL;
	}

};

//insert the circular linked list
void insert(node*&head , int data) {
	node*ptr1 = new node(data);
	node*temp = head;	//used to traverse the linked list
	ptr1->next = head;

	if (head != NULL) {

		while (temp->next != head) {
			temp = temp->next;
		}
		temp->next = ptr1;
	}
	else {
		ptr1->next = ptr1;
	}

	head = ptr1;
}

//find the node and returns its address
node* getnode(node*head , int data) {
	node*temp = head;

	while (temp->next != head) {
		if (temp->data == data) {
			return temp;
		}
		temp = temp->next;
	}
	if (temp->data == data) {
		return temp;
	}
	else return NULL;
}

//delete a node
void deleteNode(node*&head , int data) {
	node*del = getnode(head, data);
	if (del == NULL) {
		cout << "node not present \n";
		return;
	}
	if (head == del) {
		head = del->next;
	}

	node*temp = head;
	while (temp->next != del) {
		temp = temp->next;
	}

	temp->next = del->next;
	delete del;

	return;
}

//print the circular linked list
void printList(node*head) {
	node*temp = head;

	while (temp->next != head) {
		cout << temp->data << "->";
		temp = temp->next;
	}

	cout << temp->data << endl;
}

int main(int argc, char const *argv[])
{
	node *head = NULL;
	insert(head, 10);
	insert(head, 20);
	insert(head, 30);
	insert(head, 40);
	insert(head, 50);


	printList(head);

	deleteNode(head, 30);

	printList(head);

	return 0;
}