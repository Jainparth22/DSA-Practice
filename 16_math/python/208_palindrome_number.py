# LC#9 — Palindrome Number
# Difficulty: Easy | Pattern: Math
# Time: O(log n) | Space: O(1)
# Approach: Reverse second half of number, compare to first half.

class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x % 10 == 0 and x != 0):
            return False
        reversed_half = 0
        while x > reversed_half:
            reversed_half = reversed_half * 10 + x % 10
            x //= 10
        return x == reversed_half or x == reversed_half // 10

if __name__ == "__main__":
    s = Solution()
    assert s.isPalindrome(121) == True
    assert s.isPalindrome(-121) == False
    assert s.isPalindrome(10) == False
    assert s.isPalindrome(0) == True
    assert s.isPalindrome(1221) == True
    print("All tests passed!")
