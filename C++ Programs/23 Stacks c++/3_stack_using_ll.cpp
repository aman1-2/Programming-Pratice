#include<iostream>
#include<list>
using namespace std;

template<class T>
class Stack {
private:
    list<T> ll;

public:
    void push(T value) {
        ll.push_front(value);
        return;
    }

    void pop() {
        ll.pop_front();
        return;
    }

    T top() {
        // if(isEmpty())   return -1;
        return ll.front();
    }

    bool isEmpty() {
        return ll.empty();
    }

};

int main() {
    Stack<char> s;
    s.push('c');
    s.push('b');
    s.push('a');
    cout<<s.top()<<" ";
    s.pop();
    cout<<s.top()<<" ";
    s.pop();
    cout<<s.top()<<" ";
    s.pop();
    cout<<s.top()<<" ";
    s.pop();
    cout<<s.top()<<" ";
    cout<<s.top()<<" ";

    return 0;
}