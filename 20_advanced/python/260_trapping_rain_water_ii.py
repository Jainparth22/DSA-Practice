# LC#407 — Trapping Rain Water II
# Difficulty: Hard | Pattern: Min Heap BFS from border | Time: O(mn log mn) | Space: O(mn)
import heapq

def trap_rain_water(h):
    R, C = len(h), len(h[0])
    if R < 3 or C < 3: return 0
    pq = []; seen = [[False] * C for _ in range(R)]; res = 0
    for i in range(R):
        for j in range(C):
            if i in (0, R - 1) or j in (0, C - 1): heapq.heappush(pq, (h[i][j], i, j)); seen[i][j] = True
    while pq:
        ht, i, j = heapq.heappop(pq)
        for a, b in ((i+1, j), (i-1, j), (i, j+1), (i, j-1)):
            if 0 <= a < R and 0 <= b < C and not seen[a][b]:
                seen[a][b] = True; res += max(0, ht - h[a][b]); heapq.heappush(pq, (max(ht, h[a][b]), a, b))
    return res

assert trap_rain_water([[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]) == 4
