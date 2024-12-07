#include<iostream>
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

int search(Node* root, int &k) {
    //Base Case: This signifies we are at the end of the tree without finding the smallest kth element and in that case we have to return -1.
    if(root == NULL)    return -1;

    //Assumption: Making a recursive call to left subtree and assuming it will give us the correct answer. We have made left call first because in inorder traversal we make left call first only.
    int leftVal = search(root->left, k);

    //Self-Work: If the leftVal is not equal to -1 then it means we have found our kth smallest element and we can return it back without further continuation.
    if(leftVal != -1)   return leftVal;

    //If not found yet then we see wether we are standing on the kth smallest element or not. If k is equal to 0 then it means we are on the root value whose value has kth smallest value. And at each comparison we just go on decreasing the value of k.
    k--;
    if(k == 0)  return root->data;

    //If the kth smallest element is not found in left subtree then we check its presence in the right subtree.
    return search(root->right, k);
}

int kthSmallest(Node* root, int k) {
    return search(root, k);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);

    root->left->left = new Node(2);
    root->left->right = new Node(4);

    root->left->left->left = new Node(1);

    cout<<kthSmallest(root, 1);

    return 0;
}