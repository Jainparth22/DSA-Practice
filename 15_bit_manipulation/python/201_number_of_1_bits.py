# LC#191 — Number of 1 Bits
# Difficulty: Easy | Pattern: Bit Manipulation
# Time: O(1) | Space: O(1)

class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n:
            n &= n - 1
            count += 1
        return count

if __name__ == "__main__":
    s = Solution()
    assert s.hammingWeight(11) == 3
    assert s.hammingWeight(128) == 1
    assert s.hammingWeight(0) == 0
    print("All tests passed!")
