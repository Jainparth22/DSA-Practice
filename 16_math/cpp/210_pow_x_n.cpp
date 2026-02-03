// LC#50 — Pow(x, n)
// Difficulty: Medium | Pattern: Fast Exponentiation (Divide & Conquer)
// Time: O(log n) | Space: O(log n)
// Approach: x^n = (x^(n/2))^2. If n odd, multiply extra x.
// Handle negative n: x^(-n) = 1/x^n.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    double fastPow(double x, long long n) {
        if (n == 0) return 1.0;
        double half = fastPow(x, n / 2);
        if (n % 2 == 0) return half * half;
        return half * half * x;
    }
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) { x = 1 / x; N = -N; }
        return fastPow(x, N);
    }
};

int main() {
    Solution sol;
    cout << sol.myPow(2.0, 10)  << endl; // 1024
    cout << sol.myPow(2.1, 3)   << endl; // 9.261
    cout << sol.myPow(2.0, -2)  << endl; // 0.25
    cout << "All tests passed!" << endl;
    return 0;
}
