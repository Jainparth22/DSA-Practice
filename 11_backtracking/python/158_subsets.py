# LC #78 — Subsets
# Difficulty : Medium
# Pattern    : Backtracking
# Time       : O(2^n × n)   Space: O(n)

"""
Every call to backtrack records the current state as a valid subset.
Iterate from 'start' to avoid re-using elements.
"""

from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result: List[List[int]] = []

        def bt(start: int, current: List[int]) -> None:
            result.append(current[:])   # snapshot
            for i in range(start, len(nums)):
                current.append(nums[i])
                bt(i + 1, current)
                current.pop()

        bt(0, [])
        return result


if __name__ == "__main__":
    sol = Solution()

    res1 = sol.subsets([1, 2, 3])
    assert len(res1) == 8   # 2^3
    assert [] in res1
    assert [1, 2, 3] in res1
    assert sorted(sorted(s) for s in res1) == sorted(sorted(s) for s in [
        [], [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]
    ])

    res2 = sol.subsets([0])
    assert sorted(res2) == [[], [0]]

    print("All tests passed!")
