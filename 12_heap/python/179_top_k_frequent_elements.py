# LC#347 — Top K Frequent Elements
# Difficulty: Medium | Pattern: Heap
# Time: O(n log k) | Space: O(n)

import heapq
from collections import Counter


class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        freq = Counter(nums)
        # heapq.nlargest returns k elements with largest frequency
        return heapq.nlargest(k, freq.keys(), key=lambda x: freq[x])


if __name__ == "__main__":
    s = Solution()
    assert sorted(s.topKFrequent([1,1,1,2,2,3], 2)) == [1, 2]
    assert s.topKFrequent([1], 1) == [1]
    print("All tests passed!")
