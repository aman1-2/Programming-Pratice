/*
Question 1 : Create a class to store Complex numbers. Using operator overloading, 
create the logic to subtract one complex number from another.

Note - In Complex numbers, the real part of 1st gets subtracted from the real part of 
2nd number. Same goes for the imaginary part
*/

#include<iostream>
using namespace std;

class Complex{
    int real, img;
public:
    Complex(int real, int img){
        this->real = real; 
        this->img = img;
    }

    void show(){
        cout<<this->real<<" + "<<this->img<<"i\n";
        return;
    }

    Complex operator-(Complex &c2){
        int resReal = this->real - c2.real;
        int resImg = this->img - c2.img;
        return Complex (resReal, resImg);
    }
};

int main(){
    Complex c1(1,2);
    Complex c2(3,4);

    Complex c3 = c2 - c1;

    c3.show();

    return 0;
}