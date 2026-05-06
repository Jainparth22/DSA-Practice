// LC#720 — Longest Word in Dictionary
// Difficulty: Medium | Pattern: Sort + Set | Time: O(n log n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
string longestWord(vector<string>& w) {
    sort(w.begin(), w.end()); unordered_set<string> ok; string best;
    for (auto& s : w) if (s.size() == 1 || ok.count(s.substr(0, s.size() - 1))) { ok.insert(s); if (s.size() > best.size()) best = s; }
    return best;
}
int main() { vector<string> w = {"w","wo","wor","worl","world"}; cout << longestWord(w) << endl; } // world
