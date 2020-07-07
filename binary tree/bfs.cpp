// time :- O(n)
//iterative approach to print the tree level wise

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

// bfs :- breadth first search
//this function gives the all level order in a single output satement
void bfs(node*root) {
	//queue is of the type node* , it stores the address of the node
	queue<node*> q;

	//first push the root in the queue and then their children
	q.push(root);

	while (!q.empty()) {
		node*f = q.front();
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

	return;

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


int main(int argc, char const *argv[])
{
	node* root = buildTree();

	bfs_levelwise(root);

	cout << endl;
	return 0;
}
/*
I/P:-
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

O/P:- bfs
8 10 3 1 6 14 9 7 13

O/P:- bfs_levelwise
8
10 3
1 6 14
9 7 13
*/
