#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* leftPtr;
    Node* rightPtr;

    Node(int data) {
        this->data = data;
        leftPtr = rightPtr = NULL; 
    }
};

/**
 * This tree creation is based on the pre-order traversal method.
*/
//Tracking the index of the vector for node and tree creation.
static int idx = -1; //Why static because we want that this idx varaible should increment its value as we move up in the tree or down in the tree.

Node* buildTree(vector<int> &vec) {
    //Increasing the indx value before creation of the node in the tree to fetch the current value for node creation from the vector.
    idx++; //Since its a static variable our idx value will increase no matter if we go up in the tree or down.

    //Base case if -1 value available this means its NULL node.
    if(vec[idx] == -1)  return NULL;

    //Self-work -> Node creation
    //Step2: creating a new node for our tree.
    Node* currNode = new Node(vec[idx]);

    //Assumption -> Assuming that it will build the tree of the left and right subtree we just need to make the current node.
    currNode->leftPtr = buildTree(vec); // Will return the pointer of left subtree which will get attached to left side of the tree.
    currNode->rightPtr = buildTree(vec);// Will return the pointer of right subtree which will get attached to right side of the tree.

    return currNode;
}

void preOrderTraversal(Node* root) {
    if (root == NULL)   return;

    cout<<root->data<<" ";
    preOrderTraversal(root->leftPtr);
    preOrderTraversal(root->rightPtr);    
}

int main() {
    vector<int> vec = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(vec); //It should have value 1 i.e. root data must be 1.

    cout<<root->data<<endl;

    preOrderTraversal(root);
    return 0;
}

/*
            1
        2       3
    4      5 N     6
N      N N  N   N     N
*/