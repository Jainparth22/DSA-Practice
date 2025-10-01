# LC#703 — Kth Largest Element in a Stream
# Difficulty: Easy | Pattern: Min Heap of size k | Time: O(log k) per add | Space: O(k)
import heapq

class KthLargest:
    def __init__(self, k, nums):
        self.k = k; self.h = []
        for x in nums: self.add(x)
    def add(self, v):
        heapq.heappush(self.h, v)
        if len(self.h) > self.k: heapq.heappop(self.h)
        return self.h[0]

kl = KthLargest(3, [4,5,8,2]); assert [kl.add(3), kl.add(5), kl.add(10)] == [4, 5, 5]
