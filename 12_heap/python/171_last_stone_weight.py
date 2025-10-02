# LC#1046 — Last Stone Weight
# Difficulty: Easy | Pattern: Max Heap | Time: O(n log n) | Space: O(n)
import heapq

def last_stone_weight(stones):
    h = [-s for s in stones]; heapq.heapify(h)
    while len(h) > 1:
        a, b = heapq.heappop(h), heapq.heappop(h)
        if a != b: heapq.heappush(h, a - b)
    return -h[0] if h else 0

assert last_stone_weight([2,7,4,1,8,1]) == 1
