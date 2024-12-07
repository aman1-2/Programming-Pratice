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

void preorder(Node* root) {
    if(root == NULL)    return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

    return;
}

Node* insert(Node* root, int &value) {
    if(root == NULL)    return root = new Node(value);

    if(value > root->data)  root->right = insert(root->right, value);
    else    root->left = insert(root->left, value);

    return root;
}

Node* buildBST(vector<int> &vec) {
    Node* root = NULL;
    for(int i=0; i<vec.size(); i++){
        root = insert(root, vec[i]);
    }

    return root;
}

Node* inorderSuccessor(Node* root) {
    while(root->left != NULL) {
        root = root->left;
    }

    return root;
}


int main() {
    vector<int> vec = {5, 1, 3, 4, 2, 7};
    Node* root = buildBST(vec);
    cout<<root->data<<endl;
    preorder(root);
    cout<<endl;
    Node* ans = inorderSuccessor(root);
    cout<<ans->data;
    cout<<endl;

    return 0;
}