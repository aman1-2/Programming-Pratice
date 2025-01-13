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
        return;
    }

    bool search(string key) {
        Node* temp = root;
        for(int i=0; i<key.size(); i++) {
            if(temp->children.count(key[i]) == 0)   return false;
            temp = temp->children[key[i]];
        }
        return temp->endOfWord;
    }
};



int countUniqueSubstring(string str) {
    //Step 1: Finding the suffix for the string.
    //Step 2: We need to build our Trie data structure
    Trie trie;

    for(int i=0; i<str.size(); i++) {
        trie.insert(str.substr(i));
    }

    //Step 3: Now we need to count the number of nodes in our Trie.
    
}

int main() {
    string str = "ababa";
    int res = countUniqueSubstring(str);
    return 0;
}