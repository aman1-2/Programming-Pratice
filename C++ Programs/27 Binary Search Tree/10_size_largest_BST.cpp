/**
 * For calculating the size of the largest BST what we does is:-
 * (i) We first try to define the class Info in which we will provide the following information for all Node.
 * Properties of class Info :
 * -> isBST - boolean type for checking whether its subtree are BST or not.
 * -> min - for calculating the minimum of the current BT.
 * -> max - for calculating the maximum of the current BT.
 * -> size - for calculating the height of the BT at the current node.
 */
#include<iostream>
#include<climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        this->data = value;
        this->left = this->right = NULL;
    }
};

class Info {
public:
    bool isBST;
    int min;
    int max;
    int size;

    Info(bool isBST, int min, int max, int sz) {
        this->isBST = isBST;
        this->max = max;
        this->min = min;
        this->size = sz;
    }
};

static int maxSize = 0;
static Node* largestBSTRoot;

//Since its a recursive function then we can assume if it is providing us the correct value for our current node then it will too provide us the correct value for the right and left node. 
Info* largestBST(Node* root) {
    //BASE CASE: This we can imagine it like we have to find the largest BST but are given 
    //a whole empty tree without any node. Here we cann't directly return NULL. Because at 
    //every level we are getting the Info for not NULL and checking a validate value from it.
    //If we return NULL here in that case we would then have to check for the not  NULL condition everywhere,therefore we return a validate Info
    if(root == NULL) {
        return new Info(true, INT_MAX, INT_MIN, 0); //Since we are on the lead node it will be a valid BST the min and max value for the info is INT_MIN and INT_MAX valid values becuase at each call we are making a comparison and size here is 0.
        //The reason of sending minimum as maximum is if we will send maximum then only the root data will be minimum from Max value.
    }

    //We can also have one other base case for the leaf node as
    // if(root == NULL) return NULL;
    // if(root->left == NULL && root->right == NULL)   return new Info(true, root->data, root->data, 1);

    //STEP 1: We will make a call to the left and right node and in return it will provide us the left and right Info.
    Info* leftInfo = largestBST(root->left);
    Info* rightInfo = largestBST(root->right);

    //STEP 2: Now we have to make our current Info and for that we need 4 values.
    int currMin = min(root->data, min(leftInfo->min, rightInfo->min)); //Current minimum is the minimum value from the left and right subtree including the self value.

    int currMax = max(root->data, max(leftInfo->max, rightInfo->max)); //Current maximum is the maximum value from the right and left subtree including the self value. 

    int currSize = leftInfo->size + rightInfo->size + 1; //Current size is the height of the tree form the current node which is height of the left subtree + height of the right subtree + 1.

    bool currIsBST = false; //For being BST we need to again validate the 4 conditions that is first place its subtree must to be a BST then secondly the current node value must be greater then the maximum value of the left subtree and it must be lesser then the minimum value of the right subtree.
    if(leftInfo->isBST && rightInfo->isBST && 
     root->data > leftInfo->max && 
     root->data < rightInfo->min) {
        currIsBST = true;
        if(currSize > maxSize) largestBSTRoot = root;
        maxSize = max(maxSize, currSize);
        return new Info(currIsBST, currMin, currMax, currSize);
    }

    //Now if it's not a valid BST then we will just return false and the Info will be.
    return new Info(false   , currMin, currMax, currSize);
}

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(20);
    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    largestBST(root);
    cout<<maxSize<<endl;
    cout<<largestBSTRoot->data;

    return 0;
}