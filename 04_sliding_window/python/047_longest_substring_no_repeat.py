# LC #3 — Longest Substring Without Repeating Characters
# Difficulty : Medium
# Pattern    : Sliding Window (variable)
# Time       : O(n)   Space: O(min(m,n))

"""
Window [left, right] contains no duplicates.
last_seen[c] = most recent index where c was seen.
When s[right] is a duplicate inside the window, jump left past it.
"""


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last_seen: dict[str, int] = {}
        max_len = left = 0
        for right, c in enumerate(s):
            if c in last_seen and last_seen[c] >= left:
                left = last_seen[c] + 1
            last_seen[c] = right
            max_len = max(max_len, right - left + 1)
        return max_len


if __name__ == "__main__":
    sol = Solution()
    assert sol.lengthOfLongestSubstring("abcabcbb") == 3
    assert sol.lengthOfLongestSubstring("bbbbb")    == 1
    assert sol.lengthOfLongestSubstring("pwwkew")   == 3
    assert sol.lengthOfLongestSubstring("")          == 0
    assert sol.lengthOfLongestSubstring("au")        == 2
    assert sol.lengthOfLongestSubstring("dvdf")      == 3
    print("All tests passed!")
