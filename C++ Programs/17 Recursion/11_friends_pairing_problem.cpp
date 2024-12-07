/*
Friends Pairing Problem -> Find total ways in which n friends can be paired up.
Each friend can only be paired once.
*/

#include<iostream>
using namespace std;

/*Here we have multiplied (num-1) with waysFriendsPair(num-2)

if we have three friends A B C
then A can pair with B as well as C so A has two choices of pairing itself which is (num-1)
and whom so ever he make a pair we will have to reduce it to num-2 only. because one pair means 2 people less in the group.*/

int waysFriendsPair(int num){
    return (num == 1 || num == 2)?(num):(waysFriendsPair(num-1) + (num-1)*waysFriendsPair(num-2));
}

int main(){
    cout<<waysFriendsPair(4);
    return 0;
}