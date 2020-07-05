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

//preorder print
void PreOrder_print(node*root) {
	if (root == NULL) {
		return ;
	}

	//otherwise print root first followed by left and then right children
	cout << root->data << " ";
	PreOrder_print(root->left);
	PreOrder_print(root->right);
}

//inorder print
void InOrder_print(node*root) {
	if (root == NULL) {
		return ;
	}

	//otherwise print left first and then followed by right child and then root
	InOrder_print(root->left);
	cout << root->data << " ";
	InOrder_print(root->right);
}

//postorder print
void PostOrder_print(node*root) {
	if (root == NULL) {
		return ;
	}

	//otherwise print left and right children first and then followed by root
	PostOrder_print(root->left);
	PostOrder_print(root->right);
	cout << root->data << " ";
}

int main(int argc, char const *argv[])
{
	node* root = buildTree();
	PreOrder_print(root);
	cout << endl;
	InOrder_print(root);
	cout << endl;
	PostOrder_print(root);
	cout << endl;
	return 0;
}
/*
I/P:-
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

O/P:-
PRE :- 8 10 1 6 9 7 3 14 13
IN :-  1 10 9 6 7 8 3 13 14
POST:- 1 9 7 6 10 13 14 3 8
*/
