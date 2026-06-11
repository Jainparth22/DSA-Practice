# LC#978 — Longest Turbulent Subarray
# Difficulty: Medium | Pattern: DP on comparisons | Time: O(n) | Space: O(1)
def max_turbulence_size(a):
    up = down = best = 1
    for i in range(1, len(a)):
        if a[i] > a[i-1]: up, down = down + 1, 1
        elif a[i] < a[i-1]: up, down = 1, up + 1
        else: up = down = 1
        best = max(best, up, down)
    return best

assert max_turbulence_size([9,4,2,10,7,8,8,1,9]) == 5
