// LC#1411 — Number of Ways to Paint N x 3 Grid
// Difficulty: Hard | Pattern: DP on row patterns (ABA / ABC) | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int numOfWays(int n) {
    const int M = 1e9 + 7; long long aba = 6, abc = 6;
    for (int i = 1; i < n; i++) { long long na = (3 * aba + 2 * abc) % M, nb = (2 * aba + 2 * abc) % M; aba = na; abc = nb; }
    return (aba + abc) % M;
}
int main() { cout << numOfWays(1) << " " << numOfWays(5000) << endl; } // 12 30228214
