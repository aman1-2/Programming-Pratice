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
    }

    void push_back(int data) {
        Node* newNode = new Node(data);
        if(this->head == NULL) {
            this->head = newNode;
            return;
        }

        Node* temp = this->head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;

        return;
    }
};

Node* print(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL) {
        Node* next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}

Node* splitAtMid(Node* head) {
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while(fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if(prev != NULL) {
        prev->next = NULL; //The partiton of the linked list is done.
    }

    return slow; //rightHead = slow;
}

Node* merge(Node* head, Node* headRightRev) {
    Node* left = head;
    Node* right = headRightRev;
    Node* tail = right; //Just for traking the last elment added in each loop end because in odd case inside right portion we have one extra element.

    while(left != NULL && right != NULL) {
        Node* nextLeft = left->next;
        Node* nextRight = right->next;

        left->next = right;
        right->next = nextLeft;

        tail = right;

        left = nextLeft;
        right = nextRight;
    }

    if(right != NULL) {
        tail->next = right;
    } 

    return head;
}

Node* zigZag(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* rightHead = splitAtMid(head);
    Node* rightHeadRev = reverse(rightHead);

    return merge(head, rightHeadRev);
}

int main() {
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    print(ll.head);
    ll.head = zigZag(ll.head);
    print(ll.head);

    return 0;
}