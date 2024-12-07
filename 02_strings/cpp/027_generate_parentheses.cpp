// LC#22 — Generate Parentheses
// Difficulty: Medium | Pattern: Backtracking | Time: O(4^n/sqrt(n)) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
void go(int open, int close, int n, string& cur, vector<string>& out) {
    if ((int)cur.size() == 2 * n) { out.push_back(cur); return; }
    if (open < n) { cur += '('; go(open + 1, close, n, cur, out); cur.pop_back(); }
    if (close < open) { cur += ')'; go(open, close + 1, n, cur, out); cur.pop_back(); }
}
vector<string> generateParenthesis(int n) { vector<string> out; string cur; go(0, 0, n, cur, out); return out; }
int main() { cout << generateParenthesis(3).size() << endl; } // 5
