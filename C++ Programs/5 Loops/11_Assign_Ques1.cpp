/*Question 1 : WAP to find the Factorial of a number entered by the user.*/
#include<iostream>
using namespace std;
int main(){
    int num, fact=1;
    cout<<"num = ";
    cin>>num;

    for(int i=1; i<=num; i++){
        fact *= i;
    }

    cout<<"Factorial is "<<fact<<endl;

    return 0;
}