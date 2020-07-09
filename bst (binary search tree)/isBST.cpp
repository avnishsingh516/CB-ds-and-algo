// check the given tree is BST or not

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

//inorder print
void inorder(node*root) {
	if (root == NULL) {
		return;
	}

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

//check the tree is bst or not
bool isBST(node *root, int minV = INT_MIN, int maxV = INT_MAX) {
	if (root == NULL) {
		return true;
	}
	// a tree is called BST:-
	/*
	1. when the data is lie btw the maxV and minV values
	2.if it is left child , then its min value is minV and max value is equal or lesser than its root value
	3.if it is right child, then its min value is equal or greater than its root value ans max value is maxV
	4. its subtrees are also BST
	*/
	if (root->data >= minV && root->data <= maxV && isBST(root->left, minV, root->data) && isBST(root->right, root->data, maxV)) {
		return true;
	}
	return false;
}




int main(int argc, char const *argv[]) {

	node*root = build();

	inorder(root);

	//it always gives true because we make BST evey time
	cout << endl << "tree is bst :- " << isBST(root) << endl;


	return 0;
}
/*
I/P :-
5 3 7 1 6 8 -1

O/P:-
1 3 5 6 7 8
tree is bst :- 1
*/
