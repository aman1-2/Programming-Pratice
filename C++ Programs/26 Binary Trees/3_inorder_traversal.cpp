#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* leftPtr;
    Node* rightPtr;

    Node(int value) {
        this->data = value;
        this->leftPtr = this->rightPtr = NULL;
    }
};

void inorderTraversal(Node* root) {
    if(root == NULL)    return;

    //Step1: Calling the left subtree.
    inorderTraversal(root->leftPtr);

    //Step2: Printing the root node value.
    cout<<root->data<<" ";

    //Step3: Calling the right subtree.
    inorderTraversal(root->rightPtr);
}

