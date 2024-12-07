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

Node* insert(Node* root, int &value) {
    if(root == NULL)    return root = new Node(value);

    if(value > root->data)  root->right = insert(root->right, value);
    else    root->left = insert(root->left, value);

    return root;
}

Node* buildBST(vector<int> &vec) {
    Node* root = NULL;
    for(int i=0; i<vec.size(); i++) {
        root = new Node(vec[i]);
    }
    return root;
}

void preorder(Node* root) {
    if(root == NULL)    return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}

void getInorder(Node* root, vector<int> &nodes) {
    if(root == NULL)    return;

    getInorder(root->left, nodes);
    nodes.push_back(root->data); //Instead of printing the data this time we are adding the data in the vector.
    getInorder(root->right, nodes);
}

Node* helperBuildBalancedBST(vector<int> &vec, int st, int ed) {
    if(st > ed) return NULL;

    int mid = st + (ed-st)/2;
    Node* curr = new Node(vec[mid]);

    curr->left = helperBuildBalancedBST(vec, st, mid-1);
    curr->right = helperBuildBalancedBST(vec, mid+1, ed);

    return curr;
}

Node* buildBalancedBST(Node* root) {
    //STEP-1: To get the inorder sequence of the vector.
    vector<int> nodes;
    getInorder(root, nodes); //Once recieved our sorted vector can pass this in buidBalancedBST helper function.

    //STEP-2: Is to call the helper function to actually build our balanced BST.
    return helperBuildBalancedBST(nodes, 0, nodes.size()-1);
}

int main() {
    Node* root = new Node(6);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);
    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);
    preorder(root);cout<<endl;

    Node* newRoot = buildBalancedBST(root);
    preorder(newRoot);cout<<endl;
    
    return 0;
}