#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Heap {
private:
    //This vector will only for the CBT and helps to represent the parent-child relation in vectors.
    vector<T> vec; //Internally using a vector for storing the data elements.
public:
    //Implementation of Heap function's
    void push(T value) { //Time Complexity for this function comes out to be O(log n).
        //STEP 1: Adding or inserting(pushing) the element at the vector's back.
        vec.push_back(value); //T.  - for inserting element is O(1)

        //STEP 2: Calculating the parent and child index value
        T childIdx = vec.size() - 1; //Child index is the size of the vector.
        T parentIdx = (childIdx - 1)/2; //Parent index is calculated.
        //These above are also constant operation.
        
        /**
         * STEP 3: fixing the heap.
         * We will keep on swaping the elements till the time our parent index is not less then 0
         * And the child index value is greater then the parent index value till that time we need to swap the values.
         * And then update the value of child and parent index.
         */
        while(parentIdx >= 0 && vec[childIdx] > vec[parentIdx]) { //This loop has a T.C of O(log n)
            swap(vec[childIdx], vec[parentIdx]);
            
            //Updating child and parent index value.
            childIdx = parentIdx; //Making child index same as the parent index.
            parentIdx = (childIdx-1)/2; //Calculating the new parent index value.
        }
    }

    T top() { //Time Complexity for extracting the top most element comes out to be O(1).
        //Returning the Highest priority index value i.e. the top most value of the index.
        //And since we have created a vector the first element of the vector is always at the 0th index.
        return vec[0];
    }

    bool empty() { //Time Complexity for checking if the Heap is empty is not is too O(1).
        //Returning the boolean value if the vector size is 0 i.e. if the vector is empty then we have to return true otherwise false.
        return vec.empty();
    }
};

int main() {
    Heap<int> heap;
    cout<<"Is heap Empty: "<<heap.empty()<<endl;
    heap.push(1);
    heap.push(10);
    heap.push(9);
    cout<<heap.top()<<endl;
    heap.push(100);
    cout<<heap.top()<<endl;
    heap.push(3);
    cout<<heap.top()<<endl;
    cout<<"Is heap Empty: "<<heap.empty()<<endl;
    
    return 0;
}