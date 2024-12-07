#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        this->val = value;
        this->left = this->right = NULL;
    }
};

int rangeSumBST(TreeNode* root, int low, int high) {
    if(root == NULL)    return 0;

    int leftSum = rangeSumBST(root->left, low, high);
    int rightSum = rangeSumBST(root->right, low, high);

    if(root->val >= low && high >= root->val) {
        return leftSum + rightSum + root->val;
    }

    return leftSum + rightSum;
}