/*
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be
truncated to 8, and -2.7335 would be truncated to -2.
Return the quotient after dividing dividend by divisor.


Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer 
range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, 
and if the quotient is strictly less than -231, then return -231.

 
Example 1:
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.

Example 2:
Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
 

Constraints:
-> -231 <= dividend, divisor <= 231 - 1
-> divisor != 0
*/

#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle edge cases
        if(dividend == 0)   return 0;
        if(divisor == 0)    return INT_MAX; // Divisor is zero is undefined, returning max int

        // Determine the sign of the result
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert to positive values
        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);

        long long result = 0;

        // Bit manipulation to find the quotient
        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor, multiple = 1;
            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }
            absDividend -= tempDivisor;
            result += multiple;
        }

        // Apply the sign to the result
        if (isNegative) result = -result;

        // Ensure the result is within the 32-bit signed integer range
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;

        return (int)result;
    }
};