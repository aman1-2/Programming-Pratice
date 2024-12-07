#include<iostream>
#include<string>
using namespace std;

//we can too do this by sorting the alphabets of the two strings - it will have time complexity of O(n*log n)
bool isAnagram(string s1, string s2){ //Time-complexity - O(n)
    //Comparing both the string size.
    if(s1.length() != s2.length())  return false;

    int arr[26] = {0};
    //stroing count
    for(int i=0; i<s1.length(); i++){
        arr[s1[i] - 'a']++;
    }
    //checking right count
    for(int i=0; i<s2.length(); i++){
        if(arr[s2[i] - 'a'] == 0)   return false;
        arr[s2[i] - 'a']--;
    }
    //checking for any extra unused letter
    for(int i=0; i<26; i++){
        if(arr[i]>0)    return false;
    }

    return true;
}

int main(){
    string s1,s2;
    s1 = "rat";
    s2 = "car";

    cout<<isAnagram(s1, s2);

    return 0;
}