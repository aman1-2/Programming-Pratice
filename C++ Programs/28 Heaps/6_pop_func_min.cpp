#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Heap {
private:
    vector<T> vec;

    void heapify(int parentIdx) {
        if(parentIdx >= vec.size()) return;

        int leftIdx = 2*parentIdx + 1;
        int rightIdx = 2*parentIdx + 2;

        int minIdx = parentIdx;
        if(leftIdx < vec.size() && vec[leftIdx] < vec[minIdx])  minIdx = leftIdx; 
        if(rightIdx < vec.size() && vec[rightIdx] < vec[minIdx])    minIdx = rightIdx;

        swap(vec[parentIdx], vec[minIdx]);

        if(minIdx != parentIdx) heapify(minIdx);
    }
public:
    void push(T value) {
        vec.push_back(value);

        int childIdx = vec.size()-1;
        int parentIdx = (childIdx-1)/2;

        while(parentIdx >= 0 && vec[childIdx] < vec[parentIdx]) {
            swap(vec[childIdx], vec[parentIdx]);

            childIdx = parentIdx;
            parentIdx = (childIdx-1)/2;
        }
    }

    void pop() {
        swap(vec[0], vec[vec.size()-1]);

        vec.pop_back();
        
        heapify(0);
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

    heap.push(1);
    heap.push(10);
    heap.push(9);
    heap.push(100);
    heap.push(3);

    while(!heap.empty()) {
        cout<<heap.top()<<endl;
        heap.pop();
    }

    return 0;
}