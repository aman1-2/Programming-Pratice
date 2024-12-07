/**
 * For Validating that if a tree is BST or not. We need to check these two conditions:
 * (i) left subtree nodes must be lesser then the root node.
 * (ii) right subtree nodes must be greater then the root node.
 * If these two conditions are true for each node in the tree, then we can say its a Valid BST otherwise an Invalid BST.
 * 
 * A wrong approach which we use many times :-
 * that we compare the root node value that is root node value must be greater then the root->left value and lesser than the root->right value this comparison is absolutely wrong for validation BST.
 * The above approach fails because we use to compare the root value with the child node only but the correct eay is too compare the root value with complete subtrees.
 * 
 * Validation condition for a BST :-
 * (i) node > maxValue in the leftSubtree
 * (ii) node < minValue in the rightSubtree
 * 
 * For checking if a BST is a valid BST or not we make sure that each node's value lies within a range of value therefore logic of min max will be applied over here.
 */

#include<iostream>
#include<vector>
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

Node* insert(Node* root, int &value) {
    if(root == NULL)    return root = new Node(value);

    if(value > root->data)  root->right = insert(root->right, value);
    else    root->left = insert(root->left, value);

    return root;
}

Node* buildBST(vector<int> &vec) {
    Node* root = NULL;
    for(int i=0; i<vec.size(); i++) {
        root = insert(root, vec[i]);
    }

    return root;
}

bool validateHelper(Node* root, Node* min, Node* max) {
    //BASE CASE: If our root node is only NULL in that case we don't need to do anything and we can simply return thr true value from there.
    if(root == NULL)    return true;

    //If minimum is not NULL and root value somehow becomes less then minimum in that case we just need to return false as it has gone out of bound.
    if(min != NULL && root->data < min->data)   return false; 
    //If the root data goes out of bond for max data then we will return false from here too
    if(max != NULL && root->data > max->data)   return false;

    //If both these calls returns a true value then only we need to return a true vlaue.
    return validateHelper(root->left, min, root) && validateHelper(root->right, root, max);
}

bool validateBST(Node* root) {
    return validateHelper(root, NULL, NULL);
}

int main() {
    vector<int> vec = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node* root = buildBST(vec);
    root->data = 15; //For validating its not a validate BST we can switch the value of the 8 to 15.

    bool ans = validateBST(root);
    cout<<ans;
    cout<<endl;

    return 0;
}