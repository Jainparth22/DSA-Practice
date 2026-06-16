# LC#1293 — Shortest Path in a Grid with Obstacles Elimination
# Difficulty: Hard | Pattern: BFS with state (r, c, k) | Time: O(mnk) | Space: O(mnk)
from collections import deque

def shortest_path(g, k):
    R, C = len(g), len(g[0])
    if k >= R + C - 2: return R + C - 2
    q = deque([(0, 0, k, 0)]); seen = {(0, 0, k)}
    while q:
        i, j, r, st = q.popleft()
        if (i, j) == (R - 1, C - 1): return st
        for a, b in ((i+1, j), (i-1, j), (i, j+1), (i, j-1)):
            if 0 <= a < R and 0 <= b < C:
                nr = r - g[a][b]
                if nr >= 0 and (a, b, nr) not in seen: seen.add((a, b, nr)); q.append((a, b, nr, st + 1))
    return -1

assert shortest_path([[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], 1) == 6 and shortest_path([[0,1,1],[1,1,1],[1,0,0]], 1) == -1
