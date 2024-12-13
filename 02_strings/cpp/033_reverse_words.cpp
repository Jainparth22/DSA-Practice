// LC#151 — Reverse Words in a String
// Difficulty: Medium | Pattern: Split / Two Pointers | Time: O(n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s) {
    stringstream ss(s); string w; vector<string> v;
    while (ss >> w) v.push_back(w);
    reverse(v.begin(), v.end());
    string out;
    for (size_t i = 0; i < v.size(); i++) out += (i ? " " : "") + v[i];
    return out;
}
int main() { cout << reverseWords("  the sky  is blue ") << endl; } // blue is sky the
