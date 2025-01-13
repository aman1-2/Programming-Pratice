#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    int freq; //We have added this freq count extra in our Node class to have the branch count.

    Node() {
        this->endOfWord = true;
        this->freq = 1;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        this->root = new Node();
        this->root->freq = -1;
    }

    void insert(string key) {
        Node* temp = root;
        for(int i=0; i<key.size(); i++) {
            if(temp->children.count(key[i]) == 0){
                temp->children[key[i]] = new Node();
                // temp->children[key[i]]->freq = 1;
            }
            else    temp->children[key[i]]->freq++;
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true;
        return;
    }

    bool search(string key) {
        Node* temp = root;
        for(int i=0; i<key.size(); i++) {
            if(temp->children[key[i]] == 0) return false;
            temp = temp->children[key[i]];
        }
        return temp->endOfWord;
    }

    //Time complexity for this getPrefix function is too O(L).
    string getPrefix(string key) { //This function for our key will be retuning the shortest unique prefix.
        string ans = ""; //An ans variable to store our prefix value
        Node* temp = root; //Temp node for traversing on our trie.

        for(int i=0; i<key.size(); i++){
            //First of all we store the character in our ans string.
            ans += key[i];
            //And then look for the character's frequency
            if(temp->children.count(key[i]) == 1 && temp->children[key[i]]->freq == 1) {
                break; //As soon as you see the character frequency as 1 it means you have got your prefix.
            }
            temp = temp->children[key[i]]; //Lets say if the character is not there or the frequency count is more than 1. In that case don't need to do anything and just update the temp value.
        }

        return ans;
    }
};

vector<string> prefixProblem(vector<string> &words) { //Total time complexity for finding prefix for n word comes out to be O(n * L).
    vector<string> ans_words;

    //Step 1: Is to build a Trie data structure.
    Trie trie;
    for(int i=0; i<words.size(); i++) {
        trie.insert(words[i]);
    }

    //Step 2: Finding the prefix for each word by traveling our trie data structure.
    for(int i=0; i<words.size(); i++) {
        string res = trie.getPrefix(words[i]);
        if(res != "")   ans_words.push_back(res);
    }

    return ans_words;
}

int main() {
    vector<string> words = {"zebra", "dog", "duck", "dove"};
    vector<string> ans = prefixProblem(words);

    for(string word:ans) {
        cout<<word<<" ";
    }

    return 0;
}