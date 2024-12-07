#include<iostream>
using namespace std;

class Animal{
public:
    string color;

    void breathe(){
        cout<<"Animals can Breathe...\n";
        return;
    }

    void eat(){
        cout<<"Animals can Eats...\n";
        return;
    }
};

class Fish : public Animal{
public:
    int fins;

    void swim(){
        cout<<"Fish can swim...\n";
        return;
    }
};

int main(){
    Fish f1;
    f1.swim(); //This is the property of fish class itself
    f1.breathe(); //This is the inherited property from the animal class.
    f1.eat(); //This is the inherited property from the animal class.
}