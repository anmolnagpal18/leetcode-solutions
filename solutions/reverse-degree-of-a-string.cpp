/**
 * Problem: Reverse Degree of a String (Easy)
 * Language: C++
 *
 * Description:
 * Given a string `s`, calculate its **reverse degree**.
 * 
 * The **reverse degree** is calculated as follows:
 * 
 * 	1. $1
 * 
 * 	2. $1
 * 
 * Return the **reverse degree** of `s`.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** s = "abc"
 * 
 * **Output:** 148
 * 
 * **Explanation:**
 * 
 * 	
 * 		
 * 			Letter
 * 			Index in Reversed Alphabet
 * 			Index in String
 * 			Product
 * 		
 * 		
 * 			`'a'`
 * 			26
 * 			1
 * 			26
 * 		
 * 		
 * 			`'b'`
 * 			25
 * 			2
 * 			50
 * 		
 * 		
 * 			`'c'`
 * 			24
 * 			3
 * 			72
 * 		
 * 	
 * 
 * The reversed degree is `26 + 50 + 72 = 148`.
 * 
 * **Example 2:**
 * 
 * **Input:** s = "zaza"
 * 
 * **Output:** 160
 * 
 * **Explanation:**
 * 
 * 	
 * 		
 * 			Letter
 * 			Index in Reversed Alphabet
 * 			Index in String
 * 			Product
 * 		
 * 		
 * 			`'z'`
 * 			1
 * 			1
 * 			1
 * 		
 * 		
 * 			`'a'`
 * 			26
 * 			2
 * 			52
 * 		
 * 		
 * 			`'z'`
 * 			1
 * 			3
 * 			3
 * 		
 * 		
 * 			`'a'`
 * 			26
 * 			4
 * 			104
 * 		
 * 	
 * 
 * The reverse degree is `1 + 52 + 3 + 104 = 160`.
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 <= s.length <= 1000`
 * 
 * 	• `s` contains only lowercase English letters.
 */

class Solution {
public:
    int reverseDegree(string s) {
        long long degree = 0;                 // use 64‑bit to avoid overflow for long strings
        for (int i = 0; i < (int)s.size(); ++i) {
            int revIdx = 26 - (s[i] - 'a');    // index in reversed alphabet (1 … 26)
            degree += 1LL * revIdx * (i + 1); // position is 1‑based
        }
        return (int)degree;                   // result fits in 32‑bit for given constraints
    }
};
