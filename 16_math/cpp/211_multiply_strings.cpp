// LC#43 — Multiply Strings
// Difficulty: Medium | Pattern: Grade-school multiplication | Time: O(mn) | Space: O(m+n)
#include <bits/stdc++.h>
using namespace std;
string multiply(string a, string b) {
    if (a == "0" || b == "0") return "0";
    vector<int> r(a.size() + b.size());
    for (int i = a.size() - 1; i >= 0; i--) for (int j = b.size() - 1; j >= 0; j--) {
        int s = (a[i] - '0') * (b[j] - '0') + r[i + j + 1];
        r[i + j + 1] = s % 10; r[i + j] += s / 10;
    }
    string out; for (int d : r) if (!(out.empty() && d == 0)) out += '0' + d;
    return out;
}
int main() { cout << multiply("123", "456") << endl; } // 56088
