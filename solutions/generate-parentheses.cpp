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
        vector<string> ans;
        backtrack(ans, "", 0, 0, n);
        return ans;
    }

private:
    void backtrack(vector<string>& ans, const string& cur,
                   int open, int close, int maxPairs) {
        if (cur.size() == 2 * maxPairs) {
            ans.push_back(cur);
            return;
        }
        if (open < maxPairs) {
            backtrack(ans, cur + '(', open + 1, close, maxPairs);
        }
        if (close < open) {
            backtrack(ans, cur + ')', open, close + 1, maxPairs);
        }
    }
};
