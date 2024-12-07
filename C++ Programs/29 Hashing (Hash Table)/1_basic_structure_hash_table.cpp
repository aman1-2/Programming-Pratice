/*
STEP 1: Before we make a Hash Table we first need to create a Class of Node type. And this Node Class will just represent our Linkekd List Node Class.
    Properties these Node Class will hold is that - (i)Every Node will have a string type key and an integer type value with a pointer to its next Node.

STEP 2: Now we will create an another class which will be our final Hash Table class.
    What all data do we have in our Hash Table is -
    (*) First of all we can store the total i.e. the size of the Hash Table if we have a Hash table being implemented with the Array then we can implement it using a Dynamic Array of some size. 
    Now this size which we will pass we will try to pass we will store it as it will at some point will become the total size of the Array. And there is one more reason for storing this Size because we need size at the time of Hashing. So that we can just take modulo with size.
    (*) 

*/

#include<iostream>
using namespace std;

class Node { //This Node class represents every Linked List which will be created at array's index.
public:
    string key;
    int value;
    Node* nextPtr;

    Node(string key, int val) {
        this->key = key;
        this->value = val;
        this->nextPtr = NULL;
    }
};

class HashTable {
    int totalSize;
    int currSize; //The reason for taking currSize is becuase of Rehashing the concept of Rehashing we will study a bit later. For Doing rehashing we need to have access of our currsize
    Node** table; //This will be our table
public:
    HashTable(int size = 5) { //Here we have passed a default size value for our Hash Table which is 5.
        this->totalSize = size;
        currSize = 0;

        //Now we will just initalize our table. Initializing a Table means we will allocate it some memory
        this->table = new Node*[this->totalSize]; //This line will just create a Table for us (which will be an Array of Node* and at each index of this Array we will have a Node*'s Garbage value being stored).
        //But what we want to do is we want to initalize our starting index value of our Array with Null values. To do this task we can run a loop in our constructor only.

        for(int i=0; i<this->totalSize; i++) {
            this->table[i] = NULL;
        }
        //Now this How we have created our Hash table this is only the part of Hash Table creation and Initalization with NULL values.
    }
};

int main() {

    return 0;
}