/*
Question 5 : Write a function that accepts a character (ch) as parameters & returns 
the character that occurs after ch in the English alphabet.
Eg : input = ‘c’, return value = ‘d’
Note : for ch = ‘z’, return ‘a’.
*/
#include<iostream>
using namespace std;

char nextCharacter(char ch){
    if(ch == 'Z' || ch=='z')    return 'a';
    else return ++ch;
}
int main(){
    char ch;
    cout<<"ch = ";
    cin>>ch;

    cout<<nextCharacter(ch);

    return 0;
}