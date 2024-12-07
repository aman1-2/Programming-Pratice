#include<iostream>
#include<string.h>
using namespace std;

void reverseString(char str[], int size){
    int st_ptr = 0;
    int en_ptr = size-1;

    while(st_ptr < en_ptr){
        swap(str[st_ptr], str[en_ptr]);
        st_ptr++,en_ptr--;
    }

    return;
}

int main(){
    char str[] = "Aditya";
    reverseString(str, strlen(str));

    cout<<str;

    return 0;
}