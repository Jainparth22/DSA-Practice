# LC#73 — Set Matrix Zeroes
# Difficulty: Medium | Pattern: In-place markers | Time: O(mn) | Space: O(1)
def set_zeroes(m):
    R, C = len(m), len(m[0])
    r0 = any(m[0][j] == 0 for j in range(C)); c0 = any(m[i][0] == 0 for i in range(R))
    for i in range(1, R):
        for j in range(1, C):
            if m[i][j] == 0: m[i][0] = m[0][j] = 0
    for i in range(1, R):
        for j in range(1, C):
            if m[i][0] == 0 or m[0][j] == 0: m[i][j] = 0
    if r0: m[0] = [0] * C
    if c0:
        for i in range(R): m[i][0] = 0

m = [[1,1,1],[1,0,1],[1,1,1]]; set_zeroes(m); assert m == [[1,0,1],[0,0,0],[1,0,1]]
