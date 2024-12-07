#include<iostream>
using namespace std;

class Example{
public:
    Example(){
        cout<<"Construnctor of static being Called....."<<endl;
    }

    ~Example(){
        cout<<"Destructor of static being called....."<<endl;
    }
};

class Example1{
public:
    Example1(){
        cout<<"Construnctor being Called....."<<endl;
    }

    ~Example1(){
        cout<<"Destructor being called....."<<endl;
    }
};

int main(){
    if(0==0){
        static Example obj1;
        Example1 obj2;
    }

    cout<<"Code Ending...."<<endl;

    return 0;
}