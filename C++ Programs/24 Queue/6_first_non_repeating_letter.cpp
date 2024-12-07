#include<iostream>
#include<queue>
using namespace std;

string firstNonRepeatingElement(string str) {
    if(str == "")   return "";

    string res = "";
    int arr[26] = {0};
    queue<char> qu;

    for(int i=0; i<str.length(); i++) { //O(n)
        char ch = str[i];
        arr[ch - 'a']++;
        qu.push(ch);

        while(arr[qu.front() - 'a'] > 1 && !qu.empty()){
            qu.pop();
        }

        if(qu.empty())  res += "-1 ";
        else res = res + qu.front() + ' ';
    }

    return res;
}

int main() {
    string str = "aabccxb";

    cout<<firstNonRepeatingElement(str);

    return 0;
}