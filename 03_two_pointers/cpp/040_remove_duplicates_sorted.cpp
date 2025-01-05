// LC#26 — Remove Duplicates from Sorted Array
// Difficulty: Easy | Pattern: Two Pointers | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>& a) {
    int k = 0;
    for (int x : a) if (!k || x != a[k-1]) a[k++] = x;
    return k;
}
int main() { vector<int> a = {0,0,1,1,1,2,2,3,3,4}; cout << removeDuplicates(a) << endl; } // 5
