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

Node* insert(Node* root, int value) {
    if(root == NULL)    return root = new Node(value);

    if(root->data < value)  root->right = insert(root->right, value);
    else    root->left = insert(root->left, value);

    return root;
}

Node* buildBST(vector<int> &vec) {
    Node* root = NULL;
    for(int i=0; i<vec.size(); i++) {
        root = insert(root, vec[i]);
    }

    return root;
}

//Global Varibales
int startValue; 
int endValue;

//This is the Brute-Force approach where we have traversed the whole tree One by one we went to each of the node and checked if the value lies between the range or not if it lies then print the value otherwise just skip it.
void printInRange(Node* root) {// It will have a time complexity of O(n). As we will go to each node at least once. 
    if(root == NULL)    return;

    printInRange(root->left);
    if(root->data >= startValue && root->data <=endValue)   cout<<root->data<<" ";
    printInRange(root->right);

    return;
}

/*But we can optimize our searching if we have BST tree and if we use the BST property then we can optimize our searching technique.*/
void printInRange2(Node* root) {
    //Base Case: If the root node is null then just return from the function
    if(root == NULL)    return; 

    //Condition1: If the root data is in range start and end then we have to print the root value and make a call to right and left both.
    if(root->data >= startValue && root->data <= endValue){
        // cout<<root->data<<" ";
        // printInRange2(root->left);
        // printInRange2(root->right);
        
        //If we want to have sorted order printing then we just need to make our left tree call first then pinting. First make left call then printing and then right call and it will have a sorted sequence printing.
        printInRange2(root->left);
        cout<<root->data<<" ";
        printInRange2(root->right);
    } else if(root->data < startValue){
        printInRange2(root->right);
    } else { //Condition3: If root is more tha endValue then we have to make a call to left side only.
        printInRange2(root->left);
    }

    
}

int main() {
    vector<int> vec = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node* root = buildBST(vec);

    startValue = 5;
    endValue = 12;

    printInRange(root);
    cout<<endl;
    printInRange2(root);

    return 0;
}