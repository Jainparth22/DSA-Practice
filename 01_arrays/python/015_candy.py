# LC#135 — Candy
# Difficulty: Hard | Pattern: Greedy (two pass) | Time: O(n) | Space: O(n)
def candy(r):
    n = len(r); c = [1] * n
    for i in range(1, n):
        if r[i] > r[i-1]: c[i] = c[i-1] + 1
    for i in range(n - 2, -1, -1):
        if r[i] > r[i+1]: c[i] = max(c[i], c[i+1] + 1)
    return sum(c)

assert candy([1,0,2]) == 5 and candy([1,2,2]) == 4
