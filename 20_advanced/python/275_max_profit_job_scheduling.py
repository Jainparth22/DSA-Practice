# LC#1235 — Maximum Profit in Job Scheduling
# Difficulty: Hard | Pattern: Sort + DP + Binary Search | Time: O(n log n) | Space: O(n)
import bisect

def job_scheduling(start, end, profit):
    jobs = sorted(zip(end, start, profit)); ends = []; best = [0]
    for e, s, p in jobs:
        k = bisect.bisect_right(ends, s)
        ends.append(e); best.append(max(best[-1], best[k] + p))
    return best[-1]

assert job_scheduling([1,2,3,3], [3,4,5,6], [50,10,40,70]) == 120
