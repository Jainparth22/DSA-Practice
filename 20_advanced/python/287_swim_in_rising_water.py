# LC#778 — Swim in Rising Water
# Difficulty: Hard | Pattern: Dijkstra on max-cell | Time: O(n^2 log n) | Space: O(n^2)
import heapq

def swim_in_water(g):
    n = len(g); seen = {(0, 0)}; pq = [(g[0][0], 0, 0)]
    while pq:
        t, i, j = heapq.heappop(pq)
        if i == n - 1 and j == n - 1: return t
        for x, y in ((i+1, j), (i-1, j), (i, j+1), (i, j-1)):
            if 0 <= x < n and 0 <= y < n and (x, y) not in seen:
                seen.add((x, y)); heapq.heappush(pq, (max(t, g[x][y]), x, y))

assert swim_in_water([[0,2],[1,3]]) == 3
