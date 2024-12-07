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

    ~Node() { //This destructor will help us delete the whole LL repatedly for us
        if(this->nextPtr != NULL) {
            delete this->nextPtr;
        }
    }

};

class HashTable {
    int totalSize;
    int currSize; //Rehashing
    Node** table;

    int hashFunction(string key) { //In this hashFunction we will get a key as argument which will be then converted to some integer value.
        int idx = 0;
        for(char ch: key) {
            int ele = ch - 0;
            idx += (ele * ele)%this->totalSize;
        }

        return idx;
    }
    /**
     * Time complexity - O(n)
     */
    void rehash() { //This function will do Rehashing.
        Node** oldTable = this->table; //This will help us store our old-table.
        int oldSize = this->totalSize; //This will store our old table size value.

        //Now we will just update our total size value.
        this->totalSize = 2*totalSize;
        this->currSize = 0; //Reseting the currSize to avoid the conflict on rehashing

        //Now we will make a new table so the work which we did in the HashTable constructor that work we need to again do it.
        table = new Node*[this->totalSize]; //This statement will create a complete new table for us it is not like that we are just increasing the size of the old table rather we will be just creating a all brand new table. We will just copy the old data table to our new data table.
        for(int i=0; i<this->totalSize; i++) { //Intializing each value of the table with a NULL pointer.
            table[i]=NULL;
        }

        // now we need to copy the old table values and rehash on those old keys and store it at new index position in our new Hash table.
        //For coping the old values we can just loop on the old values.
        for(int i=0; i<oldSize; i++) {
            //So in our old table at each and every index we will receive the head of the LL.
            Node* temp = oldTable[i]; //Storing the linked list heads.
            //Now we would traverse our LL.
            while(temp != NULL) {
                //Till the time our LL is not empty we just need to insert the key-value pair in our new table.
                insert(temp->key, temp->value);
                temp = temp->nextPtr;
            }

            //Once we have stored the values in new table we can then delete the values from old table.
            if(oldTable[i] != NULL) delete oldTable[i]; //Now removing like this will only remove the head node but let's say we need to delete its successor nodes too then we would just need to have its destructor.
        }
        //Like this repeatedly our all nodes value will get rehashed.

        delete[] oldTable; //This will help us delete our oldTable.

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
        //The first Step in the void insert function is that we need to find the index position where we need to insert our key-value pair.
        int idx = hashFunction(key); //This hashFunction can be created as a private function within our Hash Table class.

        //Once we have recieved our Index value then our Second step is to create a new Node which we want to insert in our Hash Table.
        Node* newNode = new Node(key, value);
        //Now this newNode we need to add in our Linked List and where will we get that linked list. So that LL will be present at the index position recieved at that index position we will recieve the head of the Linked List.
        //The current Linked List head is present at the table's index position. From here we will just make our currHead as the pointer to the newNode and make the newNode as the head of the LL.
        //This currHead when we will take out for the first time will always going to be NULL initally therefore instead of finding the currHead we can directly assign the value in the table[idx] position.
        newNode->nextPtr = table[idx];
        table[idx] = newNode;

        //Once we make our new Node insertion we will just increment our current size.
        this->currSize++;

        //Rehashing
        double lambda = this->currSize/(double)this->totalSize;
        if(lambda > 1)  rehash(); //If the lambda value is more then 1 than we will just call rehash function for rehashing.
        //Rehash takes O(n) T.C in worst case.
        return;
    }
};

int main() {

    return 0;
}