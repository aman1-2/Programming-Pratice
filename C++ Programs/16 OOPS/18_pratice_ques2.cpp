#include<iostream>
using namespace std;

class Base{
public:
    virtual void print(){
        cout<<"Base\n";
        return;
    }
};

class Derived : public Base{
public:
    void print() override {
        cout<<"Derived\n";
        return;
    }
};

int main(){
    Base *b = new Derived; //Binding of this class is done at the Run-time
    b->print(); //That function is called whoase object is called.

    delete b;

    //So here we have created a pointer of Base Class but storing the address of a new Derived class Object so unfortunately the Derived object is created and its function will be called.

    return 0;
}