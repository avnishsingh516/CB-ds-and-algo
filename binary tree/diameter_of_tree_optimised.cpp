// time :- O(n)
//approach :- bottom up approach
//in this approach we do the postorder traversal
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

class Pair {
public:
	int height;
	int diameter;

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

//returns the diameter and height of the tree
Pair fastDiameter(node*root) {
	Pair p;

	if (root == NULL) {
		p.diameter = p.height = 0;
		return p;
	}
	//otherwise
	Pair left = fastDiameter(root->left);
	Pair right = fastDiameter(root->right);

	p.height = max(left.height , right.height) + 1;
	p.diameter =  max(left.height + right.height , max(left.diameter , right.diameter));

	return p;

}

int main(int argc, char const *argv[])
{
	node* root = buildTree();

	Pair p = fastDiameter(root);
	cout << p.height << endl;
	cout << p.diameter << endl;

	return 0;
}
/*
I/P:-
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
*/

