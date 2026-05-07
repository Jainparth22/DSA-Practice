// LC#1065 — Index Pairs of a String
// Difficulty: Easy | Pattern: Trie scan | Time: O(n * L) | Space: O(total chars)
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> indexPairs(string text, vector<string>& words) {
    unordered_set<string> d(words.begin(), words.end()); vector<vector<int>> res;
    for (int i = 0; i < (int)text.size(); i++) for (int j = i; j < (int)text.size(); j++) if (d.count(text.substr(i, j - i + 1))) res.push_back({i, j});
    return res;
}
int main() { vector<string> w = {"story","fleet","leetcode"}; cout << indexPairs("thestoryofleetcodeandme", w).size() << endl; } // 2
