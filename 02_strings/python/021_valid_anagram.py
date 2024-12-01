# LC #242 — Valid Anagram
# Difficulty : Easy
# Pattern    : Frequency Count
# Time       : O(n)   Space: O(1) — 26-char alphabet

"""
Approach A (Counter): Counter(s) == Counter(t) — clean one-liner.
Approach B (array): 26-element frequency array, same O(n) time, O(1) space.
Both shown below.
"""

from collections import Counter


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        return Counter(s) == Counter(t)

    # Alternative — no Counter import needed
    def isAnagram_v2(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        freq = [0] * 26
        for c in s: freq[ord(c) - ord('a')] += 1
        for c in t:
            freq[ord(c) - ord('a')] -= 1
            if freq[ord(c) - ord('a')] < 0:
                return False
        return True


if __name__ == "__main__":
    sol = Solution()
    for fn in [sol.isAnagram, sol.isAnagram_v2]:
        assert fn("anagram", "nagaram") is True
        assert fn("rat", "car") is False
        assert fn("a", "a") is True
        assert fn("ab", "a") is False
        assert fn("", "") is True
    print("All tests passed!")
