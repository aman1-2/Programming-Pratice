/* LEETCODE PROBLEM -> 121
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future 
to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.*/

#include<iostream>
using namespace std;

int maxProfit(int prices[], int size){
    int profit = 0;
    int cheapest_price = prices[0];

    //Here we have considered each day as either the selling day of the stock or buying day of stock.
    for(int i=1; i<size; i++){
        if(cheapest_price > prices[i])   cheapest_price = prices[i]; //If the day's price is less than price cheap-price then its buying day.
        else    profit = max(profit, (prices[i] - cheapest_price)); //Otherwise if its not the buying day then we try to sell the stock on this 
        //day and finds if its maximum then we get new maximum value otherwise move forward. Profit is calculated by considering the current price as the selling price and the cheapest price as the cost price.
    }

    return profit;
}
int main(){

    int prices[] = {7,6,4,3,1};

    cout<<maxProfit(prices, 5); 
    return 0;
}

//Brute-Force Approach
/* int maxProfit(int arr[], int size){
    int bestBuy[100000]; Cann't have the best buy value more than 1 lac.
    bestBuy[0] = INT_MAX;
    for(int i=1; i<size; i++){
        bestBuy[i] = min(bestBuy[i-1] - prices[i-1]);
    }

    int maxProfit = 0;
    for(int i=0; i<size; i++){
        maxprofit = max(maxprofit, (prices[i] - bestBuy[i]));
    }

    return maxProfit;
}*/