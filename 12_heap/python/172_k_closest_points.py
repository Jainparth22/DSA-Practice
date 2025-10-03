# LC#973 — K Closest Points to Origin
# Difficulty: Medium | Pattern: Max Heap of size k | Time: O(n log k) | Space: O(k)
import heapq

def k_closest(points, k):
    return heapq.nsmallest(k, points, key=lambda p: p[0] ** 2 + p[1] ** 2)

assert k_closest([[1,3],[-2,2]], 1) == [[-2, 2]]
