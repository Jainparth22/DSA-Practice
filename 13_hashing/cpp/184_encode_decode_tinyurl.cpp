// LC#535 — Encode and Decode TinyURL
// Difficulty: Medium | Pattern: Hash Map + counter | Time: O(1) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
    unordered_map<string, string> m; int id = 0; const string base = "http://tinyurl.com/";
public:
    string encode(string url) { string key = to_string(id++); m[key] = url; return base + key; }
    string decode(string s) { return m[s.substr(base.size())]; }
};
int main() { Solution s; cout << s.decode(s.encode("https://leetcode.com/problems/design-tinyurl")) << endl; } // https://leetcode.com/problems/design-tinyurl
