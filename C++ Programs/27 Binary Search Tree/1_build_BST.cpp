#include<iostream>
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

/**
 * A recursive insert function for adding the Node in the BST.
 */
Node* insert(Node* root, int value) { //Time Complexity of Insert function is O(log n). For inserting a single Node
    //Base case: If the root is NULL then this means we need to create a new node and return the value of the root only.
    if(root == NULL)    return root = new Node(value);

    //Self-work: If the root is not NULL and a value is passed to us then we need to first find out the correct position for that value to be inserted in the BST.
    //In short we have to search for the appropiate position and where we will find the appropiate position there it will have a NULL value and the node will be inserted at that position.
    if(value < root->data)  root-> left = insert(root->left, value);  //Left subtree case.
    else    root->right = insert(root->right, value); //Right Subtree case.

    //The value can be either lesser or greater then the root node. They value cann't be equal to root node as BST has unique values in it.

    return root;
}

/**
 * This buildBST function takes an array of values and a builds a BST out of the values given.
 * And at the end returns the root of the BST at the end of the function. That's why its return type is Node*.
 * n here is the size of the array.
 */
Node* buildBST(int arr[], int n) { //Time complexity will be O(n log n) not exactly because each time the size of the tree is changing.
    //What buildBSt does is it tries to travel one by one each value of the array and tries to build the node.
    //STEP 1: At starting we have created a root with the value NULL in it.
    Node* root = NULL;
    for(int i=0; i<n; i++) {
        //STEP 2: Is running a loop which will traverse the value of BST one by one.
        root = insert(root, arr[i]); //This insert function will insert the node at its correct position and return us the new root value which we will just update in the root variable.
    }
    //STEP 3: And finally just returning our root Node.
    return root;
}

void inorder(Node* root) {
    if(root == NULL)    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

    return;
}

int main() {
    int arr[] = {5, 1, 3, 4, 2, 7};

    Node* root = buildBST(arr, 6); //This function will return us the root value of the BST Tree.

    inorder(root);

    return 0;
}