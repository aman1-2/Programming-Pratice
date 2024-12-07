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

//Iterative Approach - Time complexity - O(n)
void levelOrder(Node* root, int kth) {
    if(root == NULL)    return ;

    queue<Node*> qu;
    //Pushed the root and null as the first ingoing elements in the queue.
    qu.push(root);
    qu.push(NULL);

    int count = 1; //Count for matching the kth value (level) to print.
    
    //A loop till the time our queue is not empty
    while(!qu.empty()) {
        Node* curr = qu.front();
        qu.pop(); //Fetching the first element from the queue and then poping it.

        if(count > kth) break; //If in any case count goes beyond the kth just break at that point this means we have already printed our kth level.

        if(curr != NULL){ //If the current node is not null.
            if(count == kth)    cout<<curr->data<<" "; //If its not null and equal to the kth value then print the nodes present at that level.
            if(curr->left)  qu.push(curr->left); //If there is some left child present for the current node then add it in the queue.
            if(curr->right) qu.push(curr->right); //If there is some right child present for the current node then add it in the queue.
        } else {
            count++; //If its not null then increase the count value.
            if(qu.empty())    break; //Make a check that if it was the last null character that poped then we don't need to do anything further
            qu.push(NULL); //If wasn't the last null then add the null character again so that it can increase the count when encounters the null.
        }
    }

    return;
}

//Recursive Approach Time Complexity - O(n)
void kthHelper(Node* root, int kth, int currentLevel) { //This functions time-complexity is O(n)
    //Base Case if we are on a Null node which doesn't have any further nodes then just return from there.
    if(root == NULL)    return;

    //Self-work If the kth value is equal to the currentLevel which is if a nodes current level is same as kth then we have to print that data and just return from there because moving down that level will only increase the level it will never be same as kth again so no need to traverse for them.
    if(kth == currentLevel) {
        cout<<root->data<<" ";
        return;
    }

    kthHelper(root->left, kth, currentLevel+1); //Recursively going to the left child and increasing its level.
    kthHelper(root->right, kth, currentLevel+1); //Recursively going to the right child and increasing its level.
}

void kthLevel (Node* root, int kth) { 
    kthHelper(root, kth, 1); //Calling the Helper function
    return;
}

static int idx = -1;
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

    // levelOrder(root, 3);
    kthLevel(root, 2);

    return 0;
}

/*
            1
        2       3
    4      5 N     6
N      N N  N   N     N
*/