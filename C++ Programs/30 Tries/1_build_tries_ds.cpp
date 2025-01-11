#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Node { //We have created a Node which will help us to create the node of the trie
public:
    unordered_map<char, Node*> children; //This map is going to store the child node for 
    //each node where for each node we will storing the character and its node pointer address.
    bool endOfWord; //A boolean value to indicate whether this node is a end character of a word or not.

    Node() {
        //Inside this constructor we won't be initializing the children as such. If our map is
        //empty this means every children is null or no children are available for that node.
        endOfWord = false; //Intially for each node we can initialize the endOfWord as false.
        //Until we explicitly set it true till then it won't be true.
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        //What tries constructor does is at root node it jsut stores a new node value. At the root node we
        //can initialize it in starting only as the root node value is generally empty only.
        root = new Node();
    }
};

int main() {
    vector<string> words = {"the", "a", "there", "their", "any", "thee"}; //For these collection of words we will create a Trie DS.

    Trie trie; //This will build a empty Trie Data Structure for us.
    return 0;
}