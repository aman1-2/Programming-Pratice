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
    //Step1: Check if root is null then we don't have to do any thing.
    if(root == NULL)    return;

    queue<Node*> qu;
    //Step2: Pushing the root node and NULL in the Queue. 
    qu.push(root);
    qu.push(NULL);

    //Step3: While loop running till the queue is not empty.
    while(!qu.empty()) {
        //Step5: Fetch the front element from the Queue and store it in a Node current variable.
        Node* curr = qu.front();
        //Step6: Once we have stored the front node in a variable pop that node from the variable. Otherwise it will just create a infinite loop.
        qu.pop();

        //Step7: If the curr node is not null then print its valid data.And if it has its right and left child then add those child in the queue.
        if(curr != NULL) {
            cout<<curr->data<<" ";

            if(curr->leftPtr)   qu.push(curr->leftPtr);
            if(curr->rightPtr)  qu.push(curr->rightPtr);
        } else {
            //Step8: If curr Node is Null in that case we need to add a line break and push the null back into the queue.
            cout<<"\n";
            if(qu.empty())  break;    
            qu.push(NULL);
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