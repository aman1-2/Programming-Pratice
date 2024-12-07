#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* nextPtr;
    Node(int data) {
        this->data = data;
        this->nextPtr = NULL;
    }
};

int main(){
    Node* obj1 = new Node(1);
    Node* obj2 = new Node(2);
    obj1->nextPtr = obj2;
    cout<<obj1->data<<" "<<obj1->nextPtr->data;
    return 0;
}