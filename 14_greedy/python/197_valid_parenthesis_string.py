# LC#678 — Valid Parenthesis String
# Difficulty: Medium | Pattern: Greedy range of open count | Time: O(n) | Space: O(1)
def check_valid_string(s):
    lo = hi = 0
    for c in s:
        lo += 1 if c == "(" else -1
        hi += -1 if c == ")" else 1
        if hi < 0: return False
        lo = max(lo, 0)
    return lo == 0

assert check_valid_string("(*))") and not check_valid_string("(((**")
