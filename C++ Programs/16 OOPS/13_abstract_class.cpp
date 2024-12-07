#include<iostream>
using namespace std;

//And this class is a Abstract Class.
//Having any one Pure virtual function inside the class makes that class a Abstract class automatically.
class Shape{
public:
    virtual void draw() = 0; //Its a abstract function or we can too say it as a Pure virtual function.
};

class Circle : public Shape{
public:
    void draw(){
        cout<<"Circle"<<endl;
        return;
    }
};

class Square : public Shape{
public:
    void draw(){
        cout<<"Square"<<endl;
        return;
    }
};

int main(){
    Circle obj1;
    obj1.draw(); 

    Square obj2;
    obj2.draw();

    //If we try to create a obj of Abstract class it will throw an error to us.
    return 0;
}