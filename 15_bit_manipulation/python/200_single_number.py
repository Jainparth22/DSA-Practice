# LC #136 — Single Number
# Difficulty : Easy
# Pattern    : Bit Manipulation — XOR
# Time       : O(n)   Space: O(1)

"""
XOR properties:
  a ^ a = 0 (self-cancel)
  a ^ 0 = a (identity)
XOR all numbers: duplicates cancel, single remains.
"""

from typing import List
from functools import reduce
import operator


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        result = 0
        for n in nums:
            result ^= n
        return result

    # One-liner with reduce
    def singleNumber_v2(self, nums: List[int]) -> int:
        return reduce(operator.xor, nums)


if __name__ == "__main__":
    sol = Solution()
    for fn in [sol.singleNumber, sol.singleNumber_v2]:
        assert fn([2, 2, 1])        == 1
        assert fn([4, 1, 2, 1, 2])  == 4
        assert fn([1])              == 1
        assert fn([0, 1, 0])        == 1
    print("All tests passed!")
