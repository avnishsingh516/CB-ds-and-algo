#include <iostream>
#include<queue>
using namespace std;

class node {
public:
    int data;
    node*left;
    node*right;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void bfs(node *root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node* f = q.front();
        if (f == NULL) {
            cout << endl;
            q.pop();
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << f->data << ",";
            q.pop();

            if (f->left) {
                q.push(f->left);
            }
            if (f->right) {
                q.push(f->right);
            }
        }
    }
    return;
}



node* createTreeFromInAndPre(int *in, int *pre, int s, int e) {
    //pre:- preorder array , in:- inorder array , s:- starting index , e:- last index
    // we dont want to traverse back to index 0 again and again ...
    static int i = 0;

    //Base Case
    if (s > e) {
        //there is only single element
        return NULL;
    }

    //Rec Case
    node *root = new node(pre[i]);

    // pick one data from preorder array and find it in inorder aaray
    int index = -1;
    for (int j = s; s <= e; j++) {

        //find the element in inorder array
        if (in[j] == pre[i]) {
            index = j;
            break;
        }
    }

    i++;
    root->left = createTreeFromInAndPre(in, pre, s, index - 1);
    root->right = createTreeFromInAndPre(in, pre, index + 1, e);
    return root;
}



int main() {
    int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
    int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
    int n = sizeof(in) / sizeof(int);

    node*root = createTreeFromInAndPre(in, pre, 0, n - 1);
    bfs(root);


    return 0;
}