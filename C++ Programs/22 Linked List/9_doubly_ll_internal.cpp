#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoublyList {
public:
    Node* head;
    Node* tail;

    DoublyList() {
        this->head = NULL;
        this->tail = NULL;
    }

    void push_front(int data) {
        Node* newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    void pop_front() {
        //No element and trying to pop.
        if(head == NULL)    return;

        if(head->next == NULL) {
            //Single element pop.
            delete head;
            head = NULL;
            return;
        }

        /*Above if condition can be replaced by
        Node* temp = head;
        head = head->next;
        if(head!=NULL) {
            head->prev = NULL;
        }
        temp->next = NULL;
        delete temp;*/

        Node* temp = head;
        head = head->next;
        temp->next->prev = NULL;
        delete temp;
    }

    void print() {
        Node* temp = this->head;
        while(temp != NULL) {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
};

int main() {
    DoublyList dll;
    dll.push_front(3);
    dll.push_front(2);
    dll.push_front(1);
    dll.print();
    dll.pop_front();
    dll.print();
    dll.pop_front();
    dll.print();
    dll.pop_front();
    dll.print();
    return 0;
}