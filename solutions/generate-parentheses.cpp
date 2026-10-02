/**
 * Problem: Generate Parentheses (Medium)
 * Language: C++
 *
 * Description:
 * Given `n` pairs of parentheses, write a function to *generate all combinations of well-formed parentheses*.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** n = 3
 * **Output:** ["((()))","(()())","(())()","()(())","()()()"]
 * 
 * **Example 2:**
 * 
 * **Input:** n = 1
 * **Output:** ["()"]
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 <= n <= 8`
 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, n, 0, 0);
        return result;
    }

private:
    void backtrack(vector<string>& result, string& current, int n, int open, int close) {
        if (current.size() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        if (open < n) {
            current.push_back('(');
            backtrack(result, current, n, open + 1, close);
            current.pop_back();
        }
        
        if (close < open) {
            current.push_back(')');
            backtrack(result, current, n, open, close + 1);
            current.pop_back();
        }
    }
};
