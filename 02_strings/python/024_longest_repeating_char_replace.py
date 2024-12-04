# LC#424 — Longest Repeating Character Replacement
# Difficulty: Medium
# Pattern: Sliding Window
# Time: O(n) | Space: O(1)
#
# Approach:
#   Sliding window. Track max frequency char count in current window.
#   If (window_size - max_count) > k → too many replacements → shrink left.
#   Answer = largest valid window seen.

from collections import defaultdict


class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = defaultdict(int)
        left = 0
        max_count = 0
        result = 0
        for right in range(len(s)):
            count[s[right]] += 1
            max_count = max(max_count, count[s[right]])
            # chars to replace = window_size - max_count
            if (right - left + 1) - max_count > k:
                count[s[left]] -= 1
                left += 1
            result = max(result, right - left + 1)
        return result


if __name__ == "__main__":
    s = Solution()
    assert s.characterReplacement("ABAB", 2) == 4
    assert s.characterReplacement("AABABBA", 1) == 4
    assert s.characterReplacement("AAAA", 2) == 4
    assert s.characterReplacement("ABCD", 0) == 1
    print("All tests passed!")
