/**
 * First of all detect the cycle
 * Then move the slow pointer to head
 * Then run a loop where you move slow and fast by +1 updation
 * Where so ever they meet the previous node to fast we have to make it point to the NULL.
 * 
 * Then comes the corner case when the tail is attached to head
 * In that case we need to
*/

#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        this->data = val;
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

    void push_front(int val) {
        Node* new_node = new Node(val);
        if(head == NULL) {
            head = tail = new_node;
            return;
        }

        new_node->next = head;
        head = new_node;
        return;
    }

    void print() {
        Node* temp = this->head;
        while(temp!=NULL) {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL\n";
        return;
    }

};

void removingCycle(Node* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    Node* slow = head;
    Node* fast = head;
    bool flag = false;

    //Detecting the cycle
    while(fast!=NULL && fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            flag = true;
            break;
        }
    }
    if(!flag){
        //No Cycle
        return;
    }
    slow = head;
    if(slow == fast) { //Corner case to handle if the start was connected to tail. In that case both the slow and fast would point to the same position in starting itself.
        while(fast->next != slow) {
            fast = fast->next;
        }
        fast->next = NULL; //Removed Cycle
    } else {
        Node* prev;
        while(fast != slow) {
            prev = fast;
            fast = fast->next;
            slow = slow->next;
        }
        prev->next = NULL; //Removed Cycle
    }
    return;
}

int main() {
    List ll;
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    //Made a connection
    ll.tail->next = ll.head;
    // ll.print();
    removingCycle(ll.head);
    ll.print();
    return 0;
}