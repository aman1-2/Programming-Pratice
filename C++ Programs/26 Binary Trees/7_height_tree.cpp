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

int height(Node*root) {
    if(root == NULL)    return 0;

    int leftHt = height(root->leftPtr);
    int rightHt = height(root->rightPtr);

    int currHt = max(leftHt, rightHt) + 1;
    
    return currHt;
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

    int ans = height(root);
    cout<<"Height of the tree is: "<<ans;

    return 0;
}

/*
            1
        2       3
    4      5 N     6
N      N N  N   N     7
                    N   N
*/