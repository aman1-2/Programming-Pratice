/*WAP to sort the array of characters using insertion sort in descending order?
char ch[] = {'f', 'b', 'a', 'e', 'c', 'd'}

In this we just need to convert the charcter into its ASCII int value and comapre the values.*/

#include<iostream>
using namespace std;

void charSort(char ch[], int size){
    for(int i=1; i<size; i++){
        int curr_ele = ch[i] - 0; //Conversion from char to int.
        int prev_idx = i-1;

        while(prev_idx >= 0 && curr_ele > (ch[prev_idx] - 0)){
            swap(ch[prev_idx+1], ch[prev_idx]);
            prev_idx--;
        }
        ch[prev_idx+1] = char(curr_ele); //Conversion from int to char
    }

    return;
}

//This same will to work for sorting characters because the underline comaprison logic remain same i.e,
/*Even 1 > 2 -> false
       1 < 2 -> true
in same way
        a < b -> true
        a > b -> false
*/
void insertionSort(int nums[], int size){
    for(int i=1; i<size; i++){
        int curr_ele = nums[i];
        int previous_idx = i-1;
        //Backward loop for checking in the sorted position
        while(previous_idx >= 0 && nums[previous_idx]>curr_ele){
            swap(nums[previous_idx], nums[previous_idx+1]);
            previous_idx--;
        }
        nums[previous_idx+1] = curr_ele; //At the end loop will end one position before the correct position that's why previous_idx + 1 done.
    }

    //Time complexity of the Insertion sort is O(n^2) as we are running the loop only once.

    return;
}

void print(char ch[], int size){
    for(int i=0; i<size; i++) {
    cout<<ch[i]<<" ";
    }

    return;
}

int main(){
    char ch[] = {'f', 'b', 'a', 'e', 'c', 'd'};
    charSort(ch, 6);
    print(ch, 6);

    return 0;
}