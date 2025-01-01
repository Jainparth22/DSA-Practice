# LC #125 — Valid Palindrome
# Difficulty : Easy
# Pattern    : Two Pointers
# Time       : O(n)   Space: O(1)

"""
Two pointers moving inward, skipping non-alphanumeric characters.
Compare after converting to lowercase.
"""


class Solution:
    def isPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1
        while l < r:
            while l < r and not s[l].isalnum():
                l += 1
            while l < r and not s[r].isalnum():
                r -= 1
            if s[l].lower() != s[r].lower():
                return False
            l += 1
            r -= 1
        return True


if __name__ == "__main__":
    sol = Solution()
    assert sol.isPalindrome("A man, a plan, a canal: Panama") is True
    assert sol.isPalindrome("race a car") is False
    assert sol.isPalindrome(" ") is True
    assert sol.isPalindrome("0P") is False
    assert sol.isPalindrome("") is True
    assert sol.isPalindrome("a") is True
    print("All tests passed!")
