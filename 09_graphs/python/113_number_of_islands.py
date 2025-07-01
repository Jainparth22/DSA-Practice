# LC #200 — Number of Islands
# Difficulty : Medium
# Pattern    : Graph — DFS Flood Fill
# Time       : O(m×n)   Space: O(m×n)

"""
For each unvisited '1', increment island count, then DFS to sink all
connected land (mark '0') so we don't count it again.
"""

from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        m, n = len(grid), len(grid[0])

        def dfs(r: int, c: int) -> None:
            if r < 0 or r >= m or c < 0 or c >= n or grid[r][c] != '1':
                return
            grid[r][c] = '0'   # sink — mark visited
            dfs(r + 1, c); dfs(r - 1, c)
            dfs(r, c + 1); dfs(r, c - 1)

        count = 0
        for r in range(m):
            for c in range(n):
                if grid[r][c] == '1':
                    count += 1
                    dfs(r, c)
        return count


if __name__ == "__main__":
    sol = Solution()

    g1 = [["1","1","1","1","0"],
          ["1","1","0","1","0"],
          ["1","1","0","0","0"],
          ["0","0","0","0","0"]]
    assert sol.numIslands(g1) == 1

    g2 = [["1","1","0","0","0"],
          ["1","1","0","0","0"],
          ["0","0","1","0","0"],
          ["0","0","0","1","1"]]
    assert sol.numIslands(g2) == 3

    g3 = [["1"]]
    assert sol.numIslands(g3) == 1

    g4 = [["0"]]
    assert sol.numIslands(g4) == 0

    print("All tests passed!")
