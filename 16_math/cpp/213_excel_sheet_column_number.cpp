// LC#171 — Excel Sheet Column Number
// Difficulty: Easy | Pattern: Base-26 | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int titleToNumber(string s) { int r = 0; for (char c : s) r = r * 26 + (c - 'A' + 1); return r; }
int main() { cout << titleToNumber("A") << titleToNumber("AB") << titleToNumber("ZY") << endl; } // 128701
