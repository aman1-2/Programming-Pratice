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

    ~Node() {
        if(nextPtr != NULL) {
            delete nextPtr;
            nextPtr = NULL;
        }
    }
};

class List {
    Node* head;
    Node* tail;
    
public: 
    List() {
        this->head = NULL;
        this->tail = NULL;
    }

    ~List() {
        if(head != NULL || tail != NULL) {
            delete head;
            head = NULL;
        }
    }

    void push_front(int data) {
        Node* newNode = new Node(data);

        if(head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->nextPtr = head;
        head = newNode;

        return;
    }
    
    void push_back(int data) {
        Node* newNode = new Node(data);

        if(tail == NULL){
            head = newNode;
            tail = newNode;
            return;
        }

        tail->nextPtr = newNode;
        tail = newNode;

        return;
    }

    void printList(){
        Node* temp = head;
        for(temp; temp!=NULL; temp=temp->nextPtr){
            cout<<temp->data<<"->";
        }
        cout<<"Null\n";
        return;
    }

    void insertKthPosition(int value, int position){
        //If the head is null we cann't go to that position and need to fill the position before it.
        if(head == NULL){
            cout<<"Position Invalid.\n";
        }

        Node* newNode = new Node(value);
        Node* temp = head;

        for(int i=0; i<position-1; i++) {
            if(temp == NULL)    cout<<"Position Invalid.\n";
            temp = temp->nextPtr;
        }

        newNode->nextPtr = temp->nextPtr;
        temp->nextPtr = newNode;

        return;
    }

    void pop_front() {
        if(head == NULL || tail == NULL) {
            return;
        }
        Node* temp = head;
        head = head->nextPtr;
        free(temp);

        return;
    }

    void pop_back() {
        if(tail == NULL || head == NULL) {
            return;
        }
        Node*temp=head;
        while (temp->nextPtr->nextPtr != NULL) {
            temp = temp->nextPtr;
        }
        temp->nextPtr = NULL;
        free(tail);
        tail = temp;
    }

    int searchItr(int key) {
        Node* temp = head;
        int count = 0;

        while(temp != NULL){
            if(temp->data == key)   return count;

            temp = temp->nextPtr;
            count++;
        }

        return -1;
    }

    int helper(Node* head, int &key) {
        if(head == NULL)    return -1;

        if(head->data == key)   return 0;

        int idx = helper(head->nextPtr, key);

        if(idx == -1)   return -1;

        return idx+1;
    }

    int searchRec(int key) {
        return helper(head, key);
    }

    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        while(curr != NULL) {
            Node* next = curr->nextPtr;
            curr->nextPtr = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
        return;
    }

    int length() {
        int count = 0;
        Node* temp = head;
        while(temp != NULL) {
            temp = temp->nextPtr;
            count++;
        }

        return count;
    }

    void removalFromEnd(int position) {
        int size = this->length();
        Node* prev = head;
        for(int i=0; i<size-position; i++){
            prev = prev->nextPtr;
        }
        Node* delNode = prev;
        if(delNode->data == head->data) {
            head = head->nextPtr;
            free(delNode);
        }
        prev->nextPtr = prev->nextPtr->nextPtr;
        free(delNode);
        return;
    }
};

int main() {
    List ll;
    // ll.push_front(1);
    // // ll.push_front(2);
    // // ll.push_front(1);
    // // ll.push_front(3);

    // cout<<ll.head->data<<" "<<ll.head->nextPtr->data;

    // ll.push_back(1);
    // ll.push_back(2);
    // ll.push_back(3);

    // cout<<ll.head->data<<" "<<ll.head->nextPtr->data<<" "<<ll.head->nextPtr->nextPtr->data;

    // ll.push_front(3);
    ll.push_front(2);
    ll.push_back(4);
    ll.push_front(1);
    ll.push_back(5);
    ll.insertKthPosition(3,2);
    ll.insertKthPosition(6,5);

    // ll.pop_front();
    // ll.pop_front();
    // ll.pop_back();
    // ll.pop_back();

    ll.printList();

    // int keyIdx = ll.searchItr(7);
    // int keyIdx1 = ll.searchRec(1);
    // cout<<keyIdx1;

    // ll.reverse();
    // ll.printList();

    ll.removalFromEnd(1);
    ll.printList();

    return 0;
}