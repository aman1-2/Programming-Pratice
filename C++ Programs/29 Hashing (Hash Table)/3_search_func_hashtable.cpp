#include<iostream>
using namespace std;

class Node {
public:
    string key;
    int value;
    Node* nextPtr;

    Node(string key, int val) {
        this->key = key;
        this->value = val;
        this->nextPtr = NULL;
    }

    ~Node() {
        if(this->nextPtr != NULL)   delete this->nextPtr;
    }
};

class HashTable {
    int totalSize;
    int currSize;
    Node** table;

    int hashFunction(string key) {
        int idx = 0;
        for(char ch:key) {
            int ele = ch - 0;
            idx = (idx + (ele*ele) % this->totalSize) % this->totalSize;
        }

        return idx;
    }

    void rehash() {
        Node** oldTable = table;
        int oldSize = this->totalSize;
        this->totalSize = oldSize*2;
        this->currSize = 0; //Reseting the currSize to avoid the conflict on rehashing.

        table = new Node*[this->totalSize];
        for(int i=0; i<this->totalSize; i++) {
            oldTable[i]=NULL;
        }

        for(int i=0; i<oldSize; i++) {
            Node* temp = table[i];
            while(temp != NULL) {
                insert(temp->key, temp->value);
                temp = temp->nextPtr;
            }

            if(oldTable[i] != NULL) delete oldTable[i];
        }

        delete[] oldTable;

        return;
    }

public:
    HashTable(int size = 5) {
        this->totalSize = size;
        this->currSize = 0;

        table = new Node*[this->totalSize];

        for(int i=0; i<this->totalSize; i++) {
            table[i] = NULL;
        }
    }

    void insert(string key, int value) {
        int idx = hashFunction(key);

        Node* newNode = new Node(key, value);
        newNode->nextPtr = this->table[idx];
        this->table[idx] = newNode;

        this->currSize++;

        int lambda = this->currSize/(double)this->totalSize;
        if(lambda > 1)  rehash();

        return;
    }

    bool exists(string key) {
        //STEP 1: We will find the index position for our key.
        int idx = this->hashFunction(key);
        //STEP 2: We will store the head of the Linked List for searching the key.
        Node* tempHead = table[idx];
        //STEP 3: Check in that Linked List whether the key exists or not.
        while(tempHead != NULL) {
            if(tempHead->key == key)    return true; //If the key found return the true value.
            tempHead = tempHead->nextPtr; //If not found then move it one step ahead.
        }
        return false; //If we have reached the last value of the linked list and still we haven't found our key then in that case just return the false value.   
    }

    int search(string key) {
        //STEP 1: We will find the index position for our key.
        int idx = this->hashFunction(key);
        //STEP 2: We will store the head of the Linked List for searching the key.
        Node* tempHead = table[idx];
        //STEP 3: Check in that Linked List whether the key exists or not.
        while(tempHead != NULL) {
            if(tempHead->key == key)    return tempHead->value; //If the key found return the value present at that key.
            tempHead = tempHead->nextPtr; //If not found then move it one step ahead.
        }
        return -1; //If we have reached the last value of the linked list and still we haven't found our key then in that case just return the -1 value.   
    }

    void print() {
        for(int i=0; i<this->totalSize; i++) {
            cout<<"At index = "<<i<<"  ";
            Node* head = this->table[i];
            while(head != NULL) {
                cout<<"Key = "<<head->key<<", Value = "<<head->value<<" -> ";
                head = head->nextPtr;
            }
            cout<<endl;
        }
        return;
    }

    void remove(string key) {
        //STEP 1: For removing an key we must first find out the index of that key.
        int idx = hashFunction(key);
        //STEP 2: Once we have received our index value then we can make our temp variabel for traversing on the linked list.
        Node* currPtr = this->table[idx];
        Node* prevPtr = currPtr;
        while(currPtr != NULL) {
            
            if(currPtr->key == key) { //Removing or erasing logic of a Node from the memory.
                //While deleting the node we can come up with two situations:-
                if(currPtr == prevPtr) { //CASE-1 Where we need to delete the Head node.
                    table[idx] = currPtr->nextPtr;
                    delete currPtr;
                } else { //CASE-2 Where we need to delete a random Node from the linked list.
                    prevPtr->nextPtr = currPtr->nextPtr;
                    delete currPtr;
                }
            }
            prevPtr = currPtr;
            currPtr = currPtr->nextPtr;
        }

        return;
    }
};

int main() {
    HashTable ht;
    
    //Adding the data in the Hash Table
    ht.insert("India", 150);
    ht.insert("China", 150);
    ht.insert("US", 50);
    ht.insert("Nepal", 10);
    ht.insert("UK", 20);

    //Checking if the key India exists in our Hash Table or not.
    string key = "China";
    if(ht.exists(key)) {
        cout<<"Population of "<<key<<" is: "<<ht.search(key)<<endl;
    } else {
        cout<<"This Country doesn't exists in the Hash Table";
    }

    //Printing the complete Hash Table
    ht.print();

    //Removing the China Node from the LL.
    ht.remove(key);
    ht.remove("Nepal");
    cout<<"After Removal: -"<<endl;
    ht.print();

    return 0;
}