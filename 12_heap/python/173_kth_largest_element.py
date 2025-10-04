# LC #215 — Kth Largest Element in an Array
# Difficulty : Medium
# Pattern    : Min-Heap (size K) or QuickSelect
# Time       : O(n log k) heap, O(n) avg QuickSelect

"""
Min-heap of K: top = K-th largest.
QuickSelect: partial sort, pivot in final position, recurse one side only.
"""

from typing import List
import heapq
import random


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        """Min-heap approach O(n log k)."""
        heap: List[int] = []
        for n in nums:
            heapq.heappush(heap, n)
            if len(heap) > k:
                heapq.heappop(heap)
        return heap[0]

    def findKthLargest_qs(self, nums: List[int], k: int) -> int:
        """QuickSelect O(n) average."""
        target = len(nums) - k  # k-th largest = (n-k)-th smallest

        def quickselect(lo: int, hi: int) -> int:
            # Random pivot to avoid O(n²) worst case
            pivot_idx = random.randint(lo, hi)
            nums[pivot_idx], nums[hi] = nums[hi], nums[pivot_idx]
            pivot = nums[hi]
            i = lo
            for j in range(lo, hi):
                if nums[j] <= pivot:
                    nums[i], nums[j] = nums[j], nums[i]
                    i += 1
            nums[i], nums[hi] = nums[hi], nums[i]
            if i == target:   return nums[i]
            elif i < target:  return quickselect(i + 1, hi)
            else:             return quickselect(lo, i - 1)

        return quickselect(0, len(nums) - 1)


if __name__ == "__main__":
    sol = Solution()
    for fn in [sol.findKthLargest, sol.findKthLargest_qs]:
        assert fn([3, 2, 1, 5, 6, 4], 2) == 5
        assert fn([3, 2, 3, 1, 2, 4, 5, 5, 6], 4) == 4
        assert fn([1], 1) == 1
        assert fn([2, 1], 1) == 2
    print("All tests passed!")
