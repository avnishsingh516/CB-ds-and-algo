//lowest common ancestor (lca)
//an ancestor node which is common for both node a and node b

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

//assumption both a and b are present in the tree , all keys are unique also
node* lca(node*root , int a , int b) {
	if (root == NULL) {
		return NULL;
	}

	if (root->data == a or root->data == b) {
		return root;
	}

	//search in left and right subtrees
	node* leftans = lca(root->left, a, b);
	node* rightans = lca(root->right, a, b);

	if (leftans != NULL and rightans != NULL) {
		//lca is current node
		return root;
	}

	//one node was found at left and right node not found yet
	if (leftans != NULL) {
		return leftans;
	}
	//else
	return rightans;

}


int main(int argc, char const *argv[])
{
	node* root = buildTree();

	node* common = lca(root, 5, 7);

	cout << common->data << endl;


	return 0;
}
/*
I/P:-
1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1

O/P:-
2
*/
