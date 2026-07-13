# LC#1931 — Painting a Grid With Three Different Colors
# Difficulty: Hard | Pattern: Column-pattern DP | Time: O(n * P^2) | Space: O(P^2)
def color_the_grid(m, n):
    M = 10**9 + 7; cols = []
    def gen(cur):
        if len(cur) == m: cols.append(tuple(cur)); return
        for c in range(3):
            if not cur or cur[-1] != c: gen(cur + [c])
    gen([])
    ok = [[j for j, b in enumerate(cols) if all(x != y for x, y in zip(a, b))] for a in cols]
    dp = [1] * len(cols)
    for _ in range(n - 1): dp = [sum(dp[j] for j in ok[i]) % M for i in range(len(cols))]
    return sum(dp) % M

assert color_the_grid(1, 1) == 3 and color_the_grid(1, 2) == 6 and color_the_grid(5, 5) == 580986
