# LC#327 — Count of Range Sum
# Difficulty: Hard | Pattern: Merge Sort on prefix sums | Time: O(n log n) | Space: O(n)
def count_range_sum(nums, lo, up):
    p = [0]
    for x in nums: p.append(p[-1] + x)
    def go(arr):
        if len(arr) <= 1: return arr, 0
        m = len(arr) // 2; l, cl = go(arr[:m]); r, cr = go(arr[m:]); cnt = cl + cr; a = b = 0
        for x in l:
            while a < len(r) and r[a] - x < lo: a += 1
            while b < len(r) and r[b] - x <= up: b += 1
            cnt += b - a
        return sorted(l + r), cnt
    return go(p)[1]

assert count_range_sum([-2,5,-1], -2, 2) == 3 and count_range_sum([0], 0, 0) == 1
