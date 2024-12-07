#include<iostream>
#include<cmath>
#include<climits>
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

//This is a Brute-force Approach where we are going at each node and then calculating its absolute value and at the end comparing the absolute values returned form the left and right node with the current absolute value and returning the smallest from all.
Node* minAbsValue(Node* root, int &target) { //Time-Complexity - O(n)
    //Base case: If its a NULL node in that case we need to return NULL. But returning a NULL value can affect the answer as we are making comparison for minimum absolute value.
    //Therefore we have to made a condition for leaf node the leaf node will return its own value as at the smallest step the leaf will only be the minimum absolute value near to target.
    if(root == NULL)    return NULL;
    if(root->left == NULL && root->right == NULL)   return root;

    //Assumption: If we are able to calculate the nearest minimum absolute value for our self then like wise it will to be able to return the answer from our left and right subtree's too.
    Node* leftValue = minAbsValue(root->left, target);
    Node* rightValue = minAbsValue(root->right, target);

    //Self-work: Calculating the absolute value for the left and right subtree as recieved and too calculating current absolute value.
    int leftAbs = (leftValue != NULL) ? abs(target - leftValue->data) : INT_MAX; //Making sure if the absolute is a NULL value then we have to return INT_MAX ohterwise calculate the absolute value.
    int rightAbs = (rightValue != NULL) ? abs(target - rightValue->data) : INT_MAX; //Making sure if the absolute is a NULL value then we have to return INT_MAX ohterwise calculate the absolute value.
    int currAbs = abs(target - root->data); //Calculating the current nodes absolute value.

    //Making comparison so that we can return the node which has minimum absolute value near to the target.

    if(leftAbs < rightAbs && leftAbs < currAbs) return leftValue;
    else if(rightAbs < leftAbs && rightAbs < currAbs)   return rightValue;
    else    return root;
}

//Its an Optimize approach for the above code where we use the BST property
Node* minAbsValueOptz(Node* root, int &target) { //Time-Complexity - O(log H), H is the height of the tree.
    //In starting consider the root node to be the closet node.
    Node* closet = root;

    //Untill we haven't traversed the whole tree move to the nodes one by one in the tree.
    while(root) {
        //If the current abs value is low then the closet abs value then update the root.
        if(abs(target - root->data) < abs(target - closet->data))   closet = root;

        //If the target value is less than root value just make a search in the left root only.
        if(target < root->data) {
            root = root->left;
        } else if(target > root->data) { //Otherwise on the right side
            root = root->right;
        } else { //If target is equal to the node in that case that node is only answer no other node cann't be closet to that node.
            return root;
        }
    }
    
    return closet; // at the end return the closet node.
}



int main() {
    Node* root = new Node(8);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(6);

    root->right = new Node(11);
    root->right->right = new Node(20);

    int target = 5;
    Node* ans = minAbsValueOptz(root, target);
    cout<<ans->data<<endl;
    cout<<"Absolute difference = "<<abs(target - ans->data);

    return 0;
}