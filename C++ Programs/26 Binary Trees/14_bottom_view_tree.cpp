#include<iostream>
#include<queue>
#include<map>
using namespace std;

class Node {
public:
    int data;
    Node* leftPtr;
    Node* rightPtr;

    Node(int value) {
        this->data = value;
        this->leftPtr = this->rightPtr = NULL;
    }
};

void bottomView(Node* root) {
    //Make a pair of Node and Horizontal distance which will be added in the queue 
    queue<pair<Node*, int>> qu;
    map<int, int> m; //Make a pair of key-value for (horizontal distance and node->data). Which is for storing the pair of values that will be counted for bottom view.

    qu.push(make_pair(root, 0)); //Adding the pair of first root node and its horizontal distance in the queue.

    //Running the loop until the queue is not empty
    while(!qu.empty()) {
        //Extracting the first pair out from the queue.
        pair<Node*, int> curr_p = qu.front();
        qu.pop(); //To avoid infinite loop we are poping the pair first fetched.

        m[curr_p.second] = curr_p.first->data; //If it is encountred first time then we have 
        //to add it in the map but if its been visited twice in that case we have to update it with new value. Which is the last value should be present in the map for a Horizontal distance as we are trying to print Bottom view of the tree.

        //Adding the pair of Node and Horizontal distance in the queue for the children of current node. If they are not NULL.
        if(curr_p.first->leftPtr)   qu.push(make_pair(curr_p.first->leftPtr, curr_p.second - 1));
        if(curr_p.first->rightPtr)  qu.push(make_pair(curr_p.first->rightPtr, curr_p.second + 1));
    }

    //Printing the values prensent in the map - as they are storing the bottom view nodes for the tree.
    for(auto it:m) {
        cout<<it.second<<" ";
    }

    return;
}

static int idx = -1;
Node* buidTree(vector<int> &vec) {
    idx++;

    if(vec[idx] == -1)  return NULL;

    Node* currNode = new Node(vec[idx]);
    currNode->leftPtr = buidTree(vec);
    currNode->rightPtr = buidTree(vec);

    return currNode;
}

void preOrder(Node* root) {
    if(root == NULL)    return;

    cout<<root->data<<" ";
    preOrder(root->leftPtr);
    preOrder(root->rightPtr);
}

int main() {
    vector<int> vec = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buidTree(vec);

    preOrder(root);
    cout<<endl;

    bottomView(root);
    
    return 0;
}

/*
            1
        2       3
    4      5 N     6
N      N N  N   N     N
*/