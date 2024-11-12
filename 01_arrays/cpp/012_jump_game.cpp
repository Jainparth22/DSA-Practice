// LC#55 — Jump Game
// Difficulty: Medium | Pattern: Greedy | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
bool canJump(vector<int>& a) {
    int far = 0;
    for (int i = 0; i < (int)a.size(); i++) { if (i > far) return false; far = max(far, i + a[i]); }
    return true;
}
int main() { vector<int> a = {2,3,1,1,4}, b = {3,2,1,0,4}; cout << canJump(a) << canJump(b) << endl; } // 10
