// LC#371 — Sum of Two Integers
// Difficulty: Medium | Pattern: XOR + carry | Time: O(1) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int getSum(int a, int b) { while (b) { unsigned c = (unsigned)(a & b) << 1; a ^= b; b = c; } return a; }
int main() { cout << getSum(1, 2) << getSum(-2, 3) << endl; } // 31
