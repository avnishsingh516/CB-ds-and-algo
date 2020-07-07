// time :- O(n)
//bottom up approach
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


class HBPair {
public:
	int height;
	bool balance;
};

//returns the is tree id balanced or not
HBPair isHeightBalance(node *root) {
	HBPair p;
	if (root == NULL) {
		p.height = 0;
		p.balance = true;
		return p;
	}
	//Recurisve Case postorder traversal
	HBPair left = isHeightBalance(root->left);
	HBPair right = isHeightBalance(root->right);

	//calculate height of current node
	p.height = max(left.height, right.height) + 1;

	// for balanced tree , the difference of the height of the left and right tree is not greater than 1
	//and both left and right child must be balanced
	if (abs(left.height - right.height) <= 1 && left.balance && right.balance) {
		p.balance = true;
	}
	else {
		p.balance = false;
	}
	return p;
}

int main(int argc, char const *argv[])
{
	node* root = buildTree();

	if (isHeightBalance(root).balance) {
		cout << "Balanced" << endl;
	}
	else {
		cout << "Not a Balanced Tree" << endl;
	}


	return 0;
}
/*
I/P:-
8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

O/P:-
not balanced
*/
