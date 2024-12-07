/**
 * Inside Queue we have these three as the main Functions:-
 * Push
 * Pop
 * Front -> Returns the front element of the queue.
 */

#include<iostream>
using namespace std;

class Node {
public: 
    int data;
    Node* next;

    Node(int value) {
        this->data = value;
        this->next = NULL;
    }
};

class List {
public:
    List() {
        this->head = this->tail = NULL;
    }

    Node* head;
    Node* tail;

    void push_back(int value) {
        Node* new_node = new Node(value);
        if(this->tail == NULL) {
            head = tail = new_node;
            return;
        }
        tail->next = new_node;
        tail = new_node;
        return;
    }

    void pop_front() {
        if(head == NULL)    return;
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete(temp);
        return;
    }

    int top() {
        if(head == NULL) return -1;
        return head->data;
    }
};

class Queue : private List {
private:
    List ll;    

public:
    void push(int value) { //Pushing at the back of the Queue.
        this->push_back(value);
        return;
    }

    void pop() { //Poping from the front of the Queue.
        this->pop_front();
        return;
    }

    int front() { //The front (i.e, the first element of the Queue will be shown)
        return this->top();
    }
};

int main() {
    Queue qu;
    qu.push(1);
    qu.push(2);
    cout<<qu.front()<<"\n";
    qu.pop();
    cout<<qu.front()<<"\n";
    qu.pop();
    cout<<qu.front()<<"\n";
    return 0;
}