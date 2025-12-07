// LC#763 — Partition Labels
// Difficulty: Medium | Pattern: Greedy last occurrence | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
vector<int> partitionLabels(string s) {
    int last[26]; for (int i = 0; i < (int)s.size(); i++) last[s[i] - 'a'] = i;
    vector<int> res; int start = 0, end = 0;
    for (int i = 0; i < (int)s.size(); i++) { end = max(end, last[s[i] - 'a']); if (i == end) { res.push_back(end - start + 1); start = i + 1; } }
    return res;
}
int main() { for (int x : partitionLabels("ababcbacadefegdehijhklij")) cout << x << " "; } // 9 7 8
