/**
 * This Approach gives a Time complexity of O(n).
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

/**
 * This class is made for validating that whether a branch or the binary tree is BST or not and at each node will be providing these information for further calculation of maxSum in the BST.
 */
class Info {
    public: 
        bool isBST;
        int min;
        int max;
        int sum;

        Info(bool isBST, int min, int max, int sum) {
            this->isBST = isBST;
            this->min = min;
            this->max = max;
            this->sum = sum;
        }
};

static int maxSum = 0; //A global variable for storing the maxSum of valid BST's.
/**
 * Helper function which will help us to calculate the sum of all the nodes in a Valid BST.
 * This helper function will get the information for each node and with the help of those information it will try to calculate the maxSum of the valid BST.
 */
Info* helper(Node* root) {
    //BASE CASE: If the root node is NULL then it means it a valid BST because a single node or even the empty bst is a valid BST.
    //Therefore we will return a true value with min as INT_MAX and max as INT_MIN and sum as 0 as it is NULL or empty.
    if(root == NULL)    return new Info(true, INT_MAX, INT_MIN, 0);

    //ASSUMPTION: Assuming that it will provide us the correct leftInfo and rightInfo for the Nodes. So does we will to return the currNodes Info.
    Info* leftInfo = helper(root->left);
    Info* rightInfo = helper(root->right);

    //SELF-WORK: for the current node we need to calculate the values of min, max, sum, isBST to provide or return to the parent node.
    int currMin = min(root->data, min(leftInfo->min, rightInfo->min)); //The samallest value of the subtree will be returned from the whole subtree.
    int currMax = max(root->data, max(leftInfo->max, rightInfo->max)); //The largest value of the subtree will be returned from the whole subtree.
    int currSum = leftInfo->sum + rightInfo->sum + root->data; //Calculating the sum of all the nodes till the current node. If it comes out to be a valid BST then we will have make a such with maxSum and update accordingly.
    
    //Validating logic for checking if its a BST or not.
    bool isBST = false;
    //For being a BST its left and right subtree's too must be a BST and then current node must be greater then the maximum value from the leftSubtree and lesser then the minimum value of the right subtree.
    if(leftInfo->isBST && rightInfo->isBST && root->data > leftInfo->max && root->data < rightInfo->min){
        isBST = true; //If comes out to be a valid BST.
        maxSum = max(maxSum, currSum); //Then make a comparison for the maxSum.
        return new Info(isBST, currMin, currMax, currSum); //And return the Info for the current node with the values isBST, currMin, currMax, and currSum.
    }

    //And if doesn't validates it self as BST then return isBST as false with rest of the value same.
    return new Info(false, currMin, currMax, currSum);
}

int maxSumBST(Node* root) {
    Info* ansInfo = helper(root); //calling the helper function.
    return maxSum; //Returning the maxSum value.
}

int main() {
    // Node* root = new Node(1);
    // root->left = new Node(4);
    // root->right = new Node(3);
    // root->left->left = new Node(2);
    // root->left->right = new Node(4);
    // root->right->left = new Node(2);
    // root->right->right = new Node(5);
    // root->right->right->left = new Node(4);
    // root->right->right->right = new Node(6);

    Node* root = new Node(4);
    root->left = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(2);

    cout<<maxSumBST(root);

    return 0;
}