# LC#39 — Combination Sum
# Difficulty: Medium
# Pattern: Backtracking with Reuse Allowed
# Time: O(2^(target/min)) | Space: O(target/min)
#
# Approach:
#   Sort candidates. DFS: for each candidate from index i onward (reuse allowed),
#   subtract from target. If target hits 0, record combination.
#   Prune if candidate exceeds remaining target.

class Solution:
    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        candidates.sort()
        result = []

        def dfs(start: int, current: list[int], remaining: int):
            if remaining == 0:
                result.append(list(current))
                return
            for i in range(start, len(candidates)):
                if candidates[i] > remaining:
                    break
                current.append(candidates[i])
                dfs(i, current, remaining - candidates[i])
                current.pop()

        dfs(0, [], target)
        return result


if __name__ == "__main__":
    s = Solution()
    r1 = s.combinationSum([2, 3, 6, 7], 7)
    assert sorted(map(sorted, r1)) == sorted(map(sorted, [[2, 2, 3], [7]]))

    r2 = s.combinationSum([2, 3, 5], 8)
    assert sorted(map(sorted, r2)) == sorted(map(sorted, [[2, 2, 2, 2], [2, 3, 3], [3, 5]]))

    assert s.combinationSum([2], 1) == []

    print("All tests passed!")
