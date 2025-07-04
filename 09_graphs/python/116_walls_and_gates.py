# LC#286 — Walls and Gates
# Difficulty: Medium | Pattern: Multi-source BFS | Time: O(mn) | Space: O(mn)
from collections import deque

def walls_and_gates(g):
    R, C = len(g), len(g[0]); INF = 2**31 - 1
    q = deque((i, j) for i in range(R) for j in range(C) if g[i][j] == 0)
    while q:
        i, j = q.popleft()
        for x, y in ((i+1, j), (i-1, j), (i, j+1), (i, j-1)):
            if 0 <= x < R and 0 <= y < C and g[x][y] == INF:
                g[x][y] = g[i][j] + 1; q.append((x, y))

I = 2**31 - 1; g = [[I,-1,0,I],[I,I,I,-1],[I,-1,I,-1],[0,-1,I,I]]; walls_and_gates(g); assert g[0][0] == 3
