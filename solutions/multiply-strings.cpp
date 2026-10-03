/**
 * Problem: Multiply Strings (Medium)
 * Language: C++
 *
 * Description:
 * Given two non-negative integers `num1` and `num2` represented as strings, return the product of `num1` and `num2`, also represented as a string.
 * 
 * **Note:** You must not use any built-in BigInteger library or convert the inputs to integer directly.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** num1 = "2", num2 = "3"
 * **Output:** "6"
 * 
 * **Example 2:**
 * 
 * **Input:** num1 = "123", num2 = "456"
 * **Output:** "56088"
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 <= num1.length, num2.length <= 200`
 * 
 * 	• `num1` and `num2` consist of digits only.
 * 
 * 	• Both `num1` and `num2` do not contain any leading zero, except the number `0` itself.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        // Quick return for zero
        if (num1 == "0" || num2 == "0") return "0";

        int m = num1.size();
        int n = num2.size();
        vector<int> res(m + n, 0);          // holds the intermediate digits

        // Multiply each digit of num1 with each digit of num2
        for (int i = m - 1; i >= 0; --i) {
            int d1 = num1[i] - '0';
            for (int j = n - 1; j >= 0; --j) {
                int d2 = num2[j] - '0';
                int mul = d1 * d2;
                int sum = mul + res[i + j + 1];   // add existing value at this position

                res[i + j + 1] = sum % 10;        // keep the unit digit
                res[i + j] += sum / 10;           // propagate the carry to the left
            }
        }

        // Convert vector to string, skipping leading zeros
        string result;
        int i = 0;
        while (i < (int)res.size() && res[i] == 0) ++i; // skip leading zeros
        for (; i < (int)res.size(); ++i)
            result.push_back(res[i] + '0');

        return result.empty() ? "0" : result;
    }
};
