#include<iostream>
#include<queue>
using namespace std;

queue<int> interleave2Queue(queue<int> &original) { //O(n) <- Time and Space complexity
    int size = original.size();
    queue<int> firstQu;

    for(int i=0; i<size/2; i++) {
        firstQu.push(original.front());
        original.pop();
    }

    while(!firstQu.empty()) {
        original.push(firstQu.front());
        firstQu.pop();

        original.push(original.front());
        original.pop();
    }

    return original;
}

int main() {
    queue<int> qu;
    for(int i=1 ;i<11; i++) {
        qu.push(i);
    }

    queue<int> res = interleave2Queue(qu);
    while(!res.empty()) {
        cout<<res.front()<<" ";
        res.pop();
    }

    return 0;
}