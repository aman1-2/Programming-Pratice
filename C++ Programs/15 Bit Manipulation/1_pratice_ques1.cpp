#include<iostream>
using namespace std;
int main(){
    cout<<~(4); // 00000100 -> 1's(11111011) -> [MSB -> is 1 therefore will be a negative number.]
    // Leaving MSB doing  1's complement of 1111011 => 0000100 -> Now adding 1 to it.
    // 0000100 + 1 = 0000101 => -5 is answer

    cout<<endl;

    cout<<(8>>1); // 8/2 = 4

    return 0;
}