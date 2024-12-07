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

    void push_back(int val) {
        Node* newNode = new Node(val);
        if(tail == NULL) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
        return;
    }

    void print() {
        Node* temp = this->head;

        while(temp != NULL) {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL\n";

        return;
    }

};

Node* splitMid(Node* head) {
    Node* slow = head;
    Node* fast = head;
    Node* prev =NULL;

    while(fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if(prev != NULL) {
        prev->next = NULL; //Here we are just splitting the linked list in two.
    }

    return slow; //rightHead = slow;
}

Node* merge(Node* left, Node* right) {
    List ans;
    Node* i = left; Node* j = right; //Temporary pointers for traversing the left or right linked list.

    while(i != NULL && j != NULL) {
        if(i->data <= j->data) {
            ans.push_back(i->data);
            i = i->next;
        } else {
            ans.push_back(j->data);
            j = j->next;
        }
    }

    while(i != NULL) {
        ans.push_back(i->data);
        i = i->next;
    }

    while(j != NULL) {
        ans.push_back(j->data);
        j = j->next;
    }

    return ans.head;
}

Node* mergeSort(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head; //If no value Null if single value that single node will be returned.
    }

    Node* rightHead = splitMid(head);

    Node* left = mergeSort(head);
    Node* right = mergeSort(rightHead);

    return merge(left, right);
}

int main() {
    List ll;
    ll.push_back(4);
    ll.push_back(3);
    ll.push_back(2);
    ll.push_back(1);

    ll.print();
    
    ll.head = mergeSort(ll.head);
    ll.print();

    return 0;
}