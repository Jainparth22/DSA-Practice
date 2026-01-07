// LC#7 — Reverse Integer
// Difficulty: Medium | Pattern: Math with overflow check | Time: O(log n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int reverse(int x) {
    int r = 0;
    while (x) {
        int d = x % 10; x /= 10;
        if (r > INT_MAX / 10 || (r == INT_MAX / 10 && d > 7)) return 0;
        if (r < INT_MIN / 10 || (r == INT_MIN / 10 && d < -8)) return 0;
        r = r * 10 + d;
    }
    return r;
}
int main() { cout << reverse(123) << reverse(-120) << reverse(1534236469) << endl; } // 321-210
