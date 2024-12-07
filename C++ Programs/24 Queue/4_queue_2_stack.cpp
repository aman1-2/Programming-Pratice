/*We can implement Queue using 2 Stacks in two different ways:-
(i) One is by pushing the elements at O(n) time complexity -> This we have implemented below.
(ii) Other is by poping the elements at O(n) time complexity.*/

#include<iostream>
#include<stack>
using namespace std;

class Queue {
    stack<int> stack1;
    stack<int> stack2;

public:
    void push(int data) {//Time complexity: O(n)
        if(stack1.empty()){
            stack1.push(data);
            return;
        }

        while(!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }

        stack1.push(data);

        while(!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }

        return;
    }

    void pop() { //O(1)
        if(stack1.empty())  return;
        stack1.pop();
        return;
    }

    int front() { //O(1)
        if(stack1.empty())  return -1;
        return stack1.top();
    }

    bool empty() {
        return stack1.empty();
    }
};

int main() {
    Queue qu;

    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.push(5);

    while(!qu.empty()) {
        cout<<qu.front()<<" ";
        qu.pop();
    }

    return 0;
}