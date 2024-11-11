# LC#42 — Trapping Rain Water
# Difficulty: Hard | Pattern: Two Pointers | Time: O(n) | Space: O(1)
def trap(h):
    l, r, lm, rm, res = 0, len(h) - 1, 0, 0, 0
    while l < r:
        if h[l] < h[r]:
            lm = max(lm, h[l]); res += lm - h[l]; l += 1
        else:
            rm = max(rm, h[r]); res += rm - h[r]; r -= 1
    return res

assert trap([0,1,0,2,1,0,1,3,2,1,2,1]) == 6
