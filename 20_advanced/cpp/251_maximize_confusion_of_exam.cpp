// LC#2024 — Maximize the Confusion of an Exam
// Difficulty: Medium | Pattern: Sliding Window | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int longest(const string& s, int k, char c) { int l = 0, cnt = 0, best = 0; for (int r = 0; r < (int)s.size(); r++) { cnt += s[r] != c; while (cnt > k) cnt -= s[l++] != c; best = max(best, r - l + 1); } return best; }
int maxConsecutiveAnswers(string s, int k) { return max(longest(s, k, 'T'), longest(s, k, 'F')); }
int main() { cout << maxConsecutiveAnswers("TTFTTFTT", 1) << endl; } // 5
