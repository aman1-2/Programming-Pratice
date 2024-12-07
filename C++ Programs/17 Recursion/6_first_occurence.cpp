/*
WAP to create a function which resurcively find the first occurence of the element in the vector.
*/

#include<iostream>
#include<vector>
using namespace std;

int checkFirstOccurence(vector<int> vec, int target, int i){
    if(i == vec.size()){ //Base-case
        return -1;
    }

    if(vec[i] == target)    return i; //self-work

    return checkFirstOccurence(vec, target, i+1); //Assumption
}

int main(){
    vector<int> vec = {1,2,3,3,3,4};
    cout<<checkFirstOccurence(vec, 30, 0);
    return 0;
}