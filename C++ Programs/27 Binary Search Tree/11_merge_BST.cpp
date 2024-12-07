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

void getInorder(Node* root, vector<int> &vec) {
    if(root == NULL)    return;

    getInorder(root->left, vec);
    vec.push_back(root->data);
    getInorder(root->right, vec);

    return;
}

Node* buildBST(vector<int> &vec, int st, int ed) {
    if(st > ed) return NULL;
    int mid = st+(ed-st)/2;
    Node* curr = new Node(vec[mid]);

    curr->left = buildBST(vec, st, mid-1);
    curr->right = buildBST(vec, mid+1, ed);

    return curr;
}

Node* mergeBST(Node* root1, Node* root2) {
    //STEP 1:Creating the vectors for storing the sorted sequence.
    vector<int> nodes1, nodes2;
    vector<int> sorted;

    //STEP 2: Calculating the sorted sequence for the root1 and root2.
    getInorder(root1, nodes1);
    getInorder(root2, nodes2);

    //STEP 3: Now we need to merge the two sorted vectors to form a one sorted vector.
    int i=0, j=0;
    while(i<nodes1.size() && j<nodes2.size()){
        if(nodes1[i] < nodes2[j]){
            sorted.push_back(nodes1[i++]);
        } else {
            sorted.push_back(nodes2[j++]);
        }
    }

    while(i<nodes1.size()) {
        sorted.push_back(nodes1[i++]);
    }

    while(j<nodes2.size()) {
        sorted.push_back(nodes2[j++]);
    }

    //STEP 4: At the end making a call of buildBST which will build our BST using the sorted vector.
    return buildBST(sorted, 0, sorted.size()-1);
}

void inorder(Node* root) {
    if(root == NULL)    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

    return;
}


int main() {
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

    Node* root = mergeBST(root1, root2);
    inorder(root);

    return 0;
}