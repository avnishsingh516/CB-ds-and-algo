// time :- O(n^2)

#include <iostream>
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

node* buildTree() {
	int data;
	cin >> data;

	if (data == -1) {
		return NULL;
	}

	node*root = new node(data);
	root->left = buildTree();
	root->right = buildTree();

	return root;
}

//returns the height of the tree
int height(node*root) {
	if (root == NULL) {
		return 0;
	}

	int ls = height(root->left); //ls :- left subtree
	int rs = height(root->right); //rs:- right subtree

	int ms = max(ls, rs) + 1; //ms :- max height

	return ms;

}

//print the kth level of the tree
void kth_level_print(node*root , int k) {
	// k:- kth level
	if (root == NULL) {
		return;
	}

	if (k == 1) {
		cout << root->data << " ";
		return;
	}

	kth_level_print(root->left, k - 1);
	kth_level_print(root->right, k - 1);

}

//print the all level of the tree or print the tree in levelorder
void level_Order_print(node*root) {
	int H = height(root);

	for (int i = 1 ; i <= H ; i++) {
		kth_level_print(root, i);
		cout << endl;
	}

	return;
}


int main(int argc, char const *argv[])
{
	node* root = buildTree();

	// cout << height(root);

	// kth_level_print(root, 3);

	level_Order_print(root);

	cout << endl;
	return 0;
}
/*
I/P:-
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

O/P:-
8
10 3
1 6 14
9 7 13
*/
