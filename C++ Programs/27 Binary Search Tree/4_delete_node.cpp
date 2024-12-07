/**
 * Before deleting a node from the BST we first need to find the presence of that node im the BST.
 * Once we reach at the node whose value we have to delete we just implement the 3 cases for deleting the node.
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

Node* insert(Node* root, int &value) {
    if(root == NULL)    return root = new Node(value);

    if(value < root->data)  root->left = insert(root->left, value);
    else    root->right = insert(root->right, value);

    return root;
}

Node* buildBST(vector<int> &vec) {
    Node* root = NULL;
    for(int i=0; i<vec.size(); i++) {
        root = insert(root, vec[i]);
    }

    return root;
}

void inorder(Node* root) {
    if(root == NULL)    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* inorderSuccessor(Node* root) {
    while(root->left != NULL)   root = root->left;
    return root; //Inorder successor.
}

Node* deleteNode(Node* root, int deleteKey) {
    if(root == NULL)    return NULL;

    //STEP-1: Searching Phase 
    //If the deleting node is less then the root node then we have to find it in the left subtree. And this will return us the updated left value of the root.
    if(deleteKey < root->data)  root->left = deleteNode(root->left, deleteKey);
    else if(deleteKey > root->data) root->right = deleteNode(root->right, deleteKey); //If deleting root is more then the root node then we have to find the deleting node in the right subtree. And this will return us the updated right value of the root.
    else {
        //STEP-2: Here we have to handle the three cases of deleting a node in the BST
        //Inside else part we are standing on the node which we want to delete.

        //CASE 1: Deleting node having 0 child node.
        if(root->left == NULL && root->right == NULL){ //So its a leaf node
            delete(root);
            return NULL;
        }

        //CASE 2: Having 1 child node either on the left or right side.
        if(root->left == NULL || root->right == NULL) { //If any of the root left or right is NULL then we have to return the one which has valid value in it.
            return (root->left == NULL) ? root->right : root->left;
        }

        //CASE 3: Having both 2 child node of the deleting node.
        //We don't need any such if condition for case 3 because if the root was of 0 or 1 child node then it would have returned from the above two cases if its reaching till here then this means its the case of case 3.
        //First thing in case 3 is getting the inorder successor of the root. For that we will pass the root->right value because in that only we need to find out the left most value in the right subtree.
        Node* IS = inorderSuccessor(root->right);
        //Replacing the root data with the inorderSuccessor data.
        root->data = IS->data;
        //And then finally we will call the deleteNode for our Inorder successor.
        root->right = deleteNode(root->right, IS->data); //Here we have to make sure that we don't pass our root node as we have stored the IS data in the root too therefore passing the root here will make a infinite loop 
        //as root will have 2 children therefore we pass the root->right here as the root node to delete the next node from the root->right subtree.
        return root; 
    }

    return root; //If the value to be deleted doesn't exsits in the BST in that case we just need to return back the original root without any changes in it.
}

int main() {
    vector<int>  vec = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node* root = buildBST(vec);
    inorder(root);
    cout<<endl;
    deleteNode(root, 15);

    inorder(root);
    cout<<endl;

    return 0;
}