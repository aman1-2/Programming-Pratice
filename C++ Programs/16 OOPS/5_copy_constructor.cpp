#include<iostream>
using namespace std;

class Car{
    string name;
    string engineType;
public:
    Car(string name, string engineType){
        this->name = name;
        this->engineType = engineType;
    }

    //Copy Constructor
    Car(Car &obj){
        //Now this time this Custom copy constructor will be called.
        cout<<"Copy Constructor Called:-\n";
        this->name = obj.name;
        this->engineType = obj.engineType;
    }

    void getCarDetails(){
        cout<<"Car name is: "<<this->name<<endl;
        cout<<"Car Engine Type is: "<<this->engineType<<endl;
        return;
    }
};

int main(){
    Car c1("Scorpio S12", "M-Hawk"); 
    Car c2(c1); //Here calling even though we haven't created any copy contructor c++ create's it by default if its not there.
    //Now c2 object will have the same properties(Attributes) values as c1.
    //But we can too create our own copy constructor too.

    cout<<"Car-1 details:- "<<endl;
    c1.getCarDetails();
    cout<<"Car-2 details:- "<<endl;
    c2.getCarDetails();

    return 0;
}