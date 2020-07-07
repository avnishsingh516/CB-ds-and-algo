// time :- O(n^2)
//in this approach we do the preorder traversal
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

//diameter :- largest distance between 2 nodes
//diameter = height of tree - 1
//returns the diameter of the tree
int diameter(node*root) {
	if (root == NULL) {
		return 0;
	}

	int h1 = height(root->left);
	int h2 = height(root->right);

	// op1 :- option 1, in which the diameter of the tree is present including the both side of the root
	int op1 = h1 + h2;

	//op2 :- option 2 , in which the diameter of the tree is present only the left side of the root
	int op2 = diameter(root->left);

	//op3 :- option 3 , in which the diameter of the tree is present only the right side of the root
	int op3 = diameter(root->right);

	return max(op1 , max(op2 , op3) );
}

int main(int argc, char const *argv[])
{
	node* root = buildTree();

	cout << diameter(root) << endl;

	return 0;
}
/*
I/P:-
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

*/
