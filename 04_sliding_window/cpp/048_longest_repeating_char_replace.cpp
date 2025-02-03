// LC#424 — Longest Repeating Character Replacement
// Difficulty: Medium
// Pattern: Sliding Window
// Time: O(n) | Space: O(26) = O(1)
//
// Approach:
//   Sliding window [left, right]. Track frequency of each char in window.
//   Keep track of maxCount = frequency of the most common char in window.
//   Window size - maxCount = chars that need replacing.
//   If this exceeds k → shrink from left.
//   Answer = max window size seen.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};
        int left = 0, maxCount = 0, result = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            count[s[right] - 'A']++;
            maxCount = max(maxCount, count[s[right] - 'A']);
            // window size - maxCount > k means too many replacements needed
            if ((right - left + 1) - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};

int main() {
    Solution sol;
    cout << sol.characterReplacement("ABAB", 2)  << endl; // 4
    cout << sol.characterReplacement("AABABBA", 1) << endl; // 4
    cout << sol.characterReplacement("AAAA", 2)  << endl; // 4 (already all same)
    cout << sol.characterReplacement("ABCD", 0)  << endl; // 1
    cout << "All tests passed!" << endl;
    return 0;
}
