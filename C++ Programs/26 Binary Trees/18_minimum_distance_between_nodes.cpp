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

Node* LCA(Node* root, int &n1, int &n2) {
    if(root == NULL)    return NULL;

    if(root->data == n1 || root->data == n2)    return root;

    Node* leftLCA = LCA(root->left, n1, n2);
    Node* rightLCA = LCA(root->right, n1, n2);

    if(leftLCA && rightLCA) return root;

    return (leftLCA==NULL) ? rightLCA : leftLCA;
}

int distFromRootToNode(Node* root, int &n) { //Time Complexity - O(n)
    //Base case : If the root is null or if we didn't find the nth node then we have to return -1. That the nth node wasn't available here.
    if(root == NULL)    return -1;

    //Checking condition or part of the self-work : Where we have to check if the root node is itself that node which we are finding then we have to simply return 0 because we are standing on that node.
    if(root->data == n)    return 0;

    //Recurssion part -> if the root node is not the nth node then we will make a call to its left and right subtree and check for the value existence there.
    int leftDist = distFromRootToNode(root->left, n); //Left subtree call
    int rightDist = distFromRootToNode(root->right, n); //Right subtree call

    //Self-work: If the nth node is not there in any of its subtree neither left or right then we have to return -1
    if(leftDist == -1 && rightDist == -1)   return -1;

    //And if found in any one of the subtrees left or right then just return the distance of that subtree by adding 1 to it which is that node's distance + 1.
    return (leftDist==-1) ? (rightDist + 1) : (leftDist + 1);


    /*The other way of doing this part could be - first making a left subtree call
    and if we just find our nth node in the left subtree then we need to just return the value from there
    otherwise we need to make a call to our right subtree and if the value is found in the right subtree then 
    we will return the answer from there only.
    And if none of the subtree gives the answer in that case we have to return -1.
    
    int leftDist = distFromRootToNode(root->left, n);
    if(leftDist) != -1) return leftDist;

    int rightDist = distFromRootToNode(root->right, n);
    if(rightDist != -1) return rightDist;

    return -1;
    */
}

int minDis(Node* root, int n1, int n2) { //Time complexity - O(n)
    if(root == NULL)    return -1;

    Node* lca = LCA(root, n1, n2); //Finding the LCA value which is the common point between the two nodes from where we can calculate the distance for the 2 nodes.
    int dist1 = distFromRootToNode(lca, n1);
    int dist2 = distFromRootToNode(lca, n2);

    return dist1 + dist2;
}

int idx = -1;
Node* buildTree(vector<int> &vec) {
    idx++;

    if(vec[idx] == -1)  return NULL;

    Node* curr = new Node(vec[idx]);
    curr->left = buildTree(vec);
    curr->right = buildTree(vec);

    return curr;
}

int main() {
    vector<int> vec = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(vec);

    int n1 = 5, n2 = 3;
    int ans = minDis(root, n1, n2);
    cout<<ans;
    return 0;
}

/*
            1
        2       3
    4      5 N     6
N      N N  N   N     N
*/