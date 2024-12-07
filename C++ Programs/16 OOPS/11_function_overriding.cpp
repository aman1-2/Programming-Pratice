#include<iostream>
using namespace std;

class Parent{
public:
    void show(){
        cout<<"Parent class show function"<<endl;
        return;
    }
};

class Child : public Parent{
public:
    void show(){
        cout<<"The show of parent is overriden inside the child class object even though the above show was inherited by it.\n\n";
        return;
    }
};

int main(){
    Child obj;
    obj.show();

    Parent obj1;
    obj1.show();

    return 0;
}