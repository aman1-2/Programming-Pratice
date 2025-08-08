#include<iostream>
using namespace std;

int binaryToDecimal(string &binary) {
    int n = binary.size(); //Fetched the length of the binary string passed.
    int sum = 0; //Created a summation variable in which we try to store the binary sum.
    for(int i=n-1; i>=0; i--) { //Iterating the binary from the LSB towards the MSB or we can say from the ending towards starting.
        int currChar = (binary[i] - '0'); //Extracted the current character.
        sum += currChar * (1<<(n-i-1)); //Summing the product of power of 2 (that to with the help of left shift).
    }

    return sum; //At the end returing the result formed.
}

int main() {
    string str = "001101"; //13
    cout<<binaryToDecimal(str)<<endl;

    string str1 = "001011"; //11
    cout<<binaryToDecimal(str1)<<endl;

    string str2 = "00000111"; //07
    cout<<binaryToDecimal(str2)<<endl;
    return 0;
}