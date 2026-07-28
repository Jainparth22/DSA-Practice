# LC#44 — Wildcard Matching
# Difficulty: Hard | Pattern: Greedy two pointers | Time: O(mn) | Space: O(1)
def is_match(s, p):
    i = j = 0; star, mark = -1, 0
    while i < len(s):
        if j < len(p) and p[j] in ("?", s[i]): i += 1; j += 1
        elif j < len(p) and p[j] == "*": star = j; j += 1; mark = i
        elif star >= 0: j = star + 1; mark += 1; i = mark
        else: return False
    while j < len(p) and p[j] == "*": j += 1
    return j == len(p)

assert is_match("adceb", "*a*b") and not is_match("acdcb", "a*c?b")
