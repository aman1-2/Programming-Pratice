#include<iostream>
using namespace std;

class A{
    string sceret = "Secret Data";
    friend class B;
    friend void revealSecret(A &obj);
};

class B{
public:
    void showSecret(A &obj){
        cout<<obj.sceret<<endl;
        return;
    }
};

void revealSecret(A &obj){
    cout<<obj.sceret<<endl;
    return;
}

int main(){
    A a;
    B b;
    b.showSecret(a);
    revealSecret(a);

    return 0;
}