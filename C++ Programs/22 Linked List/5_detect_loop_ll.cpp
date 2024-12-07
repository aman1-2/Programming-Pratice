#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value){
        this->data = value;
        this->next = NULL;
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

    void push_front(int data) {
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
        return;
    }

    void print() {
        Node* temp = this->head;
        while(temp != NULL) {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL";
        return;
    }
};

bool detectLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next; //+1 updation
        fast = fast->next->next; //+2 updation
        if(slow == fast) {
            return true;
        }
    }
    return false;
}

int main(){
    List ll;
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    // ll.tail->next = ll.head;

    cout<<detectLoop(ll.head);

    return 0;
}