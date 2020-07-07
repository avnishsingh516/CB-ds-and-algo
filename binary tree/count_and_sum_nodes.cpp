// time :- O(n)

#include <iostream>
#include<queue>
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

//count the no of nodes in a tree
int count(node*root) {
	if (root == NULL) {
		return 0;
	}
	//returns the no of nodes at left + no of nodes at right + no of root itself (which is 1)
	return 1 + count(root->left) + count(root->right);
}

//sum the no of nodes in a tree
int sum(node*root) {
	if (root == NULL) {
		return 0;
	}
	//returns the sum of the curr root + sum of the left child + sum of right child
	return (root->data) + sum(root->left) + sum(root->right);
}


int main(int argc, char const *argv[])
{
	node* root = buildTree();

	cout << count(root) << endl << sum(root) << endl;

	return 0;
}
/*
I/P:-
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

O/P:-
9
71
*/
