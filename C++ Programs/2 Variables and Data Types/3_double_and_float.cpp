#include<iostream>
#include<iomanip> //For precision
using namespace std;
int main(){
    float PI = 3.14159265359; //Stores precision upto 7 digits
    double PI2 = 3.14159265359; //Stores precision upto 15 digits

    cout<<"Float = "<<PI<<endl; //In normal scenario the precision which we get is upto 5 places in cout case.
    cout<<"Double = "<<PI2<<endl;

    //But say we set the precision in that case.
    cout<<setprecision(12)<<"Float = "<<PI<<endl; //Not correct
    cout<<setprecision(12)<<"Double = "<<PI2<<endl; //Stores correct

    return 0; 
}