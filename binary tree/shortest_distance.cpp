
// Shortest Distance Between Nodes Of A Binary Tree
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
//finding level of a given node from the root node/any given node
int search(node*root , int key , int level) {
	if (root == NULL) {
		return -1;
	}

	if (root->data == key) {
		return level;
	}

	int left = search(root->left , key , level + 1);
	if (left != -1) {
		return left;
	}

	return search(root->right , key , level + 1);
}

//function to find distance btw 2 nodes
int findDistance(node*root , int a , int b) {
	node*lca_node = lca(root, a, b); //gives lca

	int l1 = search(lca_node, a, 0);
	int l2 = search(lca_node, b, 0);

	return l1 + l2;
}

int main(int argc, char const *argv[])
{
	node* root = buildTree();

	cout << "distance btw 4 and 7 " << findDistance(root, 4, 7) << endl;
	cout << "distance btw 6 and 9 " << findDistance(root, 6, 9) << endl;



	return 0;
}
/*
I/P:-
1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1

O/P:-
distance btw 4 and 7 1
distance btw 6 and 9 4
*/
