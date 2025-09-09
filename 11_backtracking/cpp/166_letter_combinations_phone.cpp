// LC#17 — Letter Combinations of Phone Number
// Difficulty: Medium | Pattern: Backtracking | Time: O(4^n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
vector<string> letterCombinations(string d) {
    if (d.empty()) return {};
    vector<string> m = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, res = {""};
    for (char c : d) { vector<string> nx; for (auto& p : res) for (char l : m[c - '0']) nx.push_back(p + l); res = nx; }
    return res;
}
int main() { cout << letterCombinations("23").size() << endl; } // 9
