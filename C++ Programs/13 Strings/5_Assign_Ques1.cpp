/*
Question 1 : Count how many times lowercase vowels occurred in a String entered 
by the user.
*/

#include<iostream>
using namespace std;
int countLowerVowels(string s){
    int count = 0;
    for(char ch:s){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')   count++;
    }

    return count;
}
int main(){
    string s = "AaEeIiOoUu";
    cout<<countLowerVowels(s);
    
    return 0;
}