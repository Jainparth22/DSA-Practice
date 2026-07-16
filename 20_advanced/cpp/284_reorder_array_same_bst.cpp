// LC#1569 — Number of Ways to Reorder Array with Same BST
// Difficulty: Hard | Pattern: Combinatorics + recursion | Time: O(n^2) | Space: O(n^2)
#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7; vector<vector<long long>> C;
long long f(vector<int> a) {
    if (a.size() <= 2) return 1; vector<int> l, r;
    for (size_t i = 1; i < a.size(); i++) (a[i] < a[0] ? l : r).push_back(a[i]);
    return C[a.size() - 1][l.size()] * f(l) % M * f(r) % M;
}
int numOfWays(vector<int>& a) {
    int n = a.size(); C.assign(n + 1, vector<long long>(n + 1)); for (int i = 0; i <= n; i++) { C[i][0] = 1; for (int j = 1; j <= i; j++) C[i][j] = (C[i-1][j-1] + (j <= i - 1 ? C[i-1][j] : 0)) % M; }
    return (f(a) - 1 + M) % M;
}
int main() { vector<int> a = {3,4,5,1,2}, b = {1,2,3}; cout << numOfWays(a) << numOfWays(b) << endl; } // 50
