#include<iostream>
#include<vector>
using namespace std;

class Stack {
private:
    vector<int> stacks;

public:
    void push(int value) { //O(1)
        stacks.push_back(value);
        return;
    }
    
    void pop() { //O(1)
        if(this->isEmpty())   return;
        stacks.pop_back();
        return;
    }

    int top() { //O(1)
        if(this->isEmpty())   return -1;
        int idx = stacks.size()-1;
        return stacks[idx];
    }

    bool isEmpty() {
        return (stacks.size() == 0);
    }
};

int main() {
    Stack s;
    s.push(3);
    s.push(2);
    s.push(1);
    cout<<s.top()<<" ";
    s.pop();
    cout<<s.top()<<" ";
    s.pop();
    cout<<s.top()<<" ";

    return 0;
}