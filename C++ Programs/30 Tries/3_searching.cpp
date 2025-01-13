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

class Trie { //Initialize time complexity for building a trie of n array words comes out to be O(L * n)
    Node* root;
public:
    Trie() {
        this->root = new Node();
    }

    void insert(string key) {
        Node* temp = root;
        for(int i=0; i<key.size(); i++) {
            if(temp->children.count(key[i]) == 0) {
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }

        temp->endOfWord = true;

        return;
    }

    bool search(string key) { //Time complexity for Search too comes out to be O(L)
        Node* temp = root; //Initialized a temp node which will help in traversing the trie.

        for(int i=0; i<key.size(); i++) { //A loop runing of key size.
            if(temp->children.count(key[i]) == 0)   return false; //Making a check in the children map of the current level's temp node if the count in the map is zero then return false. Which means that letter doesn't exists.
            temp = temp->children[key[i]]; //And lets say if the key exists then we have to just udate the temp value to the next level.
        }

        return temp->endOfWord; //At the end of the loop when the we have traversed the whole string then check the temp nodes endOfWord must to be true to indicate that the word truly exists.
    }
};

int main() {
    vector<string> words = {"the", "a", "there", "their", "any", "thee"};

    Trie trie;

    for(int i=0; i<words.size(); i++) {
        trie.insert(words[i]);
    }

    cout<<trie.search("any");

    return 0;
}