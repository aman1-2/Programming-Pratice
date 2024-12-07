#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        this->data = value;
        this->left = this->right = NULL;
    }
};

void levelOrderTraversal(Node* root) {
    if(root == NULL)    return;

    queue<Node*> qu;
    qu.push(root);
    qu.push(NULL);

    while(!qu.empty()) {
        Node* curr = qu.front();
        
        qu.pop();

        if(curr != NULL) {
            cout<<curr->data<<" ";

            if(curr->left)   qu.push(curr->left);
            if(curr->right)  qu.push(curr->right);
        } else {
            cout<<"\n";
            if(qu.empty())  break;    
            qu.push(NULL);
        }
    }
}

int idx = -1;
Node* buildTree(vector<int> &vec) {
    idx++;

    if(vec[idx] == -1)    return NULL;

    Node* curr = new Node(vec[idx]);
    curr->left = buildTree(vec);
    curr->right = buildTree(vec);

    return curr;
}

/**
 * This function will return the current nodes old value before it gets tranformed for futher usage.
 * We have inbuilt change the value of each to its left and right sutrees nodes values.
 */
int sumTransformTree(Node* root) { //Time-Complexity is O(n) because we have to go to each node to transform the value.
    //Base case if we find anywhere a NULL value we just need to return 0.
    if(root == NULL)    return 0;

    //Assuming that if the recursive function will tranform the current root node value then it could also tranform its child nodes or subtree.
    int leftOld = sumTransformTree(root->left); 
    int rightOld = sumTransformTree(root->right);

    //This will save the old value of the root node which we have to return at the end of the function.
    int currOld = root->data;

    //Firstly we are just adding the old values of the left and right node. (For the case of leaf node because acessing null could give error).
    root->data = leftOld + rightOld;

    //If anyone of the left or right node is null then we don't need to add it. We need to add it only if there non-null value in the left and right side.
    if(root->left != NULL)  root->data += root->left->data;
    if(root->right != NULL)  root->data += root->right->data;

    //Returning the old value of the current node.
    return currOld;
}

int main() {
    vector<int> vec = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(vec);

    int ans = sumTransformTree(root);

    levelOrderTraversal(root);

    return 0;
}

/*
            1
        2       3
    4      5 N     6
N      N N  N   N     N
*/