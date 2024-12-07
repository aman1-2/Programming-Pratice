#include<iostream>
#include<climits>
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

int height(Node* root, int &maxi) {
    if(root == NULL)    return 0;

    int lh = max(0, height(root->left, maxi));
    int rh = max(0, height(root->right, maxi));

    maxi = max(maxi, (lh+rh+root->data));

    return root->data+max(lh,rh);
}

int idx = -1;
Node* buildTree(vector<int> &vec) {
    idx++;
    if(vec[idx] == -1)    return NULL;

    Node* currNode = new Node(vec[idx]);

    currNode->left = buildTree(vec);
    currNode->right = buildTree(vec);

    return currNode;
}

int maxSumPath(Node* root) {
    int res = INT_MIN;
    height(root, res);
    return res;
}

void preOrder(Node* root) {
    if(root == NULL)    return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    vector<int> vec = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(vec);

    preOrder(root);
    cout<<endl;

    int ans = maxSumPath(root);
    cout<<ans;

    return 0;
}

/*
            1
        2       3
    4      5 N     6
N      N N  N   N     N
*/