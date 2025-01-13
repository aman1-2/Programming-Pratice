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
        Node* temp = this->root;
        for(int i=0; i<key.size(); i++) {
            if(temp->children.count(key[i]) == 0)   temp->children[key[i]] = new Node();
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true;
    }

    bool search(string key) {
        Node* temp = this->root;
        for(int i=0; i<key.size(); i++) {
            if(temp->children.count(key[i]) == 0)   return false;
            temp = temp->children[key[i]];
        }
        return temp->endOfWord;
    }
    
    void longestHelper(Node* root, string &ans, string temp) { //This will be our actual recursive function.
        for(pair<char, Node*> child: root->children) {
            //All the work we have to do when our endOfWord value is true.
            if(child.second->endOfWord == true) {
                temp += child.first;
                //Checking the size of the temp and ans strings
                if((temp.size() == ans.size() && temp < ans) || (temp.size() > ans.size())){
                    ans = temp; //If size is same ans is equal to temp and if size is not same then the string which is longer will be the answer.
                }

                longestHelper(child.second, ans, temp);
                temp = temp.substr(0, temp.size()-1);
            }
        }

    }

    //Now we know that oue this function but be recurive and we must have passed the root value to it.But in our Trie root is a private member therefore we cann't pass the value of root as such from here so what we will do is we will create a helper function of this as well.
    string longestStringWEO() {
        //One we will take an empty string as ans.
        string ans = "";
        longestHelper(this->root, ans, "");
        return ans;
    }
};

//We make to create a function of string type called as longest.
string longestString(vector<string> &dict) {
    //Step 1: We build our Trie data structure out of the words given.
    Trie trie;

    for(int i=0; i<dict.size(); i++) {
        trie.insert(dict[i]);
    }

    //Step 2: Find the longest word for which the end of the letter for each of the word comes out to be true
    //For this we will make a internal function and then make a call to that internal function fom our trie.

    return trie.longestStringWEO();
}

int main() {
    vector<string> dict = {"a", "banana", "app", "appl", "ap", "apply", "apple"};

    cout<< longestString(dict) <<endl;
    return 0;
}