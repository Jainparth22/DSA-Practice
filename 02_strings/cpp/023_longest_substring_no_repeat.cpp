/*
 * LC #3 — Longest Substring Without Repeating Characters
 * Difficulty : Medium
 * Pattern    : Sliding Window (variable size)
 * Time       : O(n)
 * Space      : O(min(m, n)) where m = charset size
 *
 * Approach:
 *   Maintain a window [left, right] with no duplicate characters.
 *   Use an unordered_map to track the LAST SEEN INDEX of each character.
 *   When s[right] was seen inside the current window, jump left past it.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen; // char -> last seen index
        int maxLen = 0;
        int left = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            char c = s[right];
            if (lastSeen.count(c) && lastSeen[c] >= left) {
                // character seen inside window — shrink left past it
                left = lastSeen[c] + 1;
            }
            lastSeen[c] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("abcabcbb") << "\n"; // 3 "abc"
    cout << sol.lengthOfLongestSubstring("bbbbb")    << "\n"; // 1 "b"
    cout << sol.lengthOfLongestSubstring("pwwkew")   << "\n"; // 3 "wke"
    cout << sol.lengthOfLongestSubstring("")          << "\n"; // 0
    cout << sol.lengthOfLongestSubstring("au")        << "\n"; // 2
    return 0;
}
