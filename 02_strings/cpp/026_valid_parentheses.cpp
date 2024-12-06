/*
 * LC #20 — Valid Parentheses
 * Difficulty : Easy
 * Pattern    : Stack
 * Time       : O(n)
 * Space      : O(n)
 *
 * Approach:
 *   Push opening brackets onto the stack.
 *   On closing bracket, check top of stack matches — if not, invalid.
 *   At the end, stack must be empty.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> match = {{')', '('}, {']', '['}, {'}', '{'}};

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty() || st.top() != match[c]) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;
    cout << boolalpha;
    cout << sol.isValid("()")       << "\n"; // true
    cout << sol.isValid("()[]{}")   << "\n"; // true
    cout << sol.isValid("(]")       << "\n"; // false
    cout << sol.isValid("([)]")     << "\n"; // false
    cout << sol.isValid("{[]}")     << "\n"; // true
    cout << sol.isValid("]")        << "\n"; // false
    return 0;
}
