#include<iostream>
using namespace std;

class Parent{
public:
    virtual void hello(){
        cout<<"Hello from parent class"<<endl;
        return;
    }
};

class Child: public Parent{
public:
    void hello(){
        cout<<"Hello from child class"<<endl;
        return;
    }
};

int main(){
    Child obj;
    Parent *ptr;

    ptr = &obj; //Run time binding as we are trying to point a pointer to the different class obj and this is possible due to inheritance
    ptr->hello(); //Run time polymorphism for the virtual function and child's hello() will be called.

    return 0;
}