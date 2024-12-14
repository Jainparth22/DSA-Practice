// LC#8 — String to Integer (atoi)
// Difficulty: Medium | Pattern: Parsing | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int myAtoi(string s) {
    int i = 0, n = s.size(), sign = 1; long long r = 0;
    while (i < n && s[i] == ' ') i++;
    if (i < n && (s[i] == '+' || s[i] == '-')) sign = s[i++] == '-' ? -1 : 1;
    while (i < n && isdigit(s[i])) {
        r = r * 10 + (s[i++] - '0');
        if (sign * r > INT_MAX) return INT_MAX;
        if (sign * r < INT_MIN) return INT_MIN;
    }
    return (int)(sign * r);
}
int main() { cout << myAtoi("   -42abc") << endl; } // -42
