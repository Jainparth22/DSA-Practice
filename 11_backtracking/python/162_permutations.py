# LC#46 — Permutations
# Difficulty: Medium
# Pattern: Backtracking
# Time: O(n! * n) | Space: O(n)
#
# Approach:
#   Track used indices. Build current permutation step by step.
#   When length equals n, record. Backtrack by removing last element.

class Solution:
    def permute(self, nums: list[int]) -> list[list[int]]:
        result = []
        used = [False] * len(nums)

        def dfs(current: list[int]):
            if len(current) == len(nums):
                result.append(list(current))
                return
            for i in range(len(nums)):
                if used[i]:
                    continue
                used[i] = True
                current.append(nums[i])
                dfs(current)
                current.pop()
                used[i] = False

        dfs([])
        return result


if __name__ == "__main__":
    s = Solution()
    r1 = s.permute([1, 2, 3])
    assert len(r1) == 6
    assert sorted(r1) == sorted([[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]])

    r2 = s.permute([0, 1])
    assert len(r2) == 2

    r3 = s.permute([1])
    assert r3 == [[1]]

    print("All tests passed!")
