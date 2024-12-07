// #include<iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* left;
//     Node* right;
    
//     Node(int value) {
//         this->data = value;
//         this->left = this->right = NULL;
//     }
// };

// /**
// *Inverting logic for Tree is simple through recursion
// */
// void invert(Node* root) {
//     //Base case If its the leaf node then it doesn't have any child nodes so there is no need of inverting and infact if its null node then too we don't need to do anything just return from there.
//     if(root == NULL)    return;

//     //Assumption -> If we get our child nodes invert then our work will be simple just to swap the nodes of the tree for our current nodes. Assuming if it works for current node then it will work fine for the its left and right node and once left and right nodes subtree are inverted then we just need to swap there values to have our node with inverted value.
//     invert(root->left);
//     invert(root->right);
        
//     //Self-work -> Swapping the right node with the left node.
//     Node* temp = root->left;
//     root->left = root->right;
//     root->right = temp;

//     return;
// }

// void preOrder(Node* root) {
//     if(root == NULL)    return;
    
//     cout<<root->data<<" ";
//     preOrder(root->left);
//     preOrder(root->right);
    
//     return;
// }

// int main() {
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);
//     root->right->left = NULL;
//     root->right->right = new Node(6);
    
//     preOrder(root);
//     cout<<endl;

//     invert(root);
//     preOrder(root);
    
//     return 0;
// }

// /*
//             1
//         2       3
//     4      5 N     6
// N      N N  N   N     N
// */












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

void helper(Node* root, int target) {
    if(root == NULL)    return;
    
    helper(root->left, target);
    helper(root->right, target);
    
    if(root->data == target){
        delete(root);
        root = NULL;
    };
    
    return;
}

void preOrder(Node* root) {
    if(root == NULL)    return;
    
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    
    return;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = NULL;
    root->right->right = new Node(4);
    preOrder(root);
    cout<<endl;
    helper(root, 4);
    preOrder(root);
    
    return 0;
}

/*
            1
        2       3
    4      5 N     6
N      N N  N   N     N
*/