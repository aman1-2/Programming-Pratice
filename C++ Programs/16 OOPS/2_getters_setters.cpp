#include<iostream>
using namespace std;

class Car{
    //These properties are private to the function and won't be accessible outside the class.
    int model_number;
    string name;

public:
    void setCarData(string name, int model_number){ //A setter function which will be used for assigning the values of the class car properties.
        this->name = name;
        this->model_number = model_number;
        return;
    }

    void getCarDetails(){ //A getter function with whose help we can access the value present inside the properties because they cann't be accessed outside the class.
        cout<<"Name of the car is: "<<this->name<<endl;
        cout<<"Model of the car is: "<<this->model_number<<endl;
        return;
    }

};

int main(){
    Car c1, c2;
    c1.setCarData("Scorpio S12", 1206);
    c2.setCarData("Fortuner", 612);

    cout<<"Car-1 details:- "<<endl;
    c1.getCarDetails();
    cout<<"Car-2 details:- "<<endl;
    c2.getCarDetails();

    return 0;
}