/**
 * Problem: Remove Invalid Parentheses (Hard)
 * Language: C++
 *
 * Description:
 * Given a string `s` that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.
 * 
 * Return *a list of **unique strings** that are valid with the minimum number of removals*. You may return the answer in **any order**.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** s = "()())()"
 * **Output:** ["(())()","()()()"]
 * 
 * **Example 2:**
 * 
 * **Input:** s = "(a)())()"
 * **Output:** ["(a())()","(a)()()"]
 * 
 * **Example 3:**
 * 
 * **Input:** s = ")("
 * **Output:** [""]
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 <= s.length <= 25`
 * 
 * 	• `s` consists of lowercase English letters and parentheses `'('` and `')'`.
 * 
 * 	• There will be at most `20` parentheses in `s`.
 */

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_set<string> visited;
        queue<string> q;
        
        q.push(s);
        visited.insert(s);
        
        while (!q.empty()) {
            int size = q.size();
            bool foundValid = false;
            
            for (int i = 0; i < size; ++i) {
                string curr = q.front();
                q.pop();
                
                if (isValid(curr)) {
                    result.push_back(curr);
                    foundValid = true;
                }
                
                if (foundValid) {
                    continue;
                }
                
                for (int j = 0; j < curr.size(); ++j) {
                    // Skip consecutive duplicates to reduce redundant branches
                    if (j > 0 && curr[j] == curr[j-1]) {
                        continue;
                    }
                    
                    string next = curr.substr(0, j) + curr.substr(j + 1);
                    
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            
            if (foundValid) {
                break;
            }
        }
        
        return result;
    }
    
private:
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) {
                    return false;
                }
            }
        }
        return count == 0;
    }
};
