#include<iostream>
#include<queue>
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

void levelOrderTraversal(Node* root) {
    if(root == NULL)    return;
    
    queue<Node*> qu;
    qu.push(root);

    while(!qu.empty()) {
        Node* curr = qu.front();
        qu.pop();
        cout<<curr->data<<" ";

        if(curr->leftPtr) {
            qu.push(curr->leftPtr);
        }
        if(curr->rightPtr) {
            qu.push(curr->rightPtr);
        }
    }

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

    levelOrderTraversal(root);

    return 0;
}

/*
            1
        2       3
    4      5 N     6
N      N N  N   N     N
*/