# LC#621 — Task Scheduler
# Difficulty: Medium | Pattern: Greedy + Max Heap
# Time: O(n) | Space: O(1)
# Approach: Use max-heap. Each cycle = n+1 slots. Fill with most frequent
# available tasks; pad with idle if not enough. Sum up all slots.

import heapq
from collections import Counter


class Solution:
    def leastInterval(self, tasks: list[str], n: int) -> int:
        freq = Counter(tasks)
        max_heap = [-cnt for cnt in freq.values()]
        heapq.heapify(max_heap)
        time = 0
        while max_heap:
            cycle = n + 1
            temp = []
            while cycle > 0 and max_heap:
                cnt = heapq.heappop(max_heap)
                temp.append(cnt + 1)   # reduce count by 1 (stored negative)
                cycle -= 1
                time += 1
            for t in temp:
                if t < 0:              # still has remaining count
                    heapq.heappush(max_heap, t)
            if max_heap:
                time += cycle          # idle slots
        return time


if __name__ == "__main__":
    s = Solution()
    assert s.leastInterval(['A','A','A','B','B','B'], 2) == 8
    assert s.leastInterval(['A','A','A','B','B','B'], 0) == 6
    assert s.leastInterval(['A','A','A','A','A','A','B','C','D','E','F','G'], 2) == 16
    print("All tests passed!")
