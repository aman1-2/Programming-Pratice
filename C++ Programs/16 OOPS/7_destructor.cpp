#include<iostream>
using namespace std;

class Car{
public:
    string name;
    string color;
    int* milege;

    Car(string name, string color, int* milege){
        this->name = name;
        this->color = color;
        this->milege = new int; //Dynamic allocation
        this->milege = milege;
    }

    Car(Car &obj){ //Copy constructor
        this->name = obj.name;
        this->color = obj.color;
        this->milege = new int; //Inside the copy constructor too we have first tried to provide it different memory location.
        *(this->milege) = *(obj.milege); //And then stored a value in it.
    }

    ~Car(){ //Destructor
        cout<<"Deleting the objects\n";
        if(this->milege != NULL){
            delete this->milege; //deleting the memory which was assigned in the heap.
        }
    }
};

int main(){
    int milege = 12;
    Car c1("Scorpio S12", "White", &milege);
    Car c2(c1);

    cout<<*(c2.milege)<<endl;
    cout<<*(c1.milege)<<endl;
    *(c2.milege) = 10;
    cout<<*(c2.milege)<<endl;
    cout<<*(c1.milege)<<endl;

    //Destructor is called twice because we have two objects being created.

    return 0;
}