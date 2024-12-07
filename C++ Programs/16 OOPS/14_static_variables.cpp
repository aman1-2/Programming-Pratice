#include<iostream>
using namespace std;

void nonStatic(){
    int count = 0;
    count++;
    cout<<"Not a Static Variable: "<<count<<endl;
    return;
}

void StaticFun(){
    static int count = 0; //Makes the variable Global
    count++;
    cout<<"Static Variable: "<<count<<endl;
    return;
}

class NonStaticClass{
public:
    int x = 0;
};

class StaticClass{
public:
    //Inside the class we generally use the static keyword with the const for making a class variable global as well as constant.
    //Here this static variable will be made for a class each object will get the same varibale.
    //we generally initialze it with Scope Resolution.
    static int x; 
};

int StaticClass::x = 0;
// :: -> Its a scope resolution this statement tells x which lies under the scope of StaticClass.

int main(){
    nonStatic(); //1
    nonStatic(); //1
    nonStatic(); //1

    StaticFun(); //1
    StaticFun(); //2
    StaticFun(); //3

    NonStaticClass obj1;
    NonStaticClass obj2;
    NonStaticClass obj3;
    cout<<obj1.x++<<endl; //0
    cout<<obj2.x++<<endl; //0
    cout<<obj3.x++<<endl; //0

    StaticClass obj4;
    StaticClass obj5;
    StaticClass obj6;
    cout<<obj4.x++<<endl; //0
    cout<<obj5.x++<<endl; //1
    cout<<obj6.x++<<endl; //2

    return 0;
}