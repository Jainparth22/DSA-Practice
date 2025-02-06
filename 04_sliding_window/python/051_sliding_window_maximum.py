# LC#239 — Sliding Window Maximum
# Difficulty: Hard | Pattern: Monotonic Deque | Time: O(n) | Space: O(k)
from collections import deque

def max_sliding_window(a, k):
    dq, res = deque(), []
    for i, x in enumerate(a):
        while dq and dq[0] <= i - k: dq.popleft()
        while dq and a[dq[-1]] < x: dq.pop()
        dq.append(i)
        if i >= k - 1: res.append(a[dq[0]])
    return res

assert max_sliding_window([1,3,-1,-3,5,3,6,7], 3) == [3,3,5,5,6,7]
