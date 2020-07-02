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
//its make the single linked list to circular linked list
// i made this function to check the detectCycle function is working or not;
void makecircular(node*head) {
	node*tail = head;

	while (tail->next != NULL) {
		tail = tail->next;
	}

	node*m = midPoint(head);

	tail->next = m;
}

//detect cycle using floyds cycle
bool detectCycle(node*head) {
	node*slow = head;
	node*fast = head;

	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow) {
			return true;
		}

	}

	return false;
}

// it tells which is the starting point of the cyclic loop
//using floyds cycle technique
void start_point_cyclic(node*head) {

	node*slow = head;
	node*fast = head;
	if (detectCycle(head)) {

		while (fast != NULL && fast->next != NULL) {
			fast = fast->next->next;
			slow = slow->next;

			if (fast == slow) {
				slow = head;

				while (fast != slow) {
					fast = fast->next;
					slow = slow->next;
				}

				cout << " the point from where the cyclic part is started :- " << fast->data << endl;
				return;
			}

		}
	}
	else {
		cout << " no point found " << endl;
		return;
	}

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
	cout << head;



	makecircular(head);

	cout << detectCycle(head) << endl;

	start_point_cyclic(head);




	return 0;
}