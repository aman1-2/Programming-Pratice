#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Heap {
private:
    vector<T> vec;
public:
    void push(T value) {
        vec.push_back(value);

        int childIdx = vec.size()-1;
        int parentIdx = (childIdx-1)/2;

        while(parentIdx >=0 && vec[childIdx] < vec[parentIdx]) {
            swap(vec[childIdx], vec[parentIdx]);

            childIdx = parentIdx;
            parentIdx = (childIdx-1)/2;
        }
    }

    T top() {
        return vec[0];
    }

    bool empty() {
        return vec.empty();
    }
};

int main() {
    Heap<int> heap;
    heap.push(100);
    heap.push(10);
    heap.push(9);
    cout<<heap.top()<<endl;
    heap.push(7);
    cout<<heap.top()<<endl;
    heap.push(3);
    cout<<heap.top()<<endl;
    
    return 0;
}