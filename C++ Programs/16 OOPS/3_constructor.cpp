#include<iostream>
using namespace std;

class Car{
    string name;
    string engineType;
public:
    Car(){ //Its a Non-parametrized constructor.
        cout<<"Non-parametrized constructor being called."<<endl;
    }
    Car(string name, string engineType){ //This is a Constructor similar to a function without a return type or without the function data type.
        //Its a parametrized constructor.
        this->name = name;
        this->engineType = engineType;
    }

    void getCarDetails(){
        cout<<"Car name is: "<<this->name<<endl;
        cout<<"Car Engine Type is: "<<this->engineType<<endl;
        return;
    }
};

int main(){
    Car c1("Scorpio S12", "M-Hawk"); //Called Parametrized constructor as passed few parameters in it.
    Car c2("Fortuner", "Injector");
    Car c3("Old Scorpio", "M-2-di");
    Car c4; //Called Non-Parametrized constructor as we haven't passed any parameters in it.

    cout<<"Car-1 details:- "<<endl;
    c1.getCarDetails();
    cout<<"Car-2 details:- "<<endl;
    c2.getCarDetails();

    return 0;
}