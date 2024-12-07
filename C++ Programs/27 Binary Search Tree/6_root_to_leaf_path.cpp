/**
 * We can find out the root to path for both Binary Tree and Binary Search Tree and ther isn't any
 * such logic of separtion to find the path from root to leaf therefore this will remain same same for BT and BST.
 * 
 * For printing each path of the tree from root to leaf node we would need to atleast once travel our whole tree.
 * Therefore Time Complexity will come out to be O(n).
 */
#include<iostream>
#include<vector>
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

Node* insert(Node* root, int value) {
    if(root == NULL)    return root = new Node(value);

    if(value > root->data)  root->right = insert(root->right, value);
    else    root->left = insert(root->left, value);
}

Node* buildBTS(vector<int> &vec) {
    Node* root = NULL;
    for(int i=0; i<vec.size(); i++){
        root = insert(root, vec[i]);
    }

    return root;
}

void printPath(vector<Node*> path) {
    for(Node* ele: path) {
        cout<<ele->data<<" ";
    }
    cout<<endl;
    return;
}

void rootToLeafPath(Node* root, vector<Node*> &path) {
    //Base case: If we are on the NULL node then we don't have to do anything.
    if(root == NULL)    return;

    //Self-work: First step is to all the root node in the path.
    path.push_back(root);

    //Self-work: If we are on the leaf node then we need to print the path calculated till now.
    if(root->left == NULL && root->right == NULL) {
        printPath(path);
    }

    //Recursive call for the left and right child.
    rootToLeafPath(root->left, path);
    rootToLeafPath(root->right, path);
    //Once done with the left and right child we too need to remove the added nodes from the path vector.
    path.pop_back();
}

int main() {
    vector<int> vec = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node* root = buildBTS(vec);

    vector<Node*> path;
    rootToLeafPath(root, path);

    return 0;
}