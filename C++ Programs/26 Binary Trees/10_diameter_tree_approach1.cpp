/*
Approach 1: Time Complexity - O(n^2)
*/

#include<iostream>
#include<vector>
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

static int idx = -1; //For tracking the index of the vector.

Node* buildTree(vector<int> vec){
    idx++;

    //Base Case
    if(vec[idx] == -1)  return NULL;
    /*Step1: To create a node where we will attach its child node if any. This is our 
    self-work. Since this tree creation is based on the preorder traversal we are creating 
    node first and then calling the left subtree and first creating the left subtree then 
    the right subtree creation starts.*/
    Node* currNode = new Node(vec[idx]);
    currNode->leftPtr = buildTree(vec);
    currNode->rightPtr = buildTree(vec);

    return currNode;
}

int height(Node* root) {
    if(root == NULL)    return 0;

    int leftHt = height(root->leftPtr);
    int rightHt = height(root->rightPtr);

    return max(leftHt, rightHt) + 1;
}

int diameterOfTree(Node* root) {
    //Step: The base case in any scenario if we have no node, in that the diameter will be 0.
    if(root == NULL)    return 0;

    //Step: We just calculate the diameter for the current node and this is that diameter 
    //which will pass through the root node but it is not necessary that it will be the answer.
    int currDia = height(root->leftPtr) + height(root->rightPtr) + 1;
    //Step: In a similar fashion we will try to find out our left subtree's diameter.
    int leftDia = diameterOfTree(root->leftPtr);
    //Step: In a similar we will have a call for finding the diameter of the right subtree.
    int rightDia = diameterOfTree(root->rightPtr);

    //Step: Giving or returning back the maximum of current diameter, left diameter and right diameter.
    return max(currDia ,max(leftDia, rightDia));
}

void preOrderTraversal(Node* root) {
    if(root == NULL)    return;

    cout<<root->data<<" ";
    preOrderTraversal(root->leftPtr);
    preOrderTraversal(root->rightPtr);
}

int main() {
    vector<int> vec = {1, 2, 4, 9, 10, -1, -1, -1, -1, 5, -1, 6, -1, 7, -1, -1, 3, -1, -1};
    Node* root = buildTree(vec);

    // preOrderTraversal(root);cout<<endl;

    int ans = diameterOfTree(root);
    cout<<"Diameter of the tree: "<<ans;

    return 0;
}
