# LC#981 — Time Based Key-Value Store
# Difficulty: Medium | Pattern: Binary Search on timestamps | Time: O(log n) get | Space: O(n)
import bisect

class TimeMap:
    def __init__(self): self.m = {}
    def set(self, k, v, t): self.m.setdefault(k, []).append((t, v))
    def get(self, k, t):
        arr = self.m.get(k, [])
        i = bisect.bisect_right(arr, (t, chr(0x10ffff)))
        return arr[i - 1][1] if i else ""

tm = TimeMap(); tm.set("foo", "bar", 1); tm.set("foo", "bar2", 4)
assert tm.get("foo", 1) == "bar" and tm.get("foo", 3) == "bar" and tm.get("foo", 4) == "bar2" and tm.get("foo", 0) == ""
