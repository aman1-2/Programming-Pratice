/*WAP where user can keep entering numbers till they enter the multiple of 10?*/
#include<iostream>
using namespace std;
int main(){
    // while(true){
    //     int num;
    //     cin>>num;

    //     if(num % 10 == 0){
    //         break;
    //     }
    // }

    //Alternative method
    int num;
    do{
        cin>>num;
        if(num % 10 == 0){
            break;
        }
    } while(true);

    return 0;
}