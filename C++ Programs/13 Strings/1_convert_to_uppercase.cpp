#include<iostream>
using namespace std;

//Brute Force Approach going to each element and then converting it into Upper case if its a lower case element.
void convertUpperCase(char str[]){
    int idx = 0;
    while(str[idx] != '\0'){
        if(str[idx] >= 'A' && str[idx] <= 'Z'){
            idx++;
            continue;
        }
        else{
            //First look at what position that element exists in abcd.... series
            int position = str[idx] - 'a';
            //Now just add those many position to the 'A' and replace it at the original str.
            str[idx] = 'A' + position;
        }
        idx++;
    }

    return;
}

void convertLowerCase(char str[]){
    int idx=0;
    while(str[idx] != '\0'){
        if(str[idx] >= 'a' && str[idx] <= 'z'){
            idx++;
            continue;
        }
        else{
            str[idx] = 'a' + (str[idx] - 'A');
        }
        idx++;
    }

    return;
}

int main(){
    char str[] = "aPPLE";
    // convertUpperCase(str);
    convertLowerCase(str);
    cout<<str;

    return 0;
}