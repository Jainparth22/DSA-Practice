// LC#678 — Valid Parenthesis String
// Difficulty: Medium | Pattern: Greedy range of open count | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
bool checkValidString(string s) {
    int lo = 0, hi = 0;
    for (char c : s) {
        lo += c == '(' ? 1 : -1; hi += c == ')' ? -1 : 1;
        if (hi < 0) return false;
        lo = max(lo, 0);
    }
    return lo == 0;
}
int main() { cout << checkValidString("(*))") << checkValidString("(((**") << endl; } // 10
