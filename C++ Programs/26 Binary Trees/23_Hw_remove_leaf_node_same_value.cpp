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

//Passed the root of values address pointer to pointer is send in the this place with the target value
//Here we are deleting the root node therefore a reference node is taken.
void helper(Node* &root, int &target) { 
    //Base case
    if(root == NULL)    return; //If we are on the last leaf or the NULL node just don't do anything and move from there.

    //Assumption -> If we haven't reached the root node then make a call to its left and right nodes to go one level down.
    helper(root->left, target);
    helper(root->right, target);

    //Self-work -> Condition for checking if the root node is leaf node i.e. its child must be NULL and the value of the root node is equal to target in that case just delete the node and set the value NULL in it.
    if(root->left == NULL && root->right == NULL && root->data == target){
        delete(root);
        root = NULL;
    }

    return;
}

Node* removeLeafNodes(Node* root, int target) {
    helper(root, target); //Calling the helper function
    return root; //Then return the root nodes value which will have alll the leaf nodes with the target value being removed.
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = NULL;
    root->right->right = new Node(6);

    Node* newRoot = removeLeafNodes(root, 6);

    return 0;
}

/*
            1
        2       3
    4      5 N     6
N      N N  N   N     N
*/