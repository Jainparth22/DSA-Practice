// LC#45 — Jump Game II
// Difficulty: Medium | Pattern: Greedy / BFS | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int jump(vector<int>& a) {
    int jumps = 0, end = 0, far = 0;
    for (int i = 0; i + 1 < (int)a.size(); i++) {
        far = max(far, i + a[i]);
        if (i == end) { jumps++; end = far; }
    }
    return jumps;
}
int main() { vector<int> a = {2,3,1,1,4}; cout << jump(a) << endl; } // 2
