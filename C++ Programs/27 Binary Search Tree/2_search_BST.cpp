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

bool searchBST(Node* root, int &searchKey) { //Time Complexity -> O(height)
    //Base case: If we are on the leaf node or the tree is empty in that case, it will return a false.
    if(root == NULL) return false;
    //Self-work: If the root is only the search key return true.
    if(root->data == searchKey)    return true;
    //Assumption: If root isn't the search key then find it in either of the two sides depending upon the search key value.
    if(searchKey < root->data)  searchBST(root->left, searchKey);
    else  searchBST(root->right, searchKey);
}

Node* insert(Node* root, int value) {
    if(root == NULL)    return root = new Node(value);

    if(value < root->data)  root->left = insert(root->left, value);
    else    root->right = insert(root->right, value);

    return root;
}

Node* buildBST(int arr[], int n) {
    Node* root = NULL;

    for(int i=0; i<n; i++) {
        root = insert(root, arr[i]);
    }

    return root;
}

int main() {
    int arr[] = {5, 1, 3, 4, 2, 7};
    Node* root = buildBST(arr, 6);

    int searchKey = 9;
    bool ans = searchBST(root, searchKey);
    cout<<ans<<" ";
    return 0;
}