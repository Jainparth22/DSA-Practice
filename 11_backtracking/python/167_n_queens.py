# LC#51 — N-Queens
# Difficulty: Hard | Pattern: Backtracking + column/diagonal sets | Time: O(n!) | Space: O(n)
def solve_n_queens(n):
    res = []; cols, d1, d2, pos = set(), set(), set(), []
    def go(r):
        if r == n: res.append(["." * c + "Q" + "." * (n - c - 1) for c in pos]); return
        for c in range(n):
            if c in cols or r - c in d1 or r + c in d2: continue
            cols.add(c); d1.add(r - c); d2.add(r + c); pos.append(c)
            go(r + 1)
            cols.remove(c); d1.remove(r - c); d2.remove(r + c); pos.pop()
    go(0)
    return res

assert len(solve_n_queens(4)) == 2 and len(solve_n_queens(8)) == 92
