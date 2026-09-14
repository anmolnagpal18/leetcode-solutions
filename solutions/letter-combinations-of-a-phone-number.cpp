/**
 * Problem: Letter Combinations of a Phone Number (Medium)
 * Language: C++
 *
 * Description:
 * Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. Return the answer in **any order**.
 * 
 * A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** digits = "23"
 * **Output:** ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * **Example 2:**
 * 
 * **Input:** digits = "2"
 * **Output:** ["a","b","c"]
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 <= digits.length <= 4`
 * 
 * 	• `digits[i]` is a digit in the range `['2', '9']`.
 */

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        
        // Mapping of digits to letters
        vector<string> phoneMap = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        
        string current;
        
        // Helper function for backtracking
        function<void(int)> backtrack = [&](int index) {
            // Base case: if we've processed all digits
            if (index == digits.size()) {
                result.push_back(current);
                return;
            }
            
            // Get the letters corresponding to the current digit
            string letters = phoneMap[digits[index] - '0'];
            
            // Try each letter for the current digit
            for (char c : letters) {
                current.push_back(c);       // Choose
                backtrack(index + 1);       // Explore
                current.pop_back();         // Un-choose
            }
        };
        
        backtrack(0);
        return result;
    }
};
