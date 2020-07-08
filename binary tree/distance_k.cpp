//print the all nodes which are present at distance K from the target node
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

//print all the nodes below the target node (or chikd node) , which are present at distance K from target node
void printAtLevelK(node*root , int k) {
	if (root == NULL) {
		return;
	}

	if (k == 0) {
		cout << root->data << " ";
	}

	printAtLevelK(root->left, k - 1);
	printAtLevelK(root->right, k - 1);

	return;

}
//ancestor means root node itself
//print all the nodes above the target node (or its parent node or ancestor node) , which are present at distance K from target node
int printAtDistanceK(node*root , node*target , int k) {
	//base case
	if (root == NULL) {
		//target node is not present at that node
		return -1;
	}

	//reach the target node
	if (root == target) {
		printAtLevelK(target, k);
		return 0; //returns the distance
	}

	//next step - ancestor
	//call left substree of ancestor node and find the distance
	int DL = printAtDistanceK(root->left, target, k);

	if (DL != -1) {
		//the target node is present at the left subtree

		//2 cases:-
		//print ancestor itself or we need go to the right of the ancestor
		if (DL + 1 == k) {
			//print the ancestor itself
			cout << root->data << " ";
		}
		else {
			//got to the right hand side of the ancestor
			printAtLevelK(root->right, k - 2 - DL);
		}

		return 1 + DL; //distance to the parent
	}

	//simillar to the left subtree , but for right
	int DR = printAtDistanceK(root->right, target, k);

	if (DR != -1) {

		if (DR + 1 == k) {
			cout << root->data << " ";
		}
		else {
			printAtLevelK(root->left, k - 2 - DR);
		}

		return 1 + DR;
	}

	//node was not present in left and right subtree of given
	return -1;
}


int main(int argc, char const *argv[])
{
	node* root = buildTree();

	node*target = root->left->left;

	bfs_levelwise(root);

	// int k;
	// cin>>k;
	cout << endl;

	printAtDistanceK(root, target, 2);
	cout << endl;


	return 0;
}
/*
I/P:-
1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1

O/P:-
10 11 5 1
*/
