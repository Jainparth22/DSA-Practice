# LC#1326 — Minimum Number of Taps to Open to Water a Garden
# Difficulty: Hard | Pattern: Greedy (jump game) | Time: O(n) | Space: O(n)
def min_taps(n, ranges):
    far = [0] * (n + 1)
    for i, r in enumerate(ranges):
        l = max(0, i - r); far[l] = max(far[l], min(n, i + r))
    taps = end = reach = 0
    for i in range(n + 1):
        if i > reach: return -1
        if i > end: taps += 1; end = reach
        reach = max(reach, far[i])
    return taps if end >= n else (taps + 1 if reach >= n else -1)

assert min_taps(5, [3,4,1,1,0,0]) == 1 and min_taps(3, [0,0,0,0]) == -1 and min_taps(7, [1,2,1,0,2,1,0,1]) == 3
