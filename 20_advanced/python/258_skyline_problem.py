# LC#218 — The Skyline Problem
# Difficulty: Hard | Pattern: Sweep line + Max Heap | Time: O(n log n) | Space: O(n)
import heapq

def get_skyline(buildings):
    ev = sorted([(l, -h, r) for l, r, h in buildings] + [(r, 0, 0) for _, r, _ in buildings])
    res = []; heap = [(0, float("inf"))]
    for x, negh, r in ev:
        while heap[0][1] <= x: heapq.heappop(heap)
        if negh: heapq.heappush(heap, (negh, r))
        h = -heap[0][0]
        if not res or res[-1][1] != h: res.append([x, h])
    return res

assert get_skyline([[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]) == [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
