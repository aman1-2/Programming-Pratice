/*
Remove the duplicate character from the string.
*/

#include<iostream>
#include<vector>
using namespace std;

string modifiedString(string str, string ans,int idx, vector<bool> v){
    if(idx == str.length()) return ans;
    if(!v[str[idx] - 'a']){
        ans+=str[idx]; 
        v[str[idx] - 'a'] = true;
    }
    return modifiedString(str, ans, idx+1, v);
}

int main(){
    vector<bool> v(26, false);
    cout<<modifiedString("amaannnprattaprsiinghs", "", 0, v);
    return 0;
}