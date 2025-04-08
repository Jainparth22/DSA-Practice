// LC#287 — Find the Duplicate Number
// Difficulty: Medium | Pattern: Floyd Cycle Detection | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int>& a) {
    int s = a[0], f = a[0];
    do { s = a[s]; f = a[a[f]]; } while (s != f);
    s = a[0];
    while (s != f) { s = a[s]; f = a[f]; }
    return s;
}
int main() { vector<int> a = {1,3,4,2,2}; cout << findDuplicate(a) << endl; } // 2
