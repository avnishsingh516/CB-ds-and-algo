
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

//delete a node
node* deleteInBST(node*root, int data) {
	if (root == NULL) {
		return NULL;
	}
	else if (data == root->data) {
		//Found the node to delete 3 Cases
		//1. Node with 0 children - Leaf Node
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		}
		//2. Case Only 1 child
		//child is present in the left
		if (root->left != NULL && root->right == NULL) {
			node* temp = root->left;
			delete root;
			return temp;
		}
		//child is present in the right
		if (root->right != NULL && root->left == NULL) {
			node* temp = root->right;
			delete root;
			return temp;
		}
		//3. Case 2 children
		node *replace = root->right;
		//Find the inorder successor from right subtree
		while (replace->left != NULL) {
			replace = replace->left;
		}
		root->data = replace->data;
		root->right = deleteInBST(root->right, replace->data);
		return root;
	}
	else if (data < root->data) {
		root->left = deleteInBST(root->left, data);
		return root;
	}
	else {
		root->right = deleteInBST(root->right, data);
		return root;
	}
}


int main(int argc, char const *argv[]) {

	node*root = build();

	//data which want to delete
	int s;
	cin >> s;

	//inorder before the deletion
	inorder(root);
	cout << endl;


	root = deleteInBST(root, s);

	//inorder after the deletion
	inorder(root);

	cout << endl;

	bfs_levelwise(root);


	return 0;
}
/*
I/P :-
5 3 7 1 6 8 -1
5

O/P:-
preorder :- 1 3 5 6 7 8
preorder after deletion :- 1 3 6 7 8
bfs:-
6
3 7
1 8
*/
