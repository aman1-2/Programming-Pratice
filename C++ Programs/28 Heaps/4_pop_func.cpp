#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Heap {
private:
    vector<T> vec;

    //This heapify function has specific work of its which is correcting the heap structure. In the heapify function we pass the parent index value in it.
    void heapify(int parentIdx) { 
        //BASE CASE: If the parentIdx at any point goes beyond the vector size then we just need to return from there.
        if(parentIdx >= vec.size())  return;

        //Finding the left and right child of the Heap.
        int leftIdx = 2*parentIdx + 1;
        int rightIdx = 2*parentIdx + 2;

        //Now we have to find the maximum out the left, right and current value.
        int maxIdx = parentIdx; //At initial point make the maximum index equal to the parent index.
        if(leftIdx < vec.size() && vec[leftIdx] > vec[maxIdx]) {
            //if the left child is a valid child and is greater then the parent value in the case the maximum index will be left child index.
            maxIdx = leftIdx;
        }
        if(rightIdx < vec.size() && vec[rightIdx] > vec[maxIdx]) {
            //if the right child is a valid child and is greater then the parent value just update the maxIdx value.
            maxIdx = rightIdx;
        }

        //Once we have found the maxIdx value just swap it with the parent indx value.
        swap(vec[parentIdx], vec[maxIdx]);

        //Calling the Heapify function again if the swapping is made between the parent and child relation.
        if(maxIdx != parentIdx) heapify(maxIdx);
        //If max index is equal to the parent index in such case the parent is swapped with parent only and making a heapify call for parent again won't make any sense out of it.
    }

public:
    void push(T value) {
        vec.push_back(value);

        T childIdx = vec.size() - 1; //Current added element's index
        T parentIdx = (childIdx-1)/2;

        while(parentIdx >= 0 && vec[childIdx] > vec[parentIdx]) {
            swap(vec[childIdx], vec[parentIdx]);

            childIdx = parentIdx;
            parentIdx = (childIdx-1)/2;
        }
    }

    void pop() {
        if(vec.empty())   return;

        //STEP 1: Swapping of the last element with the first element.
        swap(vec[0], vec[vec.size()-1]);

        //STEP 2: Removing of the element from the vector's end.
        vec.pop_back();

        //STEP 3: Once the element is removed Fix the heap by calling the Heapify function.
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