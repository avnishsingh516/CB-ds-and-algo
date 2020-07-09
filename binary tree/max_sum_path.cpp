// Maximum Sum Path From Any Node To Node

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

class Pair {

public:
	int branchSum;
	int maxSum;

	Pair() {
		branchSum = 0;
		maxSum = 0;
	}
};

Pair maxSumPath(node*root) {
	Pair p;

	if (root == NULL) {
		return p;
	}

	Pair left = maxSumPath(root->left);
	Pair right = maxSumPath(root->right);

	// construct two values
	int op1 = root->data; //if left and right both are -ve
	int op2 = left.branchSum + root->data; //if right is -ve
	int op3 = right.branchSum + root->data; //if left is -ve
	int op4 = left.branchSum + right.branchSum + root->data; //all are +ve


	int current_ans_through_root = max(op1, max(op2, max(op3, op4)));

	//branch sum of the current node
	p.branchSum = max(left.branchSum, max(right.branchSum, 0)) + root->data;
	p.maxSum = max(left.maxSum, max(right.maxSum, current_ans_through_root));

	return p;

}


int main(int argc, char const *argv[])
{
	// node* root = new node(10);
	// root->left = new node(2);
	// root->right = new node(10);
	// root->left->left  = new node(20);
	// root->left->right = new node(1);
	// root->right->right = new node(-25);
	// root->right->right->left   = new node(3);
	// root->right->right->right  = new node(4);

	node*root = buildTree();

	// bfs_levelwise(root);

	cout << "max sum path " << maxSumPath(root).maxSum << endl;


	return 0;
}
/*
I/P:-
10 2 20 -1 -1 1 -1 -1 10 -1 -25 3 -1 -1 4 -1 -1

O/P:-
max sum path 42
*/
