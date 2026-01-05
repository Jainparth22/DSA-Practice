# LC#268 — Missing Number
# Difficulty: Easy | Pattern: XOR
# Time: O(n) | Space: O(1)

class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        missing = len(nums)
        for i, num in enumerate(nums):
            missing ^= i ^ num
        return missing

if __name__ == "__main__":
    s = Solution()
    assert s.missingNumber([3,0,1]) == 2
    assert s.missingNumber([0,1]) == 2
    assert s.missingNumber([9,6,4,2,3,5,7,0,1]) == 8
    print("All tests passed!")
