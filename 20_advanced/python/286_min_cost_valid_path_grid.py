# LC#1368 — Minimum Cost to Make at Least One Valid Path in a Grid
# Difficulty: Hard | Pattern: 0-1 BFS | Time: O(mn) | Space: O(mn)
from collections import deque

def min_cost(g):
    R, C = len(g), len(g[0]); d = [[float("inf")] * C for _ in range(R)]; d[0][0] = 0; q = deque([(0, 0)])
    dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    while q:
        i, j = q.popleft()
        for k, (dx, dy) in enumerate(dirs):
            a, b = i + dx, j + dy
            if 0 <= a < R and 0 <= b < C:
                w = int(g[i][j] != k + 1)
                if d[i][j] + w < d[a][b]:
                    d[a][b] = d[i][j] + w
                    q.append((a, b)) if w else q.appendleft((a, b))
    return d[R-1][C-1]

assert min_cost([[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]) == 3 and min_cost([[1,2],[4,3]]) == 1
