#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord;

    Node() {
        this->endOfWord = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        this->root = new Node();
    }

    void insert(string key) { //Time-Complexity is : O(L)
        Node* temp = this->root; //Firstly created a Temp Node for Traversing and checking whether the character exists in our Tire or not because we can't keep on changing the root's value.

        for(int i=0; i<key.size(); i++) {
            //If the value of the count comes out to be 1 in that case the key exists and we don't need to do anything.
            if(temp->children.count(key[i]) == 0) { //If the count of the character of our key is not present in the map of the ith node then we need to add that character as its child node.
                temp->children[key[i]] = new Node(); //This is insertion of a new node.
            }

            temp = temp->children[key[i]]; //For increasing the level of the temp for the next we need to do update it.
        }

        temp->endOfWord = true; //At the end of the loop which indicate the word has ended then at that position of temp we need to update the boolean value endOfWord
    }
};

int main() {
    vector<string> words = {"the", "a", "there", "their", "any", "thee"};

    Trie trie; //A trie Object created for our trie class.

    for(int i=0; i<words.size(); i++) {
        trie.insert(words[i]); //And each word from the words array to the Trie.
    }
    
    return 0;
}