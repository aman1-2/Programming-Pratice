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

/**
 * Here Time Complexity will be O(n) and Space Complexity will be O(1) as we are going on each node only once.
 */
Node* LCA(Node* root, int &n1, int &n2) {
    //Base case if we are on the NULL node then just return null from there.
    if(root == NULL)    return NULL;

    //One condition check - if any of the nodes we are searching matches with the root node then return the root ndoe.
    if(root->data == n1 || root->data == n2)  {
        return root;
    }

    //If the nodes doesn't matches with the root node then make a call to its subtree.
    Node* leftLCA = LCA(root->left, n1, n2); //Making a left-subtree call and storing its value.
    Node* rightLCA = LCA(root->right, n1, n2); //Making a right-subtree call and storing its value.

    if(leftLCA && rightLCA) return root; //A condition check if both of its left and right subtree has a valid value then return the root node.
    
    //Other case could be if any of the subtree gives a valid value then we have to pass the valid value further.
    if(leftLCA)     return leftLCA;
    if(rightLCA)    return rightLCA;

    //If both the subtree's left and right pass a false or NULL value in that case we just need to return the NULL.
    // return NULL; //This NULL will be returned if none of the above condition becomes true and both the subtree have passed the NULL.

    //We can too combine the above three condition in one statement only.
    // return leftLCA == NULL ? rightLCA : leftLCA ;
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

    int node1 = 4;
    int node2 = 5;

    Node* ans = LCA(root, node1, node2);
    cout<<ans->data<<" ";
    
    return 0;
}

/*
            1
        2       3
    4      5 N     6
N      N N  N   N     N
*/