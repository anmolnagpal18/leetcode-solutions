/**
 * Problem: Brace Expansion II (Hard)
 * Language: C++
 *
 * Description:
 * Under the grammar given below, strings can represent a set of lowercase words. Let `R(expr)` denote the set of words the expression represents.
 * 
 * The grammar can best be understood through simple examples:
 * 
 * 	• Single letters represent a singleton set containing that word.
 * 	
 * 		`R("a") = {"a"}`
 * 
 * 		• `R("w") = {"w"}`
 * 
 * 	
 * 	
 * 	When we take a comma-delimited list of two or more expressions, we take the union of possibilities.
 * 	
 * 		• `R("{a,b,c}") = {"a","b","c"}`
 * 
 * 		• `R("{{a,b},{b,c}}") = {"a","b","c"}` (notice the final set only contains each word at most once)
 * 
 * 	
 * 	
 * 	When we concatenate two expressions, we take the set of possible concatenations between two words where the first word comes from the first expression and the second word comes from the second expression.
 * 	
 * 		• `R("{a,b}{c,d}") = {"ac","ad","bc","bd"}`
 * 
 * 		• `R("a{b,c}{d,e}f{g,h}") = {"abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"}`
 * 
 * 	
 * 	
 * 
 * Formally, the three rules for our grammar:
 * 
 * 	• For every lowercase letter `x`, we have `R(x) = {x}`.
 * 
 * 	• For expressions `e1, e2, ... , ek` with `k >= 2`, we have `R({e1, e2, ...}) = R(e1) &cup; R(e2) &cup; ...`
 * 
 * 	• For expressions `e1` and `e2`, we have `R(e1 + e2) = {a + b for (a, b) in R(e1) &times; R(e2)}`, where `+` denotes concatenation, and `&times;` denotes the cartesian product.
 * 
 * Given an expression representing a set of words under the given grammar, return *the sorted list of words that the expression represents*.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** expression = "{a,b}{c,{d,e}}"
 * **Output:** ["ac","ad","ae","bc","bd","be"]
 * 
 * **Example 2:**
 * 
 * **Input:** expression = "{{a,z},a{b,c},{ab,z}}"
 * **Output:** ["a","ab","ac","z"]
 * **Explanation:** Each distinct word is written only once in the final answer.
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 <= expression.length <= 60`
 * 
 * 	• `expression[i]` consists of `'{'`, `'}'`, `','`or lowercase English letters.
 * 
 * 	• The given `expression` represents a set of words based on the grammar given in the description.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        expr = move(expression);
        pos = 0;
        n = static_cast<int>(expr.size());
        set<string> result = parseExpression();   // already sorted & unique
        return vector<string>(result.begin(), result.end());
    }

private:
    string expr;
    int pos = 0;          // current index while parsing
    int n = 0;            // length of expr

    // Expression = Term (',' Term)*
    set<string> parseExpression() {
        set<string> res = parseTerm();
        while (pos < n && expr[pos] == ',') {
            ++pos;                         // consume ','
            set<string> term = parseTerm();
            res.insert(term.begin(), term.end()); // union
        }
        return res;
    }

    // Term = Factor*
    set<string> parseTerm() {
        set<string> cur;
        cur.insert("");                     // identity for concatenation
        while (pos < n && expr[pos] != ',' && expr[pos] != '}') {
            set<string> factor = parseFactor();
            set<string> nxt;
            for (const string& a : cur) {
                for (const string& b : factor) {
                    nxt.insert(a + b);
                }
            }
            cur.swap(nxt);
        }
        return cur;
    }

    // Factor = letter | '{' Expression '}'
    set<string> parseFactor() {
        if (expr[pos] == '{') {
            ++pos;                         // consume '{'
            set<string> inner = parseExpression();
            ++pos;                         // consume '}'
            return inner;
        } else {                           // a single lowercase letter
            string s(1, expr[pos]);
            ++pos;
            return {s};
        }
    }
};
