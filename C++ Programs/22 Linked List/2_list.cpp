#include<iostream>
using namespace std;

class Node {
    
public: 
    int data;
    Node* nextPtr;

    Node(int data) {
        this->data = data;
        this->nextPtr = nextPtr;
    }
};

class List {
public: 
    Node* head;
    Node* tail;

    List() {
        this->head = NULL;
        this->tail = NULL;
    }
};

int main() {
    List ll;
    Node* Obj1 = new Node(1);
    Node* Obj2 = new Node(2);
    ll.head = Obj1;
    ll.head->nextPtr = Obj2;

    cout<<ll.head->data<<" "<<ll.head->nextPtr->data;

    return 0;
}