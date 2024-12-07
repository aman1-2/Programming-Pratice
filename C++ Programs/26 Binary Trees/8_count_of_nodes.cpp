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

int countOfNodes(Node* root) {
    //Step1: Base case if the tree is empty or we are checking the nodes of the leaf nodes in that case just return 0.
    if(root == NULL)    return 0;

    //Step2: Making a recursive call to the left and right subtree.
    int leftNodes = countOfNodes(root->leftPtr);
    int rightNodes = countOfNodes(root->rightPtr);

    //Step3: Self work we just need to add one (+1) to the sum or count of the left and right subtrees nodes.
    return leftNodes + rightNodes + 1;
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

    int ans = countOfNodes(root);
    cout<<"Total Number of Nodes present in the tree: "<<ans;

    return 0;
}

/*
            1
        2       3
    4      5 N     6
N      N N  N   N     N
*/