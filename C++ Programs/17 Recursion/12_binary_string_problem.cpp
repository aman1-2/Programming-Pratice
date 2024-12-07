/*
Binary String Problem -> Print all Binary Strings of size N without any consecutive 1's.
*/

#include<iostream>
using namespace std;

void binaryStrings(int num, int lastPlace, string ans){
    if(num == 0){
        cout<<ans<<"\n";
        return;
    }

    if(lastPlace != 1){
        binaryStrings(num-1, 0, ans + '0');
        binaryStrings(num-1, 1, ans + '1');
    } else{
        binaryStrings(num-1, 0, ans + '0');
    }
}

void binaryString(int num, string ans){
    if(num == 0){
        cout<<ans<<"\n";
        return;
    }

    if(ans[ans.size()-1] != '1'){
        binaryString(num-1, ans + '0');
        binaryString(num-1, ans + '1');
    } else{
        binaryString(num-1, ans + '0');
    }
}

int main(){
    binaryString(3, "");
    return 0;
}