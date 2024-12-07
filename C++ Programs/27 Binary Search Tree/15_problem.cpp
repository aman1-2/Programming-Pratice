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

//While making a search we try to have our temp node fix and find the target value in the main (root) BST.
bool search(Node* root, Node* temp, int k) {
    //In searching case, If the temp becomes NULL i.e. while searching for the value if we reach the end of the BST in that case just return false.
    if(root == NULL)    return false;

    //Make a temporary node like root.
    Node* c = root; 
    bool flag = false; //A flag initally holding the value false in it.

    //Till the time c is not NULL and flag is not true till then we have to run our loop.
    while(c!=NULL && flag!=true) {
        //If the root(temprories data is equal to K(target[seach value]) and if temp is not equal to c
        if(c->data == k && temp != c) {
            flag = true; //Then convert the flag value to true making the while condition false.
            cout<<"Pair found: "<<c->data<<" + "<<temp->data<<endl; //And printing the first pair encountred like this.
            return true; //At the end return the true value as we have found the pair.
        } else if(k < c->data) { //If target is less then the current data then make a left subtree call.
            c=c->left;
        } else { //Otherwise make a right subtree call.
            c=c->right;
        }
    }

    //And if we aren't returned form true this means we haven't found the pair therefore return a false value.
    return false;
}

bool isPairPresent(Node* root, Node* temp, int target) {
    //If the second BST provided is empty i.e. if its NULL then we can't find the target sum therefore it will return false.
    if(temp == NULL)    return false;

    //If not so then we will try to search the target sum pair with the help of first and second BST value, If pair is not found then in that case we make a left and right call.
    return search(root, temp, target - temp->data) || isPairPresent(root, temp->left, target) || isPairPresent(root, temp->right, target);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    Node* temp = new Node(10);
    temp->left = new Node(6);
    temp->right = new Node(15);
    temp->left->left = new Node(3);
    temp->left->right = new Node(8);
    temp->right->left = new Node(11);
    temp->right->right = new Node(18);

    cout<<isPairPresent(root, temp, 16);

    return 0;
}