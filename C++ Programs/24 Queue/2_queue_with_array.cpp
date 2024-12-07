#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Queue {
    vector<T> v;
    int idx;

public: 
    Queue() {
        idx = -1;
    }

    void push(T value) {
        v.push_back(value);
        idx++;
    }

    void pop() {
        if(idx < 0){
            return;
        }
        idx--;
    }

    T front() {
        if(idx < 0) return -1;
        return v[idx];
    }
};

int main() {
    Queue<int> qu;
    qu.pop();
    cout<<qu.front()<<" ";
    qu.push(4);
    cout<<qu.front()<<" ";
    qu.push(5);
    qu.push(6);
    cout<<qu.front()<<" ";
    qu.pop();
    cout<<qu.front()<<" ";
    qu.pop();
    cout<<qu.front()<<" ";
    qu.pop();
    cout<<qu.front()<<" ";

    return 0;
}