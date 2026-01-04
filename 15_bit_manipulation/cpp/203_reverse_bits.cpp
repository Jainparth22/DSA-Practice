// LC#190 — Reverse Bits
// Difficulty: Easy | Pattern: Bit shifting | Time: O(32) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
uint32_t reverseBits(uint32_t n) { uint32_t r = 0; for (int i = 0; i < 32; i++) { r = (r << 1) | (n & 1); n >>= 1; } return r; }
int main() { cout << reverseBits(43261596) << endl; } // 964176192
