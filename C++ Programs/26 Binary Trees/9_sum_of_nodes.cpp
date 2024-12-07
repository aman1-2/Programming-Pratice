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

int sumOfNodes(Node* root) {
    if(root == NULL)    return 0;

    int leftSum = sumOfNodes(root->leftPtr);
    int rightSum = sumOfNodes(root->rightPtr);

    int currSum = leftSum + rightSum + root->data;

    return currSum;
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

    int ans = sumOfNodes(root);
    cout<<"Sum of all nodes of the tree: "<<ans;

    return 0;
}

/*
            1
        2       3
    4      5 N     6
N      N N  N   N     N
*/