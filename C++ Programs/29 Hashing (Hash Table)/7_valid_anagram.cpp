/**
 * Here we need to see if the two true is are valid anagram or not. 
 * For checking if two strings are valid anagram or not we need to test few condition -
 * (i) The length of both the strings must be same.
 * (ii) Character in both the strings must be same. Both the string might have different arrangement of those strings but the characters must be same.
 * (iii) Frequency count of characters in both the strings too must be same.
 */

#include<iostream>
#include<unordered_map>
using namespace std;

bool isAnagram(string str1, string str2) {
    //Checking the case where the size of the strings are different in that case direct return false from without making much comparison.
    if(str1.size() != str2.size())  return false;
    //STEP 1: Creating an unordered map to store the frequency of characters.
    unordered_map<char, int> um;

    //STEP 2: Storing the each characters count in the map for string1 one by one.
    for(int i=0; i<str1.size(); i++) {
        um[str1[i]]++;
    }

    //STEP 3: Now matching the characters of the string2 with the characters present in the map if the character is present then decrease its count otherwise return a false for a character which isn't present in the map. 
    for(int i=0; i<str2.size(); i++) {
        if(!um.count(str2[i]))  return false;
        else    um[str2[i]]--;

        //If the frequency of any element goes zero then erasing that element completely from the map.
        if(um[str2[i]] == 0)    um.erase(str2[i]);
    }

    //If the map is empty that means all the elements have been matched and the strings are anagram.
    return (um.size() == 0);
}

int main() {
    string str1 = "race", str2 = "care", str3 = "tulip", str4 = "lipid", str5 = "aman", str6 = "king";
    cout<<isAnagram(str1, str2)<<endl;
    cout<<isAnagram(str3, str4)<<endl;
    cout<<isAnagram(str5, str6)<<endl;

    return 0;
}