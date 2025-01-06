// LC#27 — Remove Element
// Difficulty: Easy | Pattern: Two Pointers | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int removeElement(vector<int>& a, int v) {
    int k = 0;
    for (int x : a) if (x != v) a[k++] = x;
    return k;
}
int main() { vector<int> a = {3,2,2,3}; cout << removeElement(a, 3) << endl; } // 2
