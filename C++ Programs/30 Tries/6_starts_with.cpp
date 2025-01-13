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

    void insert(string key) {
        Node* temp = root;
        for(int i=0; i<key.size(); i++) {
            if(temp->children.count(key[i]) == 0)   temp->children[key[i]] = new Node();
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true;
    }

    bool search(string key) {
        Node* temp = root;
        for(int i=0; i<key.size(); i++) {
            if(temp->children.count(key[i]) == 0)   return false;
            temp = temp->children[key[i]];
        }
        return temp->endOfWord;
    }

    bool startsWith(string prefix) {
        Node* temp = root;
        for(int i=0; i<prefix.size(); i++) {
            if(temp->children.count(prefix[i]) == 0)    return false;
            temp = temp->children[prefix[i]];
        }
        return true; //Similar to search function only this time at the end of the loop we are not check the endOfWord boolean value which temp is pointing instead directly returning true value.
    }
};

int main() {
    vector<string> words = {"apple", "app", "mango", "man", "woman"};
    string prefix = "app";

    //Step 1: Buiding a Trie data structure.
    Trie trie;

    for(string word:words) {
        trie.insert(word);
    }

    cout<<trie.startsWith(prefix); //Returning the value if there is any prefix for the word it is given.

    return 0;
}