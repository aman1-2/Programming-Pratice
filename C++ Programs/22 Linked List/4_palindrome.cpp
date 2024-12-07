/*
Qs. Given the head of a singly linked list, return true if it is a Palindrome or false
otherwise.

Input: head = [1,2,2,1]  Linked List : 1->2->2->1
Output: true

Input: head = [1,2] Linked List : 1->2
Output: false
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int value){
        data=value;
        next=NULL;
    }
};

class linkedList{
public:
    Node* head;

    linkedList(){
        head=NULL;
    }

    void insertAtHead(int value){
        Node* new_node=new Node(value);

        new_node->next=head;

        new_node=head;

        return;
    }

    void insertAtTail(int value){
        Node* new_node=new Node(value);

        if(head==NULL){
            head=new_node;
            return;
        }

        Node* temp=head;

        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;

        return;
    }

    void display(){
        Node* temp=head;

        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;

        return;
    }

    bool isPlaindrome(){
        /*To check whether the given linked list is a palindrome or
        E.G :- 1->2->3->3->2->1->NULL or we can say 1->2->3->2->1->NULL both are palindromic
        linked list.
        
        Step 1.) Find the middle point of the linked list.
        Step 2.) Break or separate the linked list into two parts.
        Step 3.) Reverse the second half of the linked list.
        Step 4.) Before reversing the second half just point the last node of the first half
        to NULL and after reversing same goes with second half point it to NULL.
        
        Step 5.) To compare both the linked list
        
        "These steps are for EVEN CASE only a minute change in the ODD CASE" 
        
        Step 5.) For odd case -> We have to compare the values till the time second half
        reaches to NULL and ignore the one left half in the first half
                                 NULL
                                  |
        E.G:- EVEN CASE- 1->2->3->3<-2<-1  for ODD CASE:- 1->2->3->NULL<-2<-1*/


        //STEP 1.) FINDING THE MIDDLE POINT OF THE LINKED LIST.
        Node* slow_ptr=head;
        Node* fast_ptr=head;

        while(fast_ptr!=NULL and fast_ptr->next!=NULL){
            slow_ptr=slow_ptr->next;
            fast_ptr=fast_ptr->next->next;
        }

        //At the end of the loop our slow pointer will be pointing to the middle element of
        //the linked lsit.

        
        //STEP 2.) TO REVERSE THE SECOND HALF OF THE LINKED LIST.
        Node* curr_node=slow_ptr->next; //Current node whose linking we have to change
        slow_ptr->next=NULL; //Once placed NULL in the next of the middle node forms the first half of the linked list.
        Node* prev_node=slow_ptr; //Previous node the node which the curr_node will point to.

        //Reverse process:-
        while(curr_node){
            Node* next_node=curr_node->next; //Next_node pointing to the next node of curr_node so that we should loose that data.
            curr_node->next=prev_node; //Linkage being changed.
            prev_node=curr_node; //Moving the node one step ahead.
            curr_node=next_node; //Moving the node one step ahead.
        }

        //STEP 3.) POSITIONING THE NEW STARTING POINTS FOR BOTH THE HALF OF THE LINKED LIST.
        Node* head1=head; //For the first half.
        Node* head2=prev_node; //For the second half.

        //STEP 4.) COMPARING THE VALUES TO CHECK WHETHER THEY ARE PALINDROME OR NOT.
        while(head2){
            if(head1->data!=head2->data)    return false;
            head1=head1->next;
            head2=head2->next;
        }

        return true;
    }
};

int main(){
    linkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(2);
    ll.insertAtTail(1);
    ll.display();

    cout<<ll.isPlaindrome();

    return 0;
}