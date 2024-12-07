/*
Approach 2: Time Complexity - O(n)
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

static int idx = -1;
Node* buildTree(vector<int> &vec) {
    idx++; 
    if(vec[idx] == -1)  return NULL;
    Node* currNode = new Node(vec[idx]);
    currNode->leftPtr = buildTree(vec);
    currNode->rightPtr = buildTree(vec);
    return currNode;
}


/**
 * Traversing the tree in the preOrder fashion.
*/
void preOrder(Node* root) {
    if(root == NULL)    return;

    cout<<root->data<<" ";
    preOrder(root->leftPtr);
    preOrder(root->rightPtr);
}


/**
 * In Pair the first value is diameter and the other value is height.
 * Basically in this function each node returns two values one is the diameter and other is height
 */
pair<int, int> diameterOfTree(Node* root) { //This function is being called n times. n* O(1)

    //Step: Talks about the base case where if the value of tree is NULL then the height and diameter it will return will to be 0.
    if(root == NULL)    return make_pair(0, 0); //This a constant time operation.

    //Step: Assuming that this function will give the information of the left and right subtrees when called. That is it will provide the value of diameter and height of the tree when asked.
    pair<int, int> leftInfo = diameterOfTree(root->leftPtr); //These are too a constant operations.
    pair<int, int> rightInfo = diameterOfTree(root->rightPtr);

    //Step: Calculating the current nodes diameter which is the addition of 1 (+1) to the sum of the left subtree height and right subtree height.
    int currDia = leftInfo.second + rightInfo.second + 1; //This is too a constant operation.
    //Step: Final diamtere is the maximum among the current diameter, left subtree diameter and right subtree diameter.
    int finalDia = max(currDia, max(leftInfo.first, rightInfo.first)); //Finding the maximum out is too a constant operation.

    //Step: Then calculating the height of the tree in the same function which is addition of 1 (+1) to the maximum value of height recieved from the left and right subtree.
    int finalHt = max(leftInfo.second, rightInfo.second) + 1; //Calculating the final height too comes out to be a constant operation

    //Step: At last just return the pair having the value final-diameter and final-height
    return make_pair(finalDia, finalHt); //Returning a value is also constant task.
}

int main() {
    vector<int> vec = {1, 2, 4, 9, 10, -1, -1, -1, -1, 5, -1, 6, -1, 7, -1, -1, 3, -1, -1};
    Node* root = buildTree(vec);

    // preOrderTraversal(root);cout<<endl;

    pair<int, int> ans = diameterOfTree(root);
    cout<<"Diameter of the tree: "<<ans.first;

    return 0;
}