#include<iostream>
#include<queue>
#include<map>
#include<vector>
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

void topView(Node* root) { //Time-complexity - O(n)
    //Step: We need to make a pair of node and Horizontal distance and that pair will get stored in our queue.
    queue<pair<Node*, int>> qu;
    //Step: Making a map pair (which is a key value pair. which will store the nodes with their horizontal value that got visited for the first time and isn't in the map. The map will hold the key-value pair as (Horizontal-distance, Node->data)
    map<int, int> m;

    //Step: Adding the first node in the Queue for ensuring the level order traversal.
    qu.push(make_pair(root, 0)); //Root node is passed in the queue as the first value with a horizontal disatance as 0.

    //Step: Execute the loop till the time queue is not empty.
    while(!qu.empty()) {
        //Step: Fetching out the the front pair from the queue.
        pair<Node*, int> curr_p = qu.front();
        qu.pop(); //Removing it from the queue to avoid it making a infinite loop.

        //Step: Checking if the Horizontal distance is visited for the first time then we have to store that value inside the map and if the same Horizontal Distance is seen again in that case we just need to skip it.
        if(!m[curr_p.second]) { //Or can have a count check like if(m.count(curr_p.second))
            m[curr_p.second] = curr_p.first->data;
        }

        //Step: Adding the left and right child of the current node in the queue. If they exists i.e they must not be NULL.
        if(curr_p.first->leftPtr)   qu.push(make_pair(curr_p.first->leftPtr, curr_p.second - 1));
        if(curr_p.first->rightPtr)    qu.push(make_pair(curr_p.first->rightPtr, curr_p.second + 1));
    }

    //Step: Iterating over the map and printing the values present in the map
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

    topView(root);
    
    return 0;
}

/*
            1
        2       3
    4      5 N     6
N      N N  N   N     N
*/