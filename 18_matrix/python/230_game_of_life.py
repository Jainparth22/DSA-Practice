# LC#289 — Game of Life
# Difficulty: Medium | Pattern: In-place state encoding | Time: O(mn) | Space: O(1)
def game_of_life(b):
    R, C = len(b), len(b[0])
    for i in range(R):
        for j in range(C):
            n = sum(b[x][y] & 1 for x in range(max(0, i-1), min(R, i+2)) for y in range(max(0, j-1), min(C, j+2)) if (x, y) != (i, j))
            if (b[i][j] and n in (2, 3)) or (not b[i][j] and n == 3): b[i][j] |= 2
    for i in range(R):
        for j in range(C): b[i][j] >>= 1

b = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]; game_of_life(b); assert b == [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
