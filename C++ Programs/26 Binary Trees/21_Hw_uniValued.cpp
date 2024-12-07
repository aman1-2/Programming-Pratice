#include<iostream>
#include<queue>
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
    if(vec[idx] == -1)  return NULL;

    Node* curr = new Node(vec[idx]);
    curr->left = buildTree(vec);
    curr->right = buildTree(vec);

    return curr;
}

//Way - 1
/**
 * Here tried to run a level order algorithm just instead of printing the node from the queue i tried to see the value inside the queue if all the nodes have same value return true otherwise false.
 * But here Time Complexity is O(n) but takes a space complexity of O(n).
 */
bool uniValued(Node* root, int num) {
    if(root == NULL)    return false;
    
    queue<Node*> qu;
    qu.push(root);
    
    while(!qu.empty()) {
        Node* curr = qu.front();
        qu.pop();
        
        if(curr->data  != num)  return false;
        
        if(curr->left)  qu.push(curr->left);
        if(curr->right) qu.push(curr->right);
    }
    
    return true;
}

//Way - 2
/**
 * Time complexity is O(n) as visiting each node to check its value. And space complexity is O(1).
 */
bool isuniValued(Node* root) {
    //Base condition -> If we are on the last node then the value at the last node or the only node in the subtree will have a unique value only.
    //The smallest part where the value will be unique will be at the last position i.e. if we are on the NULL node in that case our value at that position is unique.
    if(root == NULL)    return true;

    //Assumption -> If we somehow get the answer of our left and right subtree if any of them is false in that case we don't need to check and can simple return a false value.
    if(!isuniValued(root->left) || !isuniValued(root->right)) {
        return false;
    }

    //Self work -> checking that the left node it must not be a null and
    if(root->left != NULL)  {
        //If the left node is not null then compare the value of the left node value to the root node value if its not equal then simply return false.
        if(root->data != root->left->data) {
            return false;
        }
    }

    //Checking the same for the the right node if the right node is not null then
    if(root->right != NULL)  {
        //we can compare the value of the right node to the root node and if it is not equal then can simply return false.
        if(root->data != root->right->data) {
            return false;
        }
    }

    //And if non of the condition makes it a false statement this means the parent node value is equal to its child nodes value therefore return true for it.
    return true;
}

int main() {
    vector<int> vec = {1, 1, 1, -1, -1, 1, -1, -1, 1, -1, 1, -1, -1};
    Node* root = buildTree(vec);

    cout<<uniValued(root, root->data);
    cout<<endl;
    cout<<isuniValued(root);

    return 0;
}

/*
            1
        2       3
    4      5 N     6
N      N N  N   N     N
*/