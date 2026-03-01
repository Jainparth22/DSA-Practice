# LC#57 — Insert Interval
# Difficulty: Medium
# Pattern: Linear Scan + Merge
# Time: O(n) | Space: O(n)
#
# Approach:
#   Three-phase linear scan:
#   1. Collect all intervals ending before new_interval starts.
#   2. Merge all overlapping intervals into new_interval.
#   3. Collect remaining intervals.

class Solution:
    def insert(self, intervals: list[list[int]], new_interval: list[int]) -> list[list[int]]:
        result = []
        i = 0
        n = len(intervals)

        # Phase 1: no overlap on the left
        while i < n and intervals[i][1] < new_interval[0]:
            result.append(intervals[i])
            i += 1

        # Phase 2: merge overlapping
        while i < n and intervals[i][0] <= new_interval[1]:
            new_interval[0] = min(new_interval[0], intervals[i][0])
            new_interval[1] = max(new_interval[1], intervals[i][1])
            i += 1
        result.append(new_interval)

        # Phase 3: no overlap on the right
        while i < n:
            result.append(intervals[i])
            i += 1

        return result


if __name__ == "__main__":
    s = Solution()
    assert s.insert([[1, 3], [6, 9]], [2, 5]) == [[1, 5], [6, 9]]
    assert s.insert([[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]], [4, 8]) == [[1, 2], [3, 10], [12, 16]]
    assert s.insert([], [5, 7]) == [[5, 7]]
    assert s.insert([[1, 5]], [2, 3]) == [[1, 5]]
    print("All tests passed!")
