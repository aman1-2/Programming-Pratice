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

Node* arrayToBalanceBST(vector<int> &vec, int st, int ed) {
    //BASE CASE: If the start value becomes more than the end value in that case we just need to return NULL as we are returning a Node* type pointer.
    //Here we aren't specifying st>=ed because there can be a point where start and end both points to the same element.
    if(st > ed)    return NULL;

    //SELF-WORK: To find the mid value and create the curr node for the BST.
    int mid = st + (ed-st)/2;
    Node* curr = new Node(vec[mid]);

    //ASSUMPTION: That it will create a BST for left subtree and right subtree.
    curr->left = arrayToBalanceBST(vec, st, mid-1);
    curr->right = arrayToBalanceBST(vec, mid+1, ed);

    return curr; //At the end returning the curr node as the root node of the balance BST.
}

void inorder(Node* root) {
    if(root == NULL)    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

    return;
}

int main() {
    vector<int> vec = {3, 4, 5, 6, 7, 8, 9};
    Node* root = arrayToBalanceBST(vec, 0, vec.size()-1);
    cout<<root->data<<endl;
    inorder(root);
    return 0;
}