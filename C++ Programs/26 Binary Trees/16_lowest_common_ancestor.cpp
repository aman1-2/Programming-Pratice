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

//Path calculating from the root node to the particular node.
bool rootToNodePath(Node* root, int n, vector<int> &path) { //Time Complexity - O(n)
    //Passed the path vector as reference.
    if(root == NULL)    return false; //If the root value is NULL i.e no node to add in the path just return false.

    path.push_back(root->data); //Add the root node data in the path. Assuming that this root will be in the path

    if(root->data == n) return true; //If the root data is same as which we are finding then return true. 

    bool isLeft = rootToNodePath(root->left, n, path); //Otherwise see in the left side.
    bool isRight = rootToNodePath(root->right, n, path); //And see in the right side.

    if(isLeft || isRight)   return true; //If any of the left or the right sub-part is true just return true.

    path.pop_back(); //If both left and right part is false just remove that root value from the path and return false.
    return false;
}

//Lowest Common Ancestor
int LCA(Node* root, int n1, int n2) { //Time Complexity - O(n) and Space Complexity - O(n) as creating vectors.
    //Creating extra path vector for storing the path from the root to the node.
    vector<int> path1;
    vector<int> path2;

    //Called the function to calculate the path from the root node to particular node.
    rootToNodePath(root, n1, path1);
    rootToNodePath(root, n2, path2);

    int lca = -1; //A variable for holding the lowest common ancestors.
    
    //A loop for traversing both the paths one by one simultaneously
    for(int i=0,j=0; i<path1.size() && j<path2.size(); i++,j++) {
        if(path1[i] != path2[j]) { //If the path values are not same, that is the first time that we see that the path values are not same we just return our LCA value as we have got it and from here the path values have started divering.
            return lca;
        }
        lca = path1[i]; //Till the time path values are same just go on updating the LCA value.
    }

    return lca; //At the end if we never got our LCA common in the above loop then return -1.
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

    int ans = LCA(root, node1, node2);
    cout<<ans<<" ";
    
    return 0;
}

/*
            1
        2       3
    4      5 N     6
N      N N  N   N     N
*/