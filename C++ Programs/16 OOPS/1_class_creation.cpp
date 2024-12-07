#include<iostream>
using namespace std;

class Student{
    //Properties or Attributes
    string name;
    float cgpa;

    /*These name and Cgpa of Student is not accessible to us outside this class as they come under the Private access 
    modifier but by default all the properties of a class comes under private until and unless we define its access modifier.*/

public: 
    //Function or Memmber-function or Method
    /*This getPercent function is accessible outside the student too.*/
    void getPercent(){
        cout<<(cgpa*10)<<"%"<<endl;
        return;
    }

    void setStudentData(string name, float cgpa){
        this->name = name;
        this->cgpa = cgpa;
    }

};

//Classes aren't given any memory space in the RAM.

int main(){
    Student s1; //These objects are given space inside memory.
    cout<<sizeof(s1)<<endl;

    s1.setStudentData("Rahul", 8);
    s1.getPercent();

    return 0;
}
