# LC#22 — Generate Parentheses
# Difficulty: Medium | Pattern: Backtracking | Time: O(4^n/sqrt(n)) | Space: O(n)
def generate_parenthesis(n):
    out = []
    def go(cur, o, c):
        if len(cur) == 2 * n: out.append(cur); return
        if o < n: go(cur + "(", o + 1, c)
        if c < o: go(cur + ")", o, c + 1)
    go("", 0, 0)
    return out

assert len(generate_parenthesis(3)) == 5
