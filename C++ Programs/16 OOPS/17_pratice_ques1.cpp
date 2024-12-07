#include<iostream>
using namespace std;

class Parent{
public:
    Parent(){
        cout<<"Constructor of Parent.\n";
    }

    ~Parent(){
        cout<<"Destructor of Parent.\n";
    }
};

class Child : public Parent{
public:
    Child(){
        cout<<"Constructor of Child.\n";
    }

    ~Child(){
        cout<<"Destructor of Child.\n";
    }
};

int main(){
    Child obj;

    return 0;
}