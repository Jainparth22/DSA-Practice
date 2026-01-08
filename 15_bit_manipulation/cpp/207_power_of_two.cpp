// LC#231 — Power of Two
// Difficulty: Easy | Pattern: n & (n-1) | Time: O(1) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int n) { return n > 0 && !(n & (n - 1)); }
int main() { cout << isPowerOfTwo(16) << isPowerOfTwo(3) << isPowerOfTwo(0) << endl; } // 100
