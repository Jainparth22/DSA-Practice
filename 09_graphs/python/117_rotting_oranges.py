# LC#994 — Rotting Oranges
# Difficulty: Medium
# Pattern: Multi-source BFS
# Time: O(m*n) | Space: O(m*n)
#
# Approach:
#   Start BFS from ALL rotten oranges simultaneously.
#   Each BFS level = 1 minute. Infect neighbouring fresh oranges.
#   Return minutes elapsed, or -1 if any fresh orange remains.

from collections import deque


class Solution:
    def orangesRotting(self, grid: list[list[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        queue = deque()
        fresh = 0
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 2:
                    queue.append((r, c))
                elif grid[r][c] == 1:
                    fresh += 1
        minutes = 0
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        while queue and fresh > 0:
            for _ in range(len(queue)):
                r, c = queue.popleft()
                for dr, dc in dirs:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] == 1:
                        grid[nr][nc] = 2
                        fresh -= 1
                        queue.append((nr, nc))
            minutes += 1
        return minutes if fresh == 0 else -1


if __name__ == "__main__":
    s = Solution()
    assert s.orangesRotting([[2, 1, 1], [1, 1, 0], [0, 1, 1]]) == 4
    assert s.orangesRotting([[2, 1, 1], [0, 1, 1], [1, 0, 1]]) == -1
    assert s.orangesRotting([[0, 2]]) == 0
    print("All tests passed!")
