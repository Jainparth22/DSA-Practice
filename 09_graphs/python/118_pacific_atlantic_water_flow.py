# LC#417 — Pacific Atlantic Water Flow
# Difficulty: Medium
# Pattern: Reverse BFS from both ocean borders
# Time: O(m*n) | Space: O(m*n)
#
# Approach:
#   BFS uphill from Pacific borders (top+left) and Atlantic borders (bottom+right).
#   A cell can reach an ocean if water can flow from it to the ocean border.
#   Result = cells reachable from BOTH oceans simultaneously.

from collections import deque


class Solution:
    def pacificAtlantic(self, heights: list[list[int]]) -> list[list[int]]:
        rows, cols = len(heights), len(heights[0])

        def bfs(starts):
            visited = set(starts)
            queue = deque(starts)
            while queue:
                r, c = queue.popleft()
                for dr, dc in [(1,0),(-1,0),(0,1),(0,-1)]:
                    nr, nc = r + dr, c + dc
                    if (0 <= nr < rows and 0 <= nc < cols
                            and (nr, nc) not in visited
                            and heights[nr][nc] >= heights[r][c]):
                        visited.add((nr, nc))
                        queue.append((nr, nc))
            return visited

        pacific_starts = [(0, c) for c in range(cols)] + [(r, 0) for r in range(rows)]
        atlantic_starts = [(rows-1, c) for c in range(cols)] + [(r, cols-1) for r in range(rows)]

        pac = bfs(pacific_starts)
        atl = bfs(atlantic_starts)
        return [[r, c] for r, c in pac & atl]


if __name__ == "__main__":
    s = Solution()
    h1 = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
    result = s.pacificAtlantic(h1)
    assert len(result) == 7
    print("All tests passed!")
