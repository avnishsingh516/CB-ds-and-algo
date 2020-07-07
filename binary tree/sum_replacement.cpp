//replace each node by "SUM OF CHILD NODES" without changing the leaf nodes
#include <iostream>
#include <queue>
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


int replaceSum(node*root) {
	if (root == NULL) {
		return 0;
	}

	//if it is a leaf node , then return its value
	if (root->left == NULL and root->right == NULL) {
		return root->data;
	}

	//recursive part
	//postorder traversal
	int leftSum = replaceSum(root->left);
	int rightSum = replaceSum(root->right);

	//store the current root data , so we dont loose it
	int temp = root->data;

	//replace the current root data , with the sum of its children node
	root->data = leftSum + rightSum;

	//return sum the current node stores data and its updated data which is sum of its child node
	//return to its parent node
	return temp + root->data;

}

int main(int argc, char const *argv[])
{
	node* root = buildTree();

	bfs_levelwise(root);
	cout << endl;

	replaceSum(root);

	bfs_levelwise(root);


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

63
23 27
1 16 13
9 7 13

*/
