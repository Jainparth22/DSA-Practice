# LC#37 — Sudoku Solver
# Difficulty: Hard | Pattern: Backtracking | Time: O(9^m) | Space: O(1)
def solve_sudoku(b):
    def ok(r, c, v):
        return all(b[r][i] != v and b[i][c] != v and b[3*(r//3) + i//3][3*(c//3) + i%3] != v for i in range(9))
    for r in range(9):
        for c in range(9):
            if b[r][c] == ".":
                for v in "123456789":
                    if ok(r, c, v):
                        b[r][c] = v
                        if solve_sudoku(b): return True
                        b[r][c] = "."
                return False
    return True

rows = ["53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"]
b = [list(r) for r in rows]; solve_sudoku(b); assert "".join(b[0]) == "534678912"
