// LC#1220 — Count Vowels Permutation
// Difficulty: Hard | Pattern: DP on last vowel | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int countVowelPermutation(int n) {
    const int M = 1e9 + 7; long long a = 1, e = 1, i = 1, o = 1, u = 1;
    for (int k = 1; k < n; k++) { long long na = (e + i + u) % M, ne = (a + i) % M, ni = (e + o) % M, no = i, nu = (i + o) % M; a = na; e = ne; i = ni; o = no; u = nu; }
    return (a + e + i + o + u) % M;
}
int main() { cout << countVowelPermutation(1) << " " << countVowelPermutation(5) << endl; } // 5 68
