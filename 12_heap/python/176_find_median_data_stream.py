# LC#295 — Find Median from Data Stream
# Difficulty: Hard | Pattern: Two Heaps
# Time: O(log n) addNum, O(1) findMedian | Space: O(n)
# Approach:
#   lo = max-heap (lower half, stored as negatives for Python's min-heap).
#   hi = min-heap (upper half).
#   Keep lo.size() >= hi.size(), and lo.size() - hi.size() <= 1.

import heapq


class MedianFinder:
    def __init__(self):
        self.lo = []   # max-heap (negate values)
        self.hi = []   # min-heap

    def addNum(self, num: int) -> None:
        heapq.heappush(self.lo, -num)
        # Move max of lo to hi to maintain order
        heapq.heappush(self.hi, -heapq.heappop(self.lo))
        # Rebalance: lo must be >= hi in size
        if len(self.hi) > len(self.lo):
            heapq.heappush(self.lo, -heapq.heappop(self.hi))

    def findMedian(self) -> float:
        if len(self.lo) > len(self.hi):
            return -self.lo[0]
        return (-self.lo[0] + self.hi[0]) / 2.0


if __name__ == "__main__":
    mf = MedianFinder()
    mf.addNum(1)
    mf.addNum(2)
    assert mf.findMedian() == 1.5
    mf.addNum(3)
    assert mf.findMedian() == 2.0
    mf.addNum(4)
    assert mf.findMedian() == 2.5
    print("All tests passed!")
