// LC#271 — Encode and Decode Strings
// Difficulty: Medium | Pattern: Length Prefix | Time: O(n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
string encode(const vector<string>& v) { string s; for (auto& x : v) s += to_string(x.size()) + "#" + x; return s; }
vector<string> decode(const string& s) {
    vector<string> out; size_t i = 0;
    while (i < s.size()) {
        size_t j = s.find('#', i); int len = stoi(s.substr(i, j - i));
        out.push_back(s.substr(j + 1, len)); i = j + 1 + len;
    }
    return out;
}
int main() { auto d = decode(encode({"lint", "co#de", ""})); cout << d.size() << d[1] << endl; } // 3co#de
