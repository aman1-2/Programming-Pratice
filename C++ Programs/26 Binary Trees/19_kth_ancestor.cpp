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

int idx = -1;
Node* buildTree(vector<int> &vec) {
    idx++;

    if(vec[idx] == -1)    return NULL;

    Node* curr = new Node(vec[idx]);
    curr->left = buildTree(vec);
    curr->right = buildTree(vec);

    return curr;
}

/**
 * One thing to note here is that since we from this function we aren't return the value of the kthAncestor.
 * We are calculating the distance from the root to the given node
 * And in the process we just print the value of the kthAncestor node.
 */
int kthAncestor(Node* root, int &node, int &kth) { //Time Complexity is O(n)
    //Base case if we are at the end of a node that is that node is NULL just return -1 and if the function was a Node return type then we would have to return NULL instead of -1.
    if(root == NULL)    return -1;

    //First check if the node passed matches with the root node then return 0 as we are standing onthat node.
    if(root->data == node)  return 0;

    //If root node is not that node then check in its left and right subtrees.
    int leftDis = kthAncestor(root->left, node, kth);
    int rightDis = kthAncestor(root->right, node, kth);

    //if both of the left and right subtree have returned -1 in that case the node is not found and we too have to return -1.
    if(leftDis == -1 && rightDis == -1) return -1;

    //If any of the subtree has found the node then we have to add 1 (+1) to its value and then return back.
    int validAns = (leftDis == -1) ? rightDis+1 : leftDis+1;

    //If the validAns matches with the kth value this means we are at the kthAncestor position and we have to do nothing just print the value of the current root node.
    if(validAns == kth) cout<<root->data;

    return validAns; //At last if it is not equal to kth value then just return 
    //the validAns. Once again telling that this function is to calculate the distance 
    //between the root to a particular node distance we at the kth position we are just printing the answer.
}

int main() {
    vector<int> vec = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(vec);

    int node = 6, kth = 2;
    int ans = kthAncestor(root, node, kth);
    return 0;
}

/*
            1
        2       3
    4      5 N     6
N      N N  N   N     N
*/