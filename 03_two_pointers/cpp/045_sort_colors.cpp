// LC#75 — Sort Colors
// Difficulty: Medium | Pattern: Dutch National Flag | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
void sortColors(vector<int>& a) {
    int lo = 0, mid = 0, hi = a.size() - 1;
    while (mid <= hi) {
        if (a[mid] == 0) swap(a[lo++], a[mid++]);
        else if (a[mid] == 1) mid++;
        else swap(a[mid], a[hi--]);
    }
}
int main() { vector<int> a = {2,0,2,1,1,0}; sortColors(a); for (int x : a) cout << x << " "; } // 0 0 1 1 2 2
