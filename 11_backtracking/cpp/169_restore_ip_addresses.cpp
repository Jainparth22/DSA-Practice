// LC#93 — Restore IP Addresses
// Difficulty: Medium | Pattern: Backtracking | Time: O(3^4) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
void go(const string& s, int i, int parts, string cur, vector<string>& res) {
    if (parts == 4) { if (i == (int)s.size()) { cur.pop_back(); res.push_back(cur); } return; }
    for (int len = 1; len <= 3 && i + len <= (int)s.size(); len++) {
        string seg = s.substr(i, len);
        if ((seg.size() > 1 && seg[0] == '0') || stoi(seg) > 255) continue;
        go(s, i + len, parts + 1, cur + seg + ".", res);
    }
}
vector<string> restoreIpAddresses(string s) { vector<string> res; go(s, 0, 0, "", res); return res; }
int main() { cout << restoreIpAddresses("25525511135").size() << endl; } // 2
