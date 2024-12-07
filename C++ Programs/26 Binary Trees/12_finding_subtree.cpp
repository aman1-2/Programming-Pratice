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

bool isIdentical(Node* root1, Node* root2) {
    /**
     * The base in the binary tree most of the base case is related to NULL. When both the root nodes root1 and root2 are NULL in that we just need to return true as both don't have nothing.
     * Other case when either of the root nodes root1 or root2 becomes NULL. It returns false.
     */
    if(root1 == NULL && root2 == NULL)  return true;
    else if(root1 == NULL || root2 == NULL)  return false;

    //First check which we have to make if any of the root nodes data is not equal just return false
    if(root1->data != root2->data)  return false;

    //Then make a check for its left part and right part both of the left and right part must be equal to form the right answer.
    return (isIdentical(root1->leftPtr, root2->leftPtr) && isIdentical(root1->rightPtr, root2->rightPtr));
}

bool isSubTree(Node* root, Node* subRoot) {
    /*One of the base condition let's say both the root and subRoot value provided our NULL in that case both the root tree and 
    subRoot tree will be empty or won't have any nodes and empty things are always equal therefore if both the values are null 
    in that case we have to return true.*/
    if(root == NULL && subRoot == NULL) return true;
    else if(root == NULL || subRoot == NULL) return false; /*Base case - if any one of the value root or subRoot is null then 
    the overall result will be false as finding a null match with some valid values will always give false.*/

    if(root->data == subRoot->data) {
        if(isIdentical(root, subRoot)){
            return true;
        }
    }

    //If we just find out our subRoot inside the left part it will return true. we just need to save that return value and return true if its in the left part.
    int leftSubtree = isSubTree(root->leftPtr, subRoot); //subRoot is the searching element that's why it is same.

    //Let's say the left part returns a false value then we have to make a check in the right side.
    if(!leftSubtree) {
        //Returning the right subtree value if its not in left subtree.
        return isSubTree(root->rightPtr, subRoot); //subRoot is the searching element that's why it is same.
    }

    return true; //Return true if we got the match in the left part as right part has its own return statement.
}

int main() {
    Node* root = new Node(1);
    root->leftPtr = new Node(2);
    root->rightPtr = new Node(3);
    root->leftPtr->leftPtr = new Node(4);
    root->leftPtr->rightPtr = new Node(5);
    root->rightPtr->rightPtr = new Node(6);

    Node* subRoot = new Node(2);
    subRoot->leftPtr = new Node(4);
    subRoot->rightPtr = new Node(5);

    bool ans = isSubTree(root, subRoot);
    cout<<"Is there an identical subtree: "<<ans;

    return 0;
}

/*
            1
        2       3
    4      5 N     6
N      N N  N   N     N
*/