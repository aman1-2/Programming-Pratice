#include<iostream>
#include<vector>
using namespace std;

template<class T>

class Stack {
private:
    vector<T> stacks;

public:
    void push(T value) { //O(1)
        stacks.push_back(value);
        return;
    }
    
    void pop() { //O(1)
        if(this->isEmpty())   return;
        stacks.pop_back();
        return;
    }

    T top() { //O(1)
        // if(this->isEmpty())   return -1;
        int idx = stacks.size()-1;
        return stacks[idx];
    }

    bool isEmpty() {
        return (stacks.size() == 0);
    }
};

int main() {
    Stack<char> s;
    s.push('a');
    s.push('b');
    s.push('c');
    cout<<s.top()<<" ";
    s.pop();
    cout<<s.top()<<" ";
    s.pop();
    cout<<s.top()<<" ";

    return 0;
}