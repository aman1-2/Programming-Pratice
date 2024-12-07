#include<iostream>
using namespace std;

class ComplexNumber{
    int real, img;
public:
    ComplexNumber(int real, int img){
        this->real = real;
        this->img = img;
    }

    void show(){
        cout<<this->real<<" + "<<this->img<<"i"<<endl;
        return;
    }

    //Operator Overloading
    ComplexNumber operator+ (ComplexNumber& c2){
        int resReal = this->real + c2.real;
        int resImg = this->img + c2.img;
        return ComplexNumber(resReal, resImg);
    }

    ComplexNumber operator- (ComplexNumber& c2){
        int resReal = this->real - c2.real;
        int resImg = this->img - c2.img;
        return ComplexNumber(resReal, resImg);
    }
};

int main(){
    ComplexNumber c1(1,2);
    ComplexNumber c2(3,4);
    c1.show();
    c2.show();

    ComplexNumber c3 = c1 + c2;
    c3.show();

    ComplexNumber c4 = c2 - c1;
    c4.show();

    return 0;
}