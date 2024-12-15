// LC#38 — Count and Say
// Difficulty: Medium | Pattern: Simulation | Time: O(2^n) | Space: O(2^n)
#include <bits/stdc++.h>
using namespace std;
string countAndSay(int n) {
    string s = "1";
    while (--n) {
        string t;
        for (size_t i = 0; i < s.size();) {
            size_t j = i; while (j < s.size() && s[j] == s[i]) j++;
            t += to_string(j - i) + s[i]; i = j;
        }
        s = t;
    }
    return s;
}
int main() { cout << countAndSay(4) << endl; } // 1211
