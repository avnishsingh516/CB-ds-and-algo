// BST to Sorted Linked List Convert / Flatten a Tree

#include <bits/stdc++.h>
using namespace std;

class node {
public:

	int data;
	node*left;
	node*right;

	node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}

};

//accepts the old root node & data and returns the new root node
node* insertInBST(node*root , int data) {
	//base case
	if (root == NULL) {
		//create a new node
		return (new node(data));
	}
	//rec case - insert in the subtree and update pointers
	if (data <= root->data) {
		//go to the left
		root->left = insertInBST(root->left, data);
	}
	else {
		//go to right
		root->right = insertInBST(root->right, data);
	}

	return root;
}

//make a bst tree
node* build() {

	//read a list od no till -1 and also these numbers will be inserted into BST
	int d;
	cin >> d;

	node*root = NULL;

	while (d != -1) {
		root = insertInBST(root, d);
		cin >> d;
	}

	return root;
}


// it gives the output level wise not in single satement
void bfs_levelwise(node*root) {
	//queue is of the type node* , it stores the address of the node
	queue<node*> q;

	//first push the root in the queue and then their children
	q.push(root);

	// after the root , we push NULL in the queue . so, we can able to change the line after every level
	q.push(NULL);

	while (!q.empty()) {
		node*f = q.front();
		//if NULL is found then change the line and pop the NULL
		if (f == NULL) {
			cout << endl;
			q.pop();

			// if queue is not empty , we push NULL into the queue because at this point we push the all node of that particular level
			if (!q.empty()) {
				q.push(NULL);
			}
		}
		// otherwise it push the root children
		else {
			cout << f->data << " ";
			q.pop();


			if (f->left) {
				// if the left child of the tree is present then push it in the queue
				q.push(f->left);
			}

			if (f->right) {
				// if the right child of the tree is present then push it in the queue
				q.push(f->right);
			}
		}


	}

	return;
}


//inorder print
void inorder(node*root) {
	if (root == NULL) {
		return;
	}

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

//it is a pair class but with linkedlidt name
class LinkedList {
public:
	node*head;
	node*tail;
};

//flatten the tree
LinkedList flatten(node*root) {
	LinkedList l;

	if (root == NULL) {
		l.head = l.tail = NULL;
		return l;
	}
	// Leaf Node
	if (root->left == NULL && root->right == NULL) {
		l.head = l.tail = root;
		return l;
	}
	// Left is Not NULL
	if (root->left != NULL && root->right == NULL) {
		LinkedList leftLL = flatten(root->left);
		leftLL.tail->right = root;

		l.head = leftLL.head;
		l.tail = root;
		return l;
	}
	//Right is Not NULL
	if (root->left == NULL && root->right != NULL) {
		LinkedList rightLL = flatten(root->right);
		root->right = rightLL.head;

		l.head = root;
		l.tail  = rightLL.tail;
		return l;
	}
	//Both Sides are not NULL
	//postorder approach in this part
	LinkedList leftLL = flatten(root->left);
	LinkedList rightLL = flatten(root->right);

	leftLL.tail->right = root;
	root->right = rightLL.head;

	l.head = leftLL.head;
	l.tail = rightLL.tail;
	return l;

}

int main() {
	node*root = build();
	inorder(root);
	cout << endl;
	bfs_levelwise(root);
	cout << endl;

	LinkedList l = flatten(root);
	node*temp = l.head;

	while (temp != NULL) {
		cout << temp->data << " --> ";
		temp = temp->right;
	}
	cout << endl;


	return 0;
}

/*
I/P :-
5 3 7 1 6 8 -1

O/P:-
preorder :- 1 3 5 6 7 8

bfs:-
5
3 7
1 6 8

flatten tree
1 --> 3 --> 5 --> 6 --> 7 --> 8 -->

*/