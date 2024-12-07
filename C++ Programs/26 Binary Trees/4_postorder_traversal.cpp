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

void postOrderTraversal(Node* root) {
    if(root == NULL)    return;

    //Step1: Calling the left subtree.
    postOrderTraversal(root->leftPtr);

    //Step3: Calling the right subtree.
    postOrderTraversal(root->rightPtr);

    //Step2: Printing the root node value.
    cout<<root->data<<" ";
}

int main() {
    Node* root = new Node(1);
    root->leftPtr = new Node(2);
    root->rightPtr = new Node(3);
    root->leftPtr->leftPtr = new Node(4);
    root->leftPtr->rightPtr = new Node(5);
    root->rightPtr->leftPtr = NULL;
    root->rightPtr->rightPtr = new Node(6);
    root->rightPtr->rightPtr->leftPtr = NULL;
    root->rightPtr->rightPtr->rightPtr = NULL;
    root->leftPtr->leftPtr->rightPtr = NULL;
    root->leftPtr->rightPtr->leftPtr = NULL;
    root->leftPtr->rightPtr->rightPtr = NULL;

    postOrderTraversal(root);

    return 0;
}

/*
            1
        2       3
    4      5 N     6
N      N N  N   N     N
*/