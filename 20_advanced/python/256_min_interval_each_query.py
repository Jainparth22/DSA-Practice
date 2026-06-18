# LC#1851 — Minimum Interval to Include Each Query
# Difficulty: Hard | Pattern: Sort + Min Heap | Time: O((n+q) log n) | Space: O(n+q)
import heapq

def min_interval(intervals, queries):
    intervals.sort(); h = []; res = {}; i = 0
    for q in sorted(queries):
        while i < len(intervals) and intervals[i][0] <= q:
            heapq.heappush(h, (intervals[i][1] - intervals[i][0] + 1, intervals[i][1])); i += 1
        while h and h[0][1] < q: heapq.heappop(h)
        res[q] = h[0][0] if h else -1
    return [res[q] for q in queries]

assert min_interval([[1,4],[2,4],[3,6],[4,4]], [2,3,4,5]) == [3,3,1,4]
