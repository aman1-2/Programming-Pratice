#include<iostream>
using namespace std;
class Print{
public:
    void show(int num){
        cout<<"Integer: "<<num<<endl;
        return;
    }

    void show(string str){
        cout<<"String: "<<str<<endl;
        return;
    }
};

int main(){
    Print obj1;
    obj1.show(12);
    obj1.show("Aman");

    return 0;
}