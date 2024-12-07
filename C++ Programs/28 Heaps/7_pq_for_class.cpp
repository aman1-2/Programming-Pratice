#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Student {
public:
    string name;
    int marks;

    Student(string name, int marks) {
        this->name = name;
        this->marks = marks;
    }

    //This operator overloading will tell on what basis or on what properties these compariosn will take place.
    bool operator < (const Student &obj) const { //Here we are trying to define what a class less then operator should means while comparing the two objects of the Student class.
        return this->marks < obj.marks; //If inside operator is same as the outside defining operator then this means we are trying to define a default max heap.
        //if the outer and inner operator are same in that case it will perform the same default logic.
        //Here only if we switch the outer and inner operator then the min heap could be created.
    }
};

int main() {
    priority_queue<Student> pq;
    pq.push(Student("aman", 65));
    pq.push(Student("aditya", 95));
    pq.push(Student("anjali", 85));

    while(!pq.empty()) {
        cout<<pq.top().name<<", "<<pq.top().marks<<endl;
        pq.pop();
    }

    return 0;
}