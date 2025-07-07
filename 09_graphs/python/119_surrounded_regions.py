# LC#130 — Surrounded Regions
# Difficulty: Medium | Pattern: Border DFS | Time: O(mn) | Space: O(mn)
def solve(b):
    R, C = len(b), len(b[0])
    def mark(i, j):
        if i < 0 or j < 0 or i >= R or j >= C or b[i][j] != "O": return
        b[i][j] = "T"; mark(i+1, j); mark(i-1, j); mark(i, j+1); mark(i, j-1)
    for i in range(R): mark(i, 0); mark(i, C - 1)
    for j in range(C): mark(0, j); mark(R - 1, j)
    for i in range(R):
        for j in range(C): b[i][j] = "O" if b[i][j] == "T" else "X"

b = [list("XXXX"), list("XOOX"), list("XXOX"), list("XOXX")]; solve(b)
assert ["".join(r) for r in b] == ["XXXX", "XXXX", "XXXX", "XOXX"]
