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
};

bool breakHelper(Trie &trie, string key) { 
    if(key.size() == 0)   return true;

    //The First step in this function is to break our key into smaller pieces.
    for(int i=0; i<key.size(); i++) {
        //For breaking our key we will separate it into two parts one as first string and other as the second.
        string first = key.substr(0,i+1); //This is our first key which we want to search in our Trie. For the second string we will make a recursive call.
        if(trie.search(first) && breakHelper(trie, key.substr(i+1))){
            //This shows that if our first half of the string is there in the trie then look for the second half and if both first and second parts are there in the trie then return true.
            return true;
        }
        //Lets suppose first half was there and seconf half was not there in that case it will return false.
        //Or if say the first half was only not there this means we have marked the cut at wrong position. And hence need to return a false value.
    }

    return false;
}

bool wordBreak(vector<string> dictionary, string key) {
    //First step is to build our Trie Data Structure so that we can have the search operation efficient in it.
    //As such Trie is not the part of the STL C++ therefore anytime if we need to implement trie then we have to write it from scratch itself.
    Trie trie;
    for(int i=0; i<dictionary.size(); i++) {
        trie.insert(dictionary[i]);
    }

    return breakHelper(trie, key); //This helper function will help us to break our string into pieces.
}

int main() {
    vector<string> dictionary = {"i", "like", "sam", "samsung", "mobile", "ice"};
    cout << wordBreak(dictionary, "aman");

    return 0;
}